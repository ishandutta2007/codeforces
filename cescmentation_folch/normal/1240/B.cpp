#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef int llint;
typedef vector<llint> vi;
typedef vector<vi> vvi;
typedef pair<llint, llint> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vpi A(n, pi(n+1,n+1));
    int cont = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      --x;
      if (A[x].first == n+1) ++cont;
      A[x].first = min(A[x].first, i);
      A[x].second = i;
    }

    int res = cont;
    int ant = n+1;
    int mma = 0;
    int ccu = 0;
    for (int i = n-1; i >= 0; --i) {
      if (A[i].first == n+1) continue;
      if (A[i].second < ant) {
        ++ccu;
        mma = max(ccu, mma);
        ant = A[i].first;
      }
      else  {
        ant = A[i].first;
        ccu = 1;
        mma = max(ccu, mma);
      }
    }
    cout << res-mma << '\n';
  }

}