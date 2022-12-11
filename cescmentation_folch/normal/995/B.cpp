#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

int main() {
  int n;
  cin >> n; 
  n *= 2;
  vi V(n);
  for (int i = 0; i < n; ++i) cin >> V[i];
  int res = 0;
  for (int j = n-1; j >= 0; --j) {
    if (V[j] == 0) continue;
    int k = 0;
    for (int i = 0; i < j; ++i) {
      if (V[i] == 0) continue;
      else if (V[i] == V[j]) {
        V[i] = 0;
        k = 1;
      }
      else res += k;
    }
  }
  cout << res << '\n';
}