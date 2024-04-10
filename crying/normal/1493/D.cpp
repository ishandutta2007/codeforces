#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=2e5+10,LIM=2e5,moder=1e9+7,INF=1e9;
int notprime[MAXN],prime[MAXN],minp[MAXN],tot;
multiset<int>f[MAXN]; //0
map<int,int>c[MAXN]; // 
int g[MAXN]; // 
int rest[MAXN]; //0 
int n,m,a,idx,x;
ll ans;
ll gcd(ll a,ll b){
	if(!b)return a;
	return gcd(b,a%b);
}
void solve(){
	rep(i,2,LIM){
		if(!notprime[i]){
			prime[++tot]=i;minp[i]=i;
		}
		rep(j,1,tot){
			if(prime[j]*i>LIM)break;
			notprime[prime[j]*i]=1;
			minp[prime[j]*i]=prime[j];
			if(i%prime[j]==0)break;
		}
	}
}
int main(){
	solve();
	scanf("%d%d",&n,&m);
	rep(i,1,LIM){
		g[i]=INF;rest[i]=n;
	}
	rep(i,1,n){
		scanf("%d",&a);
		if(i==1)ans=a;else ans=gcd(ans,a);
		//sqrt 
		int tmp=a,cnt=0;
		for(int j=2;j*j<=a;j++){
			cnt=0;
			while(tmp%j==0)cnt++,tmp/=j;
			if(cnt){
				f[j].insert(cnt);g[j]=min(g[j],cnt);rest[j]--;c[i][j]=cnt;
			}
		} 
		if(tmp!=1){
			f[tmp].insert(1);g[tmp]=min(g[tmp],1);rest[tmp]--;c[i][tmp]=1;
		}
	} 
	rep(i,1,LIM){
		if(rest[i])g[i]=0;
	}
	rep(i,1,m){
		scanf("%d%d",&idx,&x);
		//log 
		while(x!=1){
			int num=minp[x]; //num
			f[num].insert(c[idx][num]+1);
			if(!c[idx][num])rest[num]--;
			else f[num].erase(f[num].find(c[idx][num]));
			if(!g[num]){
				if(!rest[num]){
					g[num]++;ans=ans*num%moder;
				}
			}else{
				if(!f[num].count(g[num])){
					g[num]++;ans=ans*num%moder;
				}
			}
			c[idx][num]++;
			x/=minp[x];
		}
		printf("%lld\n",ans);
	}
	return 0;
}