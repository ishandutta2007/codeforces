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

const int N=45;

int n,m;
int G[N][N];
ll E[N];

ll Solve0(){
	static int S[1<<20];
	ll ans=0;
	/*rep(i,0,(1<<n)-1) {
		int S=0;
		rep(j,0,n-1) if(~i&(1<<j)) S|=E[j];
		if((S&~i)==0) ans++;
	}*/
	int m=n/2,A=(1<<m)-1;
	rep(i,0,(1<<m)-1) {
		ll T=0;
		rep(j,0,m-1) if(~i&(1<<j)) T|=E[j];
		S[i]=(~i&T&A)==0;
	}
	for(int i=1;i<=A;i<<=1) for(int l=0;l<=A;l+=i*2) for(int j=l;j<l+i;++j) S[j]+=S[j+i];
	rep(i,0,(1<<(n-m))-1) {
		ll T=0;
		rep(j,0,n-m-1) if(~i&(1<<j)) T|=E[j+m];
		if((T>>m)&~i) continue;
		T&=A,ans+=S[T];
	}
	//cout<<"$ Solve0 "<<ans<<endl;
	//assert(ans%(1ll<<31)==0);
	//cout<<(ans>>31)<<endl;
	return ans;
}

ll Solve1(){
	static int vis[N];
	function<void(int)> dfs=[&](int u) {
		if(vis[u]) return;
		vis[u]=1;
		rep(i,0,n-1) if(G[u][i]) dfs(i);
	};
	ll ans=1;
	rep(i,0,n-1) if(!vis[i]) dfs(i),ans<<=1;
	//cout<<"$ Solve1 = "<<ans<<endl;
	return ans;
}

ll Solve01(){
	ll ans=1;
	rep(i,0,n-1) if(!E[i]) ans<<=1;
	//cout<<"$ Solve01 = "<<ans<<endl;
	return ans;
}

ll Solve02(){
	static int vis[N],fl=1;
	function <void(int,int)> dfs=[&](int u,int c) {
		if(vis[u]) {
			if(vis[u]!=c) fl=0;
			return;
		}
		vis[u]=c;
		rep(i,0,n-1) if(G[u][i]) dfs(i,3-c);
	};

	ll ans=1;
	rep(i,0,n-1) if(!vis[i]) dfs(i,1),ans<<=1;
	//cout<<"$ Solve02 = "<<fl*ans<<endl;
	return fl*ans;
}


int main(){
	n=rd(),m=rd();
	rep(i,1,m) {
		int x=rd()-1,y=rd()-1;
		G[x][y]=G[y][x]=1;
		E[x]|=1ll<<y,E[y]|=1ll<<x;
	}
	ll ans=1ll<<n;
	//cout<<Solve0()<<endl;
	ans-=2*Solve0(),ans-=Solve1();
	ans+=2*Solve01()+Solve02();
	if(m==0) ans-=1ll<<n;
	printf("%lld\n",ans);
}