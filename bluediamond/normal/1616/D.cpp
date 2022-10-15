#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N=50000+7;
const int K=17;
int n;
int x;
int a[N];
int s[N];
int t[K][N];
int lg[N];

/**
l+1<=r
l<=r-1

a=r
b=l-1
l=b+1

b+1<=a-1
b<=a-2

s(r)-s(l-1)>=x*(r-l+1)
s(r)-s(l-1)>=x*(r-(l-1))
s(r)-x*r>=s(l-1)-x*(l-1)
**/

int get(int l,int r){
  assert(1<=l&&l<=r&&r<=n);
  int k=lg[r-l+1];
  return min(t[k][l],t[k][r-(1<<k)+1]);
}

bool isok(int l,int r){
  assert(l<=r);
  if(l==r)return 1;
  return get(l+1,r)>=s[l-1];
}

int go[N];

signed main()
{
  ios::sync_with_stdio(0);cin.tie(0);
 // freopen("input","r",stdin);
  for (int i=2;i<N;i++)lg[i]=1+lg[i/2];
  int tests;
  cin>>tests;
  while (tests--)
  {
    cin>>n;
    for (int i=1;i<=n;i++)cin>>a[i];
    cin>>x;
    for (int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    for (int i=1;i<=n;i++)s[i]-=i*x;
    for (int i=1;i<=n;i++){
      t[0][i]=s[i];
    }
    for (int k=1;(1<<k)<=n;k++){
      for (int i=1;i+(1<<k)-1<=n;i++){
        t[k][i]=min(t[k-1][i],t[k-1][i+(1<<(k-1))]);
      }
    }
    for (int l=1;l<=n;l++){
      go[l]=-1;
      int low=l,high=n;
      while (low<=high){
        int mid=(low+high)/2;
        if(isok(l,mid)){
          go[l]=mid;
          low=mid+1;
        }else{
          high=mid-1;
        }
      }
      assert(go[l]!=-1);
    }
    int restr=n+1,cost=0;
    for (int i=1;i<=n;i++){
      if(i>=restr){
        cost++;
        restr=n+1;
        continue;
      }
      restr=min(restr,go[i]+1);
    }
    cout<<n-cost<<"\n";
    /**

    all sums>=0

    **/

  }
}