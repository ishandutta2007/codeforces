#include <bits/stdc++.h>

using namespace std;

int a[300],b[300];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin>>t;
  while (t--){
    for (int i=0;i<300;i++)a[i]=b[i]=0;
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) {int x;cin>>x;a[x+105]++;}
    for (int i=1;i<=n;i++) {int x;cin>>x;b[x+105]++;}

    bool bad=0;

    for (int i=1;i<=290;i++){
      int t=min(a[i],b[i]);
      a[i]-=t;
      if (a[i]>b[i+1]){
        bad=1;
        break;
      }else{
        b[i+1]-=a[i];
      }
    }

    if(!bad)cout<<"YES\n";
    else cout<<"NO\n";

  }


  return 0;
}