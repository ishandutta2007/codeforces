#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define rep(a,b,c) for(int a=b; a<c; ++a)
typedef vector<int> vi;
#define sz(a) a.size()

// KACTL
array<vi, 2> manacher(const string& s) {
	int n = sz(s);
	array<vi,2> p = {vi(n+1), vi(n)};
	rep(z,0,2) for (int i=0,l=0,r=0; i < n; i++) {
		int t = r-i+!z;
		if (i<r) p[z][i] = min(t, p[z][l+t]);
		int L = i-p[z][i], R = i+p[z][i]-!z;
		while (L>=1 && R+1<n && s[L-1] == s[R+1])
			p[z][i]++, L--, R++;
		if (R>r) l=L, r=R;
	}
	return p; }

/*
struct Segtree {
  vector<int> t;
  int n, h;
  Segtree(int sz) {
    h = 32 - __builtin_clz(sz);
    n = 1<<h;
    t = vector<int>(n*2);
  }
  int 
};
*/


pair<int, string> check(const string& s) {
  int n = s.size();
  auto man = manacher(s);
  //Segtree st(n+2), strev(n+2);
  int sim = 0;
  for (int i=0; i<=n; ++i) {
    sim = i;
    if (i == n || s[i] != s[n-i-1]) {
      break;
    }
  }
  //cerr << "SIM " << sim << endl;
  pair<int, int> best = {0,0}; // total, begin length
  for (int i=0; i<=n; ++i) {
    int ctr = i*2;
    int be = i-man[0][i];
    if (sim >= be && ctr <= n) {
      pair<int, int> t = {ctr, min(sim, ctr/2)};
      best = max(best, t);
    }
  }
  for (int i=0; i<n; ++i) {
    int ctr = i*2+1;
    int be = i - man[1][i];
    //cerr << " ODD BE " << be << endl;
    if (sim >= be && ctr <= n) {
      pair<int, int> t = {ctr, min(sim, ctr/2)};
      best = max(best, t);
    }
  }

  string q;
  for (int i=0; i<best.second; ++i) {
    q += s[i];
  }
  for (int i=best.second; i<best.first-best.second; ++i) {
    q += s[i];
  }
  for (int i=0; i<best.second; ++i) {
    q += s[n-best.second+i];
  }

  return pair<int, string>(best.first, q);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    string s;
    cin >> s;
    pair<int, string> best = check(s);
    reverse(s.begin(), s.end());
    pair<int, string> b2 = check(s);
    if (b2.first > best.first) {
      reverse(b2.second.begin(), b2.second.end());
      swap(best, b2);
    }
    cout << best.second << endl;
  }
  return 0;
}