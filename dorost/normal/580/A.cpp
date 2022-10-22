//in the name of GOD//

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define sz(s) s.size()

int main(){
  int n;
  cin >> n;
  int a[n], ans[n] = {},h = 1;
  cin >> a[0];
  for(int i = 1; i < n; i++){
    cin >> a[i];
    if(a[i] >= a[i - 1]){
      ans[h]++;
    }else{
      h++;
    }
  }
  sort(ans,ans + n);
  cout << ans[n - 1] + 1;
}