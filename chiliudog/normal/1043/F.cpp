#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<cassert>
#include<queue>
#include<cmath>
#include<queue>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef pair<int,int> pin;
#define mk(a,b) make_pair(a,b)
#define lowbit(x) ((x)&(-(x)))
#define sqr(a) ((a)*(a))
#define clr(a) (memset((a),0,sizeof(a)))
#define mid (((l)+(r))>>1)
#define pb push_back
#define w1 first
#define w2 second
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
/*******************************head*******************************/
int n;
set<int> app;
const int maxn=300005;
vector<int> fac[maxn];
const int mod1=1e9+7,mod2=998244353;
int cnt[maxn],C1[maxn][50],C2[maxn][50],mu[maxn];
int prime[maxn],tot,flag[maxn];
inline void solve(){
	memset(flag,1,sizeof(flag));
	rep(i,2,300000){
		if(flag[i]){prime[++tot]=i;mu[i]=-1;}
		rep(j,1,tot){
			if(i*prime[j]>300000)break;
			flag[i*prime[j]]=0;
			if(i%prime[j]==0){
				mu[i*prime[j]]=0;
				break;
			}
			mu[i*prime[j]]=-mu[i];
		}
	}
}
inline int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	read(n);int res=0;
	mu[1]=1;solve();
	//cout<<mu[7]<<endl;
	rep(i,1,300000){
		for(int j=i;j<=300000;j+=i){
			fac[j].pb(i);
		}
	}
	rep(i,1,n){
		int x;read(x);
		if(app.count(x))continue;
		if(res==0)res=x;
		else{
			res=gcd(res,x);
		}app.insert(x);
		for(int v:fac[x]){
			cnt[v]++;
		}
	}
	if(res!=1){
		puts("-1");return 0;
	}rep(i,0,n)C1[i][0]=C2[i][0]=1;
	rep(k,1,n){
		rep(i,1,300000){
			C1[i][k]=(C1[i-1][k-1]+C1[i-1][k])%mod1;
		}
		i64 res1=0,res2=0;
		rep(d,1,300000){
			res1=(res1+1ll*mu[d]*C1[cnt[d]][k])%mod1;
		}
		if(res1==0){
			continue;
		}else{
		//	cerr<<res1<<' '<<res2<<endl;
		//	cerr<<C1[n][1]<<endl;
			cout<<k<<endl;
			return 0;
		}
	}
	return 0;
}