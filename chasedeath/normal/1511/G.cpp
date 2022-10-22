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

const int N=2e5+10,INF=1e9+10;

int n,m,q;
int A[N];
struct BIT{
	int s[1<<20];
	void clr(){ memset(s,0,(m+1)<<2); }
	void Add(int p,int x){
		for(p++;p<=m;p+=p&-p) s[p]^=x;
	}
	int Que(int p){
		int res=0;
		for(p++;p;p-=p&-p) res^=s[p];
		return res;
	}
	int Que(int l,int r){ return l<=r?Que(r)^Que(l-1):0; }
} T;

struct Node{
	int p,id,k;
	bool operator < (const Node __) const {
		return p<__.p;
	}
} Q[N*2];
int C,L[N],R[N],ans[N];

int main(){
	n=rd(),rd();
	rep(i,1,n) A[i]=rd();
	sort(A+1,A+n+1);
	rep(i,1,q=rd()) L[i]=rd(),R[i]=rd();
	rep(i,1,q) Q[++C]=(Node){L[i],i,-1};
	rep(i,1,q) Q[++C]=(Node){R[i],i,1};
	sort(Q+1,Q+C+1);
	rep(d,0,18) {
		//cout<<"calc "<<d<<endl;
		if((1<<d)>=A[n]) break;
		T.clr(),m=1<<(d+1);
		int p=1;
		rep(i,1,C) {
			while(p<=n && A[p]<=Q[i].p) T.Add(A[p]%m,1),p++;
			int x=L[Q[i].id]%m;
			//cout<<"$Q"<<T.Que(m/2+x,m-1)<<' '<<T.Que(max(0,x-m/2),x-1)<<endl;
			ans[Q[i].id]^=T.Que(m/2+x,m-1)<<d;
			ans[Q[i].id]^=T.Que(max(0,x-m/2),x-1)<<d;
		}
	}
	//rep(i,1,q) cout<<ans[i]<<' ';
	//puts("");
	rep(i,1,q) putchar(ans[i]?'A':'B');
}