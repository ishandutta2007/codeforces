#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;++i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define mpr make_pair
#define pb push_back

using namespace std;

LL t,n,m;
vector <LL> ans;

void check(LL nn,LL mm,LL mmm)
{
  for(LL i=1;i*i<=nn;++i) if(nn%i==0)
  {
    if(mm%i==0&&mmm%i==0) ans.pb(i);
    if(mm%(nn/i)==0&&mmm%(nn/i)==0) ans.pb(nn/i);
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);
  cin>>t;
  rep(tn,t)
  {
    cin>>n>>m;
    ans.clear();ans.pb(1);
    check(n-1,m-1,m-1);check(n,m-2,m-2);check(n-2,m,m);check(n,n-2,m-1);check(m,m-2,n-1);
    sort(ans.begin(),ans.end());ans.erase(unique(ans.begin(),ans.end()),ans.end());
    cout<<ans.size()<<' ';
    rep(i,ans.size()) cout<<ans[i]<<' ';cout<<endl;
  }
	return 0;
}