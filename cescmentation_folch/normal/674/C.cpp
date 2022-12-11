#include<bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const int MAXN = 200010;
const int MAXK = 54;

ld inv[MAXN];
ll S[MAXN];
ll A[MAXN];
ld M[MAXN][MAXK];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> S[i];
    A[i] = S[i];
    inv[i] = ld(1.0/ld(S[i]));
    if (i) {
      inv[i] += inv[i - 1];
      S[i] += S[i - 1];
    }
  }
  for (int i = 0; i < n; ++i) {
    M[i][0] = ld(ld(S[i])/ld(A[i]));
    if (i) M[i][0] += M[i - 1][0];
  }
  vector<int> V;
  for (int j = 1; j < k; ++j) {
    V.clear();
    V.push_back(j - 1);
    V.push_back(j);
    for (int i = j + 1; i < n; ++i) {
      ld b = M[i][j - 1] - M[i][0] + ld(S[i])*inv[i];
      ld m = ld(S[i]);
      while (V.size() >= 2) {
	ld b1 = M[V[V.size() - 1]][j - 1] - M[V[V.size() - 1]][0] + ld(S[V[V.size() - 1]])*inv[V[V.size() - 1]];
	ld m1 = ld(S[V[V.size() - 1]]);
	ld b2 = M[V[V.size() - 2]][j - 1] - M[V[V.size() - 2]][0] + ld(S[V[V.size() - 2]])*inv[V[V.size() - 2]];
	ld m2 = ld(S[V[V.size() - 2]]);
	ld x1 = (b1 - b)/(m - m1);
	ld x2 = (b2 - b1)/(m1 - m2);
	if (x1 > x2 + 1e-10) V.pop_back();
	else break;
      }
      V.push_back(i);
    }
    
    
    int tt = 0;
    for (int i = j; i < n; ++i) {
      int t = V[tt];
      M[i][j] = M[t][j - 1] + M[i][0] - ld(S[t])*(inv[i] - inv[t]) - M[t][0];
      while (tt < V.size() - 1) {
	++tt;
	t = V[tt];
	if (t >= i) {
	  --tt;
	  break;
	}
	ld kt = M[t][j - 1] + M[i][0] - ld(S[t])*(inv[i] - inv[t]) - M[t][0];
	if (kt <= M[i][j]) {
	  M[i][j] = kt;
	}
	else {
	  --tt;
	  break;
	}
      }
    }
  }
  cout << setprecision(10) << fixed << M[n - 1][k - 1] << endl;
}