#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define bits bitset<N>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

const int N=3005,mod=998244353;
const ll Mod=(ll)mod*mod*8;
namespace{
	inline ll Add(const ll a,const ll b){return a+b>=Mod?a+b-Mod:a+b;}
	inline int add(const int a,const int b){return a+b>=mod?a+b-mod:a+b;}
	inline int sub(const int a,const int b){return a-b<0?a-b+mod:a-b;}
	inline int mul(const int a,const int b){return (ll)a*b%mod;}
	inline int power(int x,int p){
		int res=1;
		for(;p;p>>=1,x=mul(x,x))if(p&1)res=mul(res,x);
		return res;
	}
}
int dp[N][N],f[N][N],bin[N],s[N][N];
int a[N],ans[N],n,c,k;

void init(){
	bin[0]=1;
	rep(i,1,n)bin[i]=add(bin[i-1],bin[i-1]);
	rep(i,1,c)rep(j,1,n)s[i][j]=add(s[i][j-1],a[j]==i);
	bitset<N> owo;
	int counter=0;
	rep(i,1,n){
		if(!owo[a[i]])owo[a[i]]=1,++counter;
		if(counter==c)counter=0,owo.reset(),++k;
	}
}

void bf1(){
	int full=(1<<c)-1;
	dp[0][0]=f[0][0]=1;
	rep(i,1,n){
		int cur=1<<(a[i]-1);
		rep(p,1,k)dp[p][i]=add(dp[p][i],f[p-1][full^cur]);
		rep(s,0,full)if(s&cur)rep(p,0,k)
			f[p][s]=add(f[p][s],add(f[p][s],f[p][s^cur]));
		REP(p,k)f[p][0]=add(f[p][0],dp[p][i]);
	}
}

int cost[N][N];
void bf2(){
	rep(i,1,n){
		int rem=c,res=1;
		rep(j,i,n){
			int tmp=s[a[j]][j-1]-s[a[j]][i-1];
			if(tmp)res=mul(res,power(bin[tmp]-1,mod-2));
			else rem--;
			cost[j][i]=rem?0:res;
			res=mul(res,bin[tmp+1]-1);
		}
	}
	dp[0][0]=1;
	rep(p,1,k)rep(i,c*p,n){
		ll sum=0;
		rep(j,c*(p-1),i-c)
			sum=Add(sum,(ll)cost[i][j+1]*dp[p-1][j]);
		dp[p][i]=sum%mod;
	}
}

void work(){
	rep(i,0,k)rep(j,0,n)
		ans[i]=add(ans[i],mul(dp[i][j],bin[n-j]));
	rep(i,0,n)ans[i]=sub(ans[i],ans[i+1]);
	ans[0]=sub(ans[0],1);
	rep(i,0,n)printf("%d ",ans[i]);
}

int main(){
	scanf("%d%d",&n,&c);
	rep(i,1,n)scanf("%d",&a[i]);
	init();
	c<=10?bf1():bf2();
	work();
	return 0;
}