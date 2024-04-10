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
  int N = 1010;
  vi p(2*N,1);
  for (int i = 2; i < 2*N; ++i) {
    if (p[i]) {
      for (int j = 2*i; j < 2*N; j += i) {
        p[j] = 0;
      }
    }
  }
  int n;
  cin >> n;
  int k = n;
  while (!p[k]) ++k;
  cout << k << '\n';
  for (int i = 0; i < n; ++i) {
    cout << i + 1 << ' ' << (i+1)%n + 1 << '\n';
  }
  int j = 0;
  for (int i = n; i < k; ++i) {
    cout << j + 1 << ' ' << j + 3 << '\n';
    if (j%2) j += 3;
    else j++;
  }

}