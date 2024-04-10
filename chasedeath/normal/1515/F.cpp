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

const int N=3e5+10;

int n,m,k;
struct Edge{ 
	int to,nxt;
} e[N<<1];
int head[N],ecnt,P[N],f;
ll S[N];
int A[N],C,F[N];
int Find(int x){ return F[x]==x?x:F[x]=Find(F[x]); }

ll lst[N];
queue <int> que;
struct cmp{ bool operator () (int x,int y) const { return e[x].to<e[y].to; } };
set <int,cmp> st[N];

int Union(int x,int i){
	int y=e[i].to;
	x=Find(x),y=Find(y);
	if(x==y) {
		st[x].erase(i),st[y].erase(i^1);
		return -1;
	}
	if(S[x]+S[y]<k) return 0;
	A[++C]=i/2;
	//cout<<"$"<<x<<' '<<y<<endl;
	if(st[x].size()<st[y].size()) swap(x,y);
	vector <int> T;
	if(S[y]>k) for(int i:st[x]) T.pb(i);
	if(S[x]>k) for(int i:st[y]) T.pb(i);
	F[y]=x;
	S[x]+=S[y]-k;
	for(int i:st[y]) st[x].insert(i);
	for(int i:T) Union(x,i);
	return 1;
}

int main(){
	//freopen("test.in","r",stdin);
	n=rd(),m=rd(),k=rd();
	rep(i,1,n) S[i]=rd(),F[i]=i;
	rep(i,1,m) {
		int u=rd(),v=rd();
		e[i*2]=(Edge){v,head[u]},head[u]=i*2;
		e[i*2+1]=(Edge){u,head[v]},head[v]=i*2+1;
		st[Find(u)].insert(i*2),st[Find(v)].insert(i*2+1);
		Union(u,i*2);
	}
	//return 0;
	rep(i,1,m) assert(Union(e[i*2+1].to,i*2)!=1);
	//cerr<<"!"<<endl;
	/*rep(i,1,n) que.push(i),lst[i]=S[i];
	while(!que.empty()) {
		;
		;
		;
		;
		;
		;
	}
	while(1) {
		f=0;
		if(rand()&1) random_shuffle(P+1,P+n+1);
		else sort(P+1,P+n+1,[&](int x,int y){ return S[Find(x)]>S[Find(y)]; });
		rep(j,1,n) {
			int i=P[j];
			if(S[Find(i)]>lst[i]) lst[i]=S[F[i]],dfs(i);
		}
		if(!f || C==n-1) break;
	}*/
	//return 0;
	if(C==n-1) {
		puts("YES");
		rep(i,1,n-1) printf("%d\n",A[i]);
	} else puts("NO");
}