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
  int n;
  cin >> n;
  vi V(n);
  vi R(n);
  int res = 0;
  for (int i = 0; i < n; ++i) {
    cin >> V[i];
    R[i] = V[i]%2;
    if (V[i] < 0 and R[i]) {
      V[i] /= 2;
      V[i]--;
    }
    else V[i] /= 2;
    res += V[i];
  }
  for (int i = 0; i < n; ++i) {
    if (res < 0 and R[i]) {
      ++V[i];
      ++res;
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << V[i] << '\n';
  }
  

}