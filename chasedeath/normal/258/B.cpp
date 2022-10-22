#include<bits/stdc++.h>
using namespace std;

#define reg register
typedef long long ll;
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)

int IO;
int rd(){
	int s=0;
	while((IO=getchar())<48);
	do s=(s<<1)+(s<<3)+(IO^'0');
	while((IO=getchar())>47);
	return s;
}

const int N=510;
const ll P=1e9+7;

int n;
int nowx;

int a[150];
int dp[200][150];
int dfs(int p,int x,int lim){
	if(p==0) return x==nowx;
	if(!lim&&~dp[p][x]) return dp[p][x];
	int Up=lim?a[p]:9,res=0;
	rep(i,0,Up) res+=dfs(p-1,x+(i==4)+(i==7),lim&&(i==Up));
	if(!lim) dp[p][x]=res;
	return res;
}
int Solve(int i){
	nowx=i;
	memset(dp,-1,sizeof dp);
	int c=0,t=n;
	while(t) a[++c]=t%10,t/=10;
	return dfs(c,0,1);
}





ll cnt[150];
ll c[150];

void dfs1(int now,int x,ll s){
	//cout<<"#"<<now<<' '<<x<<' '<<y<<' '<<s<<endl;
	if(!now){
		(c[x]+=s)%=P;
		return;
	}
	rep(i,0,9) if(cnt[i]) {
		cnt[i]--;
		dfs1(now-1,x+i,s*(cnt[i]+1)%P);
		cnt[i]++;
	}
}



int main(){
	n=rd();
	ll ans=0;
	rep(i,0,9) cnt[i]=Solve(i);
	cnt[0]--;
	//rep(i,0,9) if(cnt[i]) cout<<i<<' '<<cnt[i]<<endl;
	dfs1(6,0,1);
	//rep(i,0,9) if(c[i]) cout<<"#"<<i<<' '<<c[i]<<endl;
	ll t=0;
	rep(i,0,9){
		(ans+=cnt[i]*t%P)%=P;
		(t+=c[i])%=P;
	}
	printf("%lld\n",ans);
}