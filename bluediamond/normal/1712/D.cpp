#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
/// #define int long long

const int N=(int)1e5+7;
const int inf=(int)1e9+7;
int n,init_v[N],a[N];

int minops(int k) {
  for (int i=1;i<=n;i++) {
    if (init_v[i]>=k){
      a[i]=1;
    } else {
      if (2*init_v[i]>=k) {
        a[i]=2;
      }else{
        a[i]=0;
      }
    }
  }
  int sigur=0;
  bool h1=0;
  for(int i=1;i<=n;i++){
    if(a[i]==0){
      sigur++;
      a[i]=1;
    }
    assert(a[i]==1||a[i]==2);
    h1|=(a[i]==1);
  }
  if(!h1){
    return sigur+2;
  }
  int cost=1;
  for(int i=1;i<n;i++){
    if(a[i]==1&&a[i+1]==1){
      cost=0;
    }
  }
  return cost+sigur;
  cout<<" ---> ";
  for(int i=1;i<=n;i++){
    cout<<a[i]<<" ";
  }
  cout<<"\n";

  return 0;
}

signed main()
{
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int t;
  cin>>t;
  for(int tc=1;tc<=t;tc++){
    int ops;
    cin>>n>>ops;
    for(int i=1;i<=n;i++){
      cin>>init_v[i];
    }

    int low=0,high=(int)1e9,sol=-1;
    while(low<=high){
      int mid=(low+high)/2;
      if(minops(mid)<=ops){
        sol=mid;
        low=mid+1;
      }else{
        high=mid-1;
      }
    }

    cout<<sol<<"\n";
    continue;

    exit(0);
  }
}