#include <iostream>
#include <algorithm>
using namespace std;
int t;
int main (){
  cin >> t;
  while (t--){
    int n,l,r,a[200001];
    cin >> n >> l >> r;
    for (int i=1;i<=n;i++){
      cin >> a[i];
    }
    sort(a+1,a+1+n);
    long long ans=0;
    int j1=n,j2=n;
    for (int i=1;i<=n;i++){
      while (j1>i && a[i]+a[j1]>=l){
        j1--;
      }
      while (j2>i && a[i]+a[j2]>r){
        j2--;
      }
      if(j2 <= i) break;
      if(j1 < i) j1 = i;
      ans+=(j2-j1);
    }
    cout << ans << endl;
  }
  return 0;
}