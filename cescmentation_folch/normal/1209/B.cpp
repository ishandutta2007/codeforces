#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;
typedef vector<pi> vpi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int iter = 5*4*3*2*2 + 10;
  int n;
  cin >> n;
  string a;
  cin >> a;
  vpi V(n);
  for (int i = 0; i < n; ++i) cin >> V[i].second >> V[i].first;
  int maxi = 0;
  for (int c = 1; c <= iter; ++c) {
    int cont = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] == '1') ++cont;
      if (c >= V[i].first and c%V[i].second == V[i].first%V[i].second) {
        if (a[i] == '1') a[i] = '0';
        else a[i] = '1';
      }
    }
    maxi = max(maxi, cont);
  }
  cout << maxi << endl;
}