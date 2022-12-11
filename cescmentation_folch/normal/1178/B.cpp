#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef long long llint;
typedef vector<llint> vi;
typedef vector<vi> vvi;
typedef pair<llint, llint> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string a;
  cin >> a;
  int n = a.size();
  vi L(n,0);
  vi R(n,0);
  for (int i = 1; i < n; ++i) {
    L[i] = L[i-1];
    if (a[i] == 'v' and a[i-1] == 'v') ++L[i];
  }
  for (int i = n-2; i >= 0; --i) {
    R[i] = R[i+1];
    if (a[i] == 'v' and a[i+1] =='v') ++R[i];
  }
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 'o') res += L[i]*R[i];
  }
  cout << res << endl;

}