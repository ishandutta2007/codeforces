#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >>k;
  if (n == k) {
    cout << string(n, '1') << endl;
    return 0;
  }
  int q = (n -k)/2;
  if (q > k) {
    cout << string(q,'1') << '0' << string(q,'1');
    int s = n - 2*q - 1;
    if (s) {
      cout << '0';
      --s;
    }
    cout << string(s,'1') << endl;
    return 0;
  }
  cout << string(q-1,'1') << '0';
  n -= q;
  while (n) {
    int t = min(n,q);
    cout << string(t,'1');
    n -= t;
    if (n) {
      --n;
      cout << '0';
    }
  }
  cout << endl;
}