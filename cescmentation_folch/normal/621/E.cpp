#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vll R;
ll mod = 1e9+7;
vvvll inv;

ll deu(int k, int m) {
  if (k == 0) return 1;
  if (k == 1) return 10%m;
  ll d = deu(k/2, m);
  d = (d*d)%m;
  if (k%2) d = (d*10)%m;
  return d%m;
}

vll res(int x, int m) {
  if (x == 0) return vll(R.size(), 1);
  if (x == 1) return R;
  
  vll K = res(x/2, m);
  ll d = deu(x/2, m)%m;
  
  vll rr(R.size(), 0);
  
  for (int i = 0; i < R.size(); ++i) {
    for (int j = 0; j < R.size(); ++j) {
      int t = (i - j + m)%m;
      for(int w = 0; w < inv[d][t].size(); ++w) rr[i] = (rr[i] + K[j]*K[inv[d][t][w]])%mod;
    }
  }
  
  if (x%2 == 1) {
    vll rt(R.size(), 0);
    d = (d*d)%m;
    for (int i = 0; i < R.size(); ++i) {
      for (int j = 0; j < R.size(); ++j) {
	int t = (i - j + m)%m;
	for(int w = 0; w < inv[d][t].size(); ++w) rt[i] = (rt[i] + rr[j]*R[inv[d][t][w]])%mod;
      }
    }
    return rt;
  }
  else return rr;
}

int main() {
  int n, b, k, x;
  cin >> n >> b >> k >> x;
  
  inv = vvvll(x, vvll(x));
  
  for (int i = 0; i < x; ++i) {
    for (int j = 0; j < x; ++j) {
      for (int w = 0; w < x; ++w) {
	if ((i*j)%x == w) inv[i][w].push_back(j);
      }
    }
  }
  
  
  R = vll(x, 0);
  for (int i = 0; i < n; ++i) {
    int l;
    cin >> l;
    R[l%x]++;
  }
  
  vll bb = res(b, x);
  cout << bb[k] << endl;
}