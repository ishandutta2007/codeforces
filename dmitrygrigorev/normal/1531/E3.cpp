#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

string s;
int u;

bool flag;

vector<int> restore(int l, int r) {

  if (!flag) return {};

  if (l+1 == r) {
    vector<int> q;
    q.pb(0);
    return q;
  }

  int mid = (l+r)/2;
  auto A = restore(l, mid);
  auto B = restore(mid, r);

  vector<int> C(A.size() + B.size(), 0);
  vector<int> posa(A.size()), posb(B.size());

  for (int i = 0; i < A.size(); ++i) posa[A[i]] = i;
  for (int i = 0; i < B.size(); ++i) posb[B[i]] = i;

  int u1 = 0, u2 = 0;
  int tot = 0;

  while (u1 < A.size() && u2 < B.size()) {
    if (u == s.size()) {
      flag = false;
      return {};
    }
    if (s[u++] == '0') {
      C[posa[u1++]] = tot++;
    }
    else {
      C[posb[u2++] + A.size()] = tot++;
    }
  }

  while (u1 < A.size()) {
    C[posa[u1++]] = tot++;
  }

  while (u2 < B.size()) {
    C[posb[u2++] + A.size()] = tot++;
  }

  return C;



}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> s;

  int L = 0, R = 100007;

  while (R-L>1) {

    int M = (L+R)/2;

    //cout << M << endl;

    u = 0;
    flag = true;

    auto ans = restore(0, M);
    if (!flag) R = M;
    else if (u != s.size()) L = M;
    else {

      cout << M << endl;
      for (auto x : ans) cout << x + 1 << " ";
      exit(0);

    }

  }


}