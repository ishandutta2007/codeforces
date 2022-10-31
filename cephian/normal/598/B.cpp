#include <iostream>

using namespace std;

string s,a;
const int N = 300;
int l[N],r[N],q[N];
int main() {
  cin >> s;
  a=s;
  int m;
  cin >> m;
  for(int i = 0; i < m; ++i) {
    cin >> l[i] >> r[i] >> q[i];
    --l[i];
    --r[i];
  }
  for(int i = 0; i < s.size(); ++i) {
    int j = i;
    for(int k = 0; k < m; ++k) {
      if(j < l[k] || j > r[k]) continue;
      j = ((j-l[k]+q[k])%(r[k]-l[k]+1))+l[k];
    }
    a[j]=s[i];
  }
  cout << a << "\n";
  return 0;
}