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

const int N=610,INF=1e9+10;

typedef vector <int> Vec;

int n,fa[N];
Vec A,B;

int query(Vec part){
	if(part.size()<=1) return 0;
	printf("? %d\n",(int)part.size());
	for(int i:part) printf("%d ",i);
	puts("");
	fflush(stdout);
	int res=rd();
	if(res==-1) exit(0);
	return res;
}

int col[N];
int Calc(int u,Vec V){
	if(!V.size()) return 0;
	int res=-query(V);
	return V.pb(u),res+=query(V);
}
Vec Go;
void Solve(int u,Vec V,int &s){
	//cout<<"Solve "<<u<<' '<<"Count= "<<s<<' ';
	//for(int i:V) cout<<i<<' ';
	//puts("");
	if(!s) return;
	int c=Calc(u,V);
	if(!c) return;
	if(V.size()==1) return Go.pb(V[0]);
	s-=c;
	Vec X,Y;
	rep(i,0,V.size()/2-1) X.pb(V[i]);
	rep(i,V.size()/2,V.size()-1) Y.pb(V[i]);
	Solve(u,X,c),Solve(u,Y,c);
}

void Check(Vec V) {
	if(!query(V)) return;
	Vec X;
	rep(i,0,V.size()-1) {
		X.pb(V[i]);
		if(query(X)) {
			X.pop_back(),Go.clear();
			int t=Calc(V[i],X);
			Solve(V[i],X,t);
			int u=V[i],v=Go[0];
			//cout<<"odd circle "<<u<<' '<<v<<endl;
			vector <int> ans;
			while(u) ans.pb(u),u=fa[u];
			reverse(ans.begin(),ans.end());
			while(fa[v]) ans.pb(v),v=fa[v];
			printf("N %d\n",(int)ans.size());
			for(int i:ans) printf("%d ",i);
			puts("");
			exit(0);
		}
	}
	assert(0);
}

int main(){
	n=rd();
	while(1) {
		int fir=0;
		rep(i,1,n) if(!col[i]) { fir=i; break; }
		if(!fir) break;
		queue <int> que;
		col[fir]=1,que.push(fir);
		while(!que.empty()) {
			int u=que.front(); que.pop();
			if(col[u]==1) A.pb(u);
			else B.pb(u);
			vector <int> V; Go.clear();
			rep(i,1,n) if(!col[i]) V.pb(i);
			int t=Calc(u,V);
			Solve(u,V,t);
			for(int v:Go) assert(!col[v]),col[v]=3-col[u],que.push(v),fa[v]=u;
		}
	}
	if(int(A.size()+B.size())!=n) while(1);
	rep(i,1,n) if(!col[i]) while(1);
	Check(A),Check(B);
	printf("Y %d\n",(int)A.size());
	for(int i:A) printf("%d ",i);
}