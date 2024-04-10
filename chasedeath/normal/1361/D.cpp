#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
//typedef long double db;
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

const int N=5e5+10,INF=1e9+10;

int n,m,c;
map <Pii,int> M;
vector <db> G[N];
int cnt[N],L[N],R[N];
db s[N];
int gcd(int a,int b){ return b==0?a:gcd(b,a%b); }
priority_queue <pair <db,int> > que;

void Push(int i){
	if(L[i]>R[i]) return;
	if(cnt[i]>0) {
		que.push(mp(G[i][R[i]--]*cnt[i],i));
		cnt[i]-=2;
	} else {
		que.push(mp(G[i][L[i]]*cnt[i]+s[i],i));
		s[i]-=2*G[i][L[i]++];
		//cnt[i]+=2;
	}
}

int main(){
	n=rd(),m=rd();
	rep(i,1,n) {
		int x=rd(),y=rd(),g=max(1,abs(gcd(x,y)));
		int &u=M[mp(x/g,y/g)];
		if(!u) u=++c;
		G[u].pb(sqrt(1ll*x*x+1ll*y*y));
	}
	rep(i,1,c) sort(G[i].begin(),G[i].end()),R[i]=G[i].size()-1,cnt[i]=m-1,Push(i);
	db ans=0;
	while(m--){
		ans+=que.top().first;
		//cout<<"Add "<<que.top().first<<endl;
		int i=que.top().second; que.pop();
		Push(i);
		//cout<<i<<endl;
	}
	printf("%.10lf\n",ans);
}