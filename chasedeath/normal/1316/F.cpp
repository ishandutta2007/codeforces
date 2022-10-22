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

const int N=3e5+10,INF=1e9+10,P=1e9+7;

int n,m;
int A[N],K[N],Rt;
struct Node{
	int ls,s,rs,ans;
	Node(){}
	Node(int x){ s=(P+1)/2,ls=rs=1ll*s*x%P,ans=0; }
	Node operator + (const Node _) const {
		Node res;
		res.ls=(1ll*ls*_.s+_.ls)%P;
		res.rs=(1ll*_.rs*s+rs)%P;
		res.s=1ll*s*_.s%P;
		res.ans=(1ll*ls*_.rs+ans+_.ans)%P;
		//cout<<"Up "<<res.ans<<' '<<ans<<' '<<_.ans<<' '<<ls<<' '<<_.rs<<endl;
		return res;
	}
} S[N];
int ls[N],rs[N];
void Up(int u){ 
	S[u]=Node(A[u]);
	if(ls[u]) S[u]=S[ls[u]]+S[u];
	if(rs[u]) S[u]=S[u]+S[rs[u]];
}
int Uni(int x,int y) {
	//cout<<"uni "<<x<<' '<<y<<endl;
	if(!x||!y) return x|y;
	if(K[x]<K[y]) return rs[x]=Uni(rs[x],y),Up(x),x;
	return ls[y]=Uni(x,ls[y]),Up(y),y;
}
int cmp(int u,int v){ return A[u]<A[v]||(A[u]==A[v] && u<v); }
Pii Split(int u,int v) {
	//cout<<"Split "<<u<<' '<<ls[u]<<' '<<rs[u]<<endl;
	if(!u) return mp(0,0);
	if(cmp(v,u)) {
		Pii w=Split(ls[u],v);
		return ls[u]=w.second,Up(u),mp(w.first,u);
	} else {
		Pii w=Split(rs[u],v);
		return rs[u]=w.first,Up(u),mp(u,w.second);
	}
}

int Popend(int x){
	if(rs[x]) return rs[x]=Popend(rs[x]),Up(x),x;
	return ls[x];
}
void Del(int x){
	Pii t=Split(Rt,x);
	//cout<<"Del "<<Rt<<' '<<x<<' '<<t.first<<' '<<t.second<<endl;
	Rt=Uni(Popend(t.first),t.second);
}
void Ins(int x){
	ls[x]=rs[x]=0,S[x]=Node(A[x]),K[x]=rand();
	Pii t=Split(Rt,x);
	Rt=Uni(t.first,Uni(x,t.second));
}

int main(){
	//S[0].s=1;
	n=rd();
	rep(i,1,n) A[i]=rd(),Ins(i);
	printf("%d\n",S[Rt].ans);
	//cout<<"$"<<Rt<<' '<<ls[Rt]<<' '<<rs[Rt]<<endl;
	rep(_,1,rd()) {
		int x=rd(),y=rd();
		Del(x),A[x]=y,Ins(x);
		printf("%d\n",S[Rt].ans);
	}
}