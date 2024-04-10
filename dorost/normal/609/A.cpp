//in the name of GOD//

#include<bits/stdc++.h>
#include <fstream>

using namespace std;

typedef long long ll;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define sz(s) s.size()

int main(){
  int n,m;
  cin >> n >> m;
  int a[n],sum = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  sort(a, a + n);
  for(int i = n - 1; i >= 0; i--){
    sum += a[i];
    if(sum >= m){
      cout << n - i;
      return 0;
    }
  }
}