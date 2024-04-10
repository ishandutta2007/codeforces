#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ll long long
#define all(x) x.begin(),x.end()

using namespace std;

set<ll> st;
set<ll>::iterator it;
ll v[100005];
ll t[100005];
ll ans[100005];
ll tt[100005];
ll add[100005];
int n;

int main()
{
          cin>>n;
          for(int i=1;i<=n;i++)
                    cin>>v[i];
          for(int i=1;i<=n;i++)
          {
                    cin>>t[i];
                    tt[i]=t[i];
          }
          for(int i=1;i<=n+1;i++)
                    t[i]+=t[i-1];

          for(int i=1;i<=n;i++)
          {
                    int pos;
                    int l=i,r=n+1;
                    while(r-l>1)
                    {
                              int m=(r+l)/2;
                              if(v[i]<=t[m]-t[i-1])
                                        r=m;
                              else
                                        l=m;
                    }
                    if(t[l]-t[i-1]>=v[i])
                              pos=l;
                    else
                              pos=r;
                    ans[i]++;
                    ans[pos+1]--;
                    add[pos]+=v[i]-(t[pos]-t[i-1]);
          }
          for(int i=1;i<=n;i++)
                    ans[i]+=ans[i-1];
          for(int i=1;i<=n;i++)
                    cout<<ans[i]*tt[i]+add[i]<<" ";
}