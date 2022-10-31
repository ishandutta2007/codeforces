#include <iostream>

using namespace std;

typedef long long ll;

int n;
const int N = 200000;
int a[N],b[N];
int c,d;

int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
    if(a[i] == 1) c = i;
  }
  for(int i = 0; i < n; ++i) {
    cin >> b[i];
    if(b[i] == 1) d = i;
  }
  for(int k = 0; k < n; ++k) {
    if(a[c] != b[d]) {
      cout << "NO\n";
      return 0;
    }
    c = (c+1)%n;
    d = (d+1)%n;
    if(a[c] == 0) c = (c+1)%n;
    if(b[d] == 0) d = (d+1)%n;
  }
  cout << "YES\n";
  return 0;
}