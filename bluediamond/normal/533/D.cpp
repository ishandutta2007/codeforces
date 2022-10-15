#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=(int)1e5+7;
const ll INF=(ll)1e18+7;
int n,lft[N],rgh[N];
ll x[N],d[N];
ll ff[N],ss[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen ("___input___.txt","r",stdin);
#endif // ONLINE_JUDGE

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

  cin>>n;

  for(int i=0;i<=n+1;i++)cin>>x[i];
  for(int i=1;i<=n;i++)cin>>d[i];
  vector<int> stk;
  for(int i=0;i<=n+1;i++){
    if(i-1>=1){
      int j=i-1;
      while(!stk.empty()&&2*d[j]+x[lft[j]]>=2*d[stk.back()]+x[lft[stk.back()]])stk.pop_back();
      stk.push_back(j);
    }
    lft[i]=0;
    int low=0,high=(int)stk.size()-1;
    while(low<=high){
      int mid=(low+high)/2;
      int j=stk[mid];
      if (2*d[j]+x[lft[j]]>=x[i]){
        lft[i]=j;
        low=mid+1;
      }else{
        high=mid-1;
      }
    }
  }
  stk.clear();
  for(int i=n+1;i>=0;i--){
    if(i+1<=n){
      int j=i+1;
      while(!stk.empty()&&x[rgh[j]]-2*d[j]<=x[rgh[stk.back()]]-2*d[stk.back()])stk.pop_back();
      stk.push_back(j);
    }
    rgh[i]=n+1;
    int low=0,high=(int)stk.size()-1;
    while(low<=high){
      int mid=(low+high)/2;
      int j=stk[mid];
      if(x[i]>=x[rgh[j]]-2*d[j]){
        rgh[i]=j;
        low=mid+1;
      }else{
        high=mid-1;
      }
    }
  }


  if(lft[n+1]!=0){
    cout<<"0\n";
    exit(0);
  }

  ll sol=(ll)1e18+7;
  for (int i=0;i<=n+1;i++){
    if(i==0)ff[i]=INF;
    else ff[i]=2*d[i]+x[lft[i]];
    if(i==n+1)ss[i]=-INF;
    else ss[i]=x[rgh[i]]-2*d[i];
  }
  stk.clear();

  for(int i=n+1;i>=0;i--) {
    if(i+1<=n+1){
      int j=i+1;
      if(ss[j]<=x[j]){
        while(!stk.empty()&&ss[j]<=ss[stk.back()])stk.pop_back();
        stk.push_back(j);
      }
    }
    if(x[i]>ff[i])continue;

    int low=0,high=(int)stk.size()-1,until=-1;
    while(low<=high){
      int mid=(low+high)/2;
      if(ss[stk[mid]]<=ff[i]){
        until=mid;
        low=mid+1;
      }else{
        high=mid-1;
      }
    }

    for(int iter=until;iter>=0;iter--) {
      int j=stk[iter];
      if(x[i]>=ss[j]&&x[i]==min(x[j],ff[i]))continue;
      if(x[j]<=ff[i]&&x[j]==max(x[i],ss[j]))continue;
      sol=min(sol,x[j]-x[i]);
      break;
    }
  }
  cout<<sol/2;
  if(sol%2){
    cout<<".5";
  }
  cout<<"\n";
}