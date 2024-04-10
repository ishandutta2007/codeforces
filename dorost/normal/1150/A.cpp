//in the name of GOD//

#include<bits/stdc++.h>
#include <fstream>

using namespace std;

typedef long long ll;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define sz(s) s.size()

int main(){
  int n,m,r,ans = 0;
  cin >> n >> m >> r;
  int a[n],b[m];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  for(int i = 0; i < m; i++){
    cin >> b[i];
  }
  sort(a, a + n);
  sort(b, b + m);
  cout << max(r / a[0] * b[m - 1] + r % a[0] , r);
}