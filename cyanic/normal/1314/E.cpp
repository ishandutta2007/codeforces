#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
mt19937 rnd((long int)(new char));

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=2050,mod=998244353;
int n,K;

void add(int &x,int y){
	x=(x+y>=mod?x+y-mod:x+y);
}
int f[N];
void dp1(){
	f[0]=1;
	rep(i,1,n) rep(j,0,n-i)
		add(f[i+j],f[j]);
	int ans=0;
	rep(i,1,n) add(ans,f[i]);
	printf("%d\n",ans);
}
int g[70][N];
void dp2(){
	int lim=sqrt(2*n)+1;
	g[0][0]=1;
	rep(k,0,lim) rep(j,0,n){
		add(g[k+1][j],g[k][j]);
		if(j+k*(k+1)/2<=n)
			add(g[k][j+k*(k+1)/2],g[k][j]);
	}
	int ans=0;
	rep(i,1,n) add(ans,g[lim][i]);
	printf("%d\n",ans);
}

int p[70],sz,res;

int chk(){
	vi now,nxt; int sum;
	rep(i,1,sz) now.pb(p[i]);
	rep(T,1,K-2){
		nxt.clear(); sum=0;
		for(int i=now.size()-1,val=1;i>=0;i--,val++)
			rep(j,1,now[i]) nxt.pb(val);
		for(int i=nxt.size()-1,val=1;i>=0;i--,val++)
			sum+=nxt[i]*val;
		if(sum>n) return 0;
		now=nxt;
	}
	return 1;
}
int dfs(int rem,int lea){
	if(!chk()) return 0;
	res++;
	rep(i,lea,rem){
		p[++sz]=i;
		if(!dfs(rem-i,i)){
			sz--;
			break;
		}
		sz--;
	}
	return 1;
}

void solve(){
	dfs(63,1);
	cout<<res-1<<endl;
}

int main(){
	read(n),read(K);
	if(K>=15){
		puts("1");
		return 0;
	}
	if(K==1) dp1();
	else if(K==2) dp2();
	else solve();
	return 0;
}