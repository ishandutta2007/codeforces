#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=200005,mod=1e9+7;
struct edge{int v,las,now;};vector<edge> e[N];
int deg[N],vis[N],f[N],lis[N],las[N],now[N];
int way[2],res[2],cnt,n,m,aim=1;

void upd(){
	int t=((ll)way[0]*res[0]+(ll)way[1]*res[1])%mod;
	way[1]=((ll)way[0]*res[1]+(ll)way[1]*res[0])%mod;
	way[0]=t;
}

void up(int &x,int y){
	x=(x+y>=mod?x+y-mod:x+y);
}

int dp[N][2][2][2];

void solve(int s){
	int t,ty; cnt=0;
	lis[++cnt]=s,vis[s]=1;
	rep(i,1,cnt){
		int u=lis[i];
		for(auto t:e[u])
			if(!vis[t.v]){
				lis[++cnt]=t.v;
				vis[t.v]=1;
				now[cnt]=t.las;
				las[cnt]=t.now;
				break;
			}
	}
	if(ty=(deg[s]>1)){
		auto t=e[s][1];
		now[cnt+1]=t.now,las[cnt+1]=t.las;
	}
//	rep(i,1,cnt+ty)
//		printf("(%d,%d,%d)\n",i,las[i],now[i]);
	rep(i,1,cnt+1)
		memset(dp[i],0,sizeof dp[i]);
	if(f[s]==0){
		dp[1][0][0][0]=1;
		dp[1][1][1][0]=1;
	}
	else{
		int v=(f[s]==1);
		dp[1][0][0][v]=1;
		dp[1][1][1][1^v]=1;
	}
	rep(i,2,cnt+ty)REP(a,2)REP(b,2)REP(c,2)REP(d,2)
		up(dp[i][a][d][c^((b^las[i])|(d^now[i]))],dp[i-1][a][b][c]);
	int v=-1;
	if(f[lis[cnt]]!=0)v=(f[lis[cnt]]==1);
	REP(a,2)REP(b,2)REP(c,2)
		if(!ty||a==b)up(res[v==-1?c:(c^v^b)],dp[cnt+ty][a][b][c]);
}

int main(){
	read(m),read(n);
	rep(i,1,m){
		int c,a,b;
		read(c),read(a);
		if(c==2)read(b);
		if(c==1||c==2&&abs(a)==abs(b)){
			if(c==2&&a!=b){
				aim^=1;
				continue;
			}
			f[abs(a)]^=1<<(a>0);
		}
		else{
			int x=(a<0),y=(b<0);
			a=abs(a),b=abs(b);
			e[a].pb((edge){b,y,x});
			e[b].pb((edge){a,x,y});
			deg[a]++,deg[b]++;
		}
	}
	way[0]=1;
	rep(i,1,n)
		if(!deg[i]){
			vis[i]=1;
			if(f[i]==0)res[0]=2,res[1]=0;
			else if(f[i]==3)res[0]=0,res[1]=2;
			else res[0]=1,res[1]=1;
			upd();
		}
	rep(i,1,n)
		if(deg[i]==1&&!vis[i]){
			res[0]=res[1]=0;
			solve(i),upd();
		}
	rep(i,1,n)
		if(!vis[i]){
			res[0]=res[1]=0;
			solve(i),upd();
		}
	cout<<way[aim]<<endl;
	return 0;
}