#include <bits/stdc++.h>

using namespace std;

const int N=(int)2e5+7;
int n,a[N],b[N];

bool ok(int total){
  int bef=0,after=total-1;
  for (int i=1;i<=n&&total>0;i++){
    if (a[i]>=bef&&b[i]>=after){
      bef++;
      after--;
      total--;
    }
  }
  return (total==0);
}

signed main() {
  ios::sync_with_stdio(0);cin.tie(0);

 // freopen ("input", "r", stdin);

  int t;
  cin>>t;
  while (t--){
    cin>>n;
    for (int i=1;i<=n;i++)cin>>b[i]>>a[i];

    int low=1,high=n,sol=0;
    while (low<=high){
      int mid=(low+high)/2;
      if(ok(mid)){
        sol=mid;
        low=mid+1;
      }else{
        high=mid-1;
      }
    }
    cout<<sol<<"\n";
  }


  return 0;
}