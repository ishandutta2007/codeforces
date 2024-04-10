//in the name of GOD//

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(s) s.size()
int main(){
  int n;
  cin >> n;
  int a[n],blook = 1;
  cin >> a[0];
  for(int i = 1; i < n; i++){
    cin >> a[i];
    if(a[i] != a[i - 1]){
      blook++;
    }
  }
  int ans[blook] = {};
  int x = 0;
  for(int i = 1; i < n; i++){
    if(a[i] == a[i - 1]){
      ans[x]++;
    }else{
      x++;
    }
  }
  int maxi = min(ans[0],ans[1]);
  for(int i = 1;i < blook; i++){
    int z = min(ans[i],ans[i-1]);
    if(z > maxi){
      maxi = z;
    }
  }
  cout << 2 * maxi + 2;
}