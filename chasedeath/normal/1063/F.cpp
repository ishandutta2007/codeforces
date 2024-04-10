#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int,int> Pii;
#define reg register
#define mp make_pair
#define pb push_back
#define Mod1(x) ((x>=P)&&(x-=P))
#define Mod2(x) ((x<0)&&(x+=P))
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
template <class T> inline void cmin(T &a,T b){ ((a>b)&&(a=b)); }
template <class T> inline void cmax(T &a,T b){ ((a<b)&&(a=b)); }

char IO;
template <class T=int> T rd(){
	T s=0; int f=0;
	while(!isdigit(IO=getchar())) f|=IO=='-';
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=1e6+10,INF=1e9+10;

int n,m;
char s[N];
int link[N],trans[N][26],lst,cnt,len[N];
int End[N],fa[20][N];

vector <Pii> G[N];
void Push(int x,int y,int z) {
	cmin(z,len[x]);
	if(G[x].size() && G[x].rbegin()->second==len[x]) return;
	G[x].pb(mp(y,max(z,G[x].size()?G[x].rbegin()->second:0)));
	if(x) Push(link[x],y,z);
}

void Extend(int c){
	int p=lst,cur=++cnt; len[cur]=len[lst]+1,lst=cur;
	while(~p && !trans[p][c]) trans[p][c]=cur,p=link[p];
	End[len[cur]]=cur;
	if(p==-1) link[cur]=0;
	else {
		int q=trans[p][c];
		if(len[q]==len[p]+1) link[cur]=q;
		else {
			int v=++cnt;
			len[v]=len[p]+1,memcpy(trans[v],trans[q],104);
			while(~p && trans[p][c]==q) trans[p][c]=v,p=link[p];
			link[v]=link[q],link[cur]=link[q]=v;
		}
	}
}

int dp[N];
int Find(int x,int l) {
	drep(i,19,0) if(len[fa[i][x]]>=l) x=fa[i][x];
	return x;
}
int Que(int x,int y) { // query maxlen x when i<=y
	auto it=upper_bound(G[x].begin(),G[x].end(),mp(y,INF));
	if(it==G[x].begin()) return 0;
	return --it,it->second;
}


int main(){
	n=rd(),link[0]=-1;
	scanf("%s",s+1),reverse(s+1,s+n+1);
	//puts(s+1);
	rep(i,1,n) Extend(s[i]-'a');
	rep(i,0,cnt) fa[0][i]=link[i];
	rep(i,1,19) rep(j,1,cnt) fa[i][j]=fa[i-1][fa[i-1][j]];
	int ans=0;
	rep(i,1,n) {
		dp[i]=max(1,dp[i-1]-1);
		while(1) {
			int t=dp[i]+1;
			int f=0;
			f|=Que(Find(End[i],t-1),i-t)>=t-1;
			f|=Que(Find(End[i-1],t-1),i-t)>=t-1;
			if(f) dp[i]=t;
			else break;
		}
		//cout<<dp[i]<<' ';
		cmax(ans,dp[i]),Push(Find(End[i],dp[i]),i,dp[i]);
	}
	//puts("");
	printf("%d\n",ans);
}