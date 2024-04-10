#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=757;
const ll mod=1e15+7;
ll p2[N],a[N][N],sm[N][N],p[N],h[N],s[N],p0[N],sl[28];
bool f[300][300][300];
char ss[N];
ll n,m,ans=0,cnt;

ll Manacher(ll len)
{ 
    ll max_len = -1; 

    ll id;
    ll mx = 0;
	memset(p,0,sizeof(p));
    for (ll i = 1; i < len; i++)
    {
        if (i < mx)
            p[i] = min(p[2 * id - i], mx - i); 
        else
            p[i] = 1;
        while (s[i - p[i]] == s[i + p[i]]) p[i]++;

        
        if (mx < i + p[i])
        {
            id = i;
            mx = i + p[i];
        }

        max_len = max(max_len, p[i] - 1);
    }
}
int main(){
	scanf("%I64d%I64d",&n,&m);
	p0[0]=1;
	rep(i,28)p0[i]=p0[i-1]*(m+1)%mod;
	rep(i,n){
		scanf("%s",ss+1);
		rep(j,m)a[i][j]=ss[j]-'a';
	}
	rep(i,n){
		rep(j,m){
			sm[i][j]=sm[i][j-1];
			sm[i][j]=(p0[a[i][j]]+sm[i][j])%mod;
		}
	}
	rep(i,n){
		rep(L,m){
			memset(sl,0,sizeof(sl));
			ll dl=0;
			REP(R,L,m){
				if(sl[a[i][R]]&1)dl--;
				else dl++;
				sl[a[i][R]]++;
				if(dl<2)f[i][L][R]=1;
			}
		}
	}
	rep(L,m){
		REP(R,L,m){
			ll nw=mod;
			cnt=0;
			rep(i,n){
				s[++cnt]=-1;
				if(f[i][L][R])s[++cnt]=(sm[i][R]-sm[i][L-1]+mod)%mod;
				else s[++cnt]=++nw,s[++cnt]=++nw;
			}
			s[++cnt]=-1;
			s[++cnt]=mod;
			s[0]=-mod;
			Manacher(cnt);
			rep(i,cnt-1)ans+=p[i]/2;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}