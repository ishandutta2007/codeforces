#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define LL long long
#define pii pair <LL,LL>
#define pb push_back
#define fi first
#define se second
#define mpr make_pair

using namespace std;

const LL MOD=998244353;

LL qpow(LL x,LL a)
{
	LL res=x,ret=1;
	while(a>0)
	{
		if((a&1)==1) ret=ret*res%MOD;
		a>>=1;
		res=res*res%MOD;
	}
	return ret;
}

LL n,c,a[3010],ans[3010],fst[3010],pw2[3010],inv[3010],repl[3010],mxp;
LL dp[3010][3010];//dp[ii][]
LL dp2[2][3010][2100];//dp2[i(0)][][ (, i-1]]
vector <LL> v;
vector <int> valid;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin>>n>>c;
  rep(i,n) cin>>a[i];
  mxp=n/c;
  pw2[0]=1;
  repn(i,3005)
  {
    pw2[i]=pw2[i-1]*2LL%MOD;
    repl[i]=(pw2[i]-1+MOD)%MOD;
  }
  repn(i,3005) inv[i]=qpow((pw2[i]-1+MOD)%MOD,MOD-2)%MOD;

  if(c>11)
  {
    dp[0][0]=1;
    rep(i,n)
    {
      rep(j,c+5) fst[j]=0;
      LL mul=1,cnt=0,bd=min((LL)(i+1),mxp+1);
      valid.clear();
      rep(j,bd) if(dp[i][j]>0) valid.pb(j);
      for(int j=i;j<n;++j)
      {
        ++fst[a[j]];
        if(fst[a[j]]==1) ++cnt;
        else mul=mul*inv[fst[a[j]]-1]%MOD*repl[fst[a[j]]]%MOD;
        if(cnt==c)
        {
          LL mull=mul*inv[fst[a[j]]]%MOD;
          rep(k,valid.size()) dp[j+1][valid[k]+1]=(dp[j+1][valid[k]+1]+dp[i][valid[k]]*mull)%MOD;
        }
        if(j==n-1)
        {
          repn(k,i+1)
          {
            LL mull=(pw2[n-i]-mul+MOD)%MOD;
            if(cnt!=c) mull=pw2[n-i];
            ans[k]=(ans[k]+dp[i][k]*mull)%MOD;
          }
        }
      }
    }
    repn(j,mxp) ans[j]=(ans[j]+dp[n][j])%MOD;
    ans[0]=(pw2[n]-1+MOD)%MOD;
    repn(i,mxp) ans[0]=(ans[0]-ans[i]+MOD)%MOD;
  }
  else
  {
    dp2[0][0][0]=1;
    rep(ii,n) 
    {
      int i=(ii&1);
      rep(j,mxp+5) rep(k,(1<<c)+5) dp2[i^1][j][k]=0;
      rep(j,min((LL)(ii+1),mxp+1)) rep(k,1<<c)
      {
        if(dp2[i][j][k]==0) continue;
        dp2[i^1][j][k]=(dp2[i^1][j][k]+dp2[i][j][k])%MOD;//
        if((k|(1<<(a[ii]-1)))==(1<<c)-1)//
          dp2[i^1][j+1][0]=(dp2[i^1][j+1][0]+dp2[i][j][k])%MOD;
        else//
          dp2[i^1][j][k|(1<<(a[ii]-1))]=(dp2[i^1][j][k|(1<<(a[ii]-1))]+dp2[i][j][k])%MOD;
      }
    }
    int i=(n&1);
    rep(j,mxp+1) rep(k,(1<<c)-1) ans[j]=(ans[j]+dp2[i][j][k])%MOD;
    ans[0]=(ans[0]-1+MOD)%MOD;
  }

  rep(i,n+1) cout<<ans[i]<<' ';
  cout<<endl;
	return 0;
}