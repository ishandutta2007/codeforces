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
  string a;
  cin >> a;
  int n = (int)a.size();
  int k = n/2;
  string r(k,'0');
  for (int i = 0; i < k/2; ++i) {
    int j1 = 2*i;
    int j2 = n - j1 -2;
    if (a[j1] == a[j2] or a[j1] == a[j2+1]) r[i] = a[j1];
    else r[i] = a[j1+1];
    r[k-i-1] = r[i];
  }
  if (k%2) r[k/2] = a[n/2];
  cout << r << endl;
}