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

int n,m,ans,ma,id;
int A[N],C[N];

void Work(int x){
	static int S[N],Fir[N*2];
	Fir[S[0]=N]=1;
	rep(i,1,n) {
		S[i]=S[i-1]+(A[i]==x)-(A[i]==id);
		if(Fir[S[i]]) cmax(ans,i-Fir[S[i]]+1);
		else Fir[S[i]]=i+1;
	}
	rep(i,0,n) Fir[S[i]]=0;
}

void Solve(int d){
	static vector <int> G[N];
	rep(i,1,n) G[i].clear();
	int l=0,r1=-1,r2=-1;
	rep(i,1,n) {
		G[A[i]].pb(i);
		int c=G[A[i]].size();
		if(c>d) cmax(l,G[A[i]][c-d-1]);
		if(c>=d) {
			int t=G[A[i]][c-d];
			if(t>r1) swap(r1,t);
			if(t>r2) r2=t;
		}
		if(r2>l) {
			cmax(ans,i-l);
			//cout<<"$"<<d<<' '<<i<<' '<<l<<' '<<r1<<' '<<r2<<endl;
		}
	}
}

int main(){
	n=rd(),m=ceil(sqrt(n)/2);
	rep(i,1,n) C[A[i]=rd()]++;
	rep(i,1,n) if(C[i]>ma) ma=C[i],id=i;
	rep(i,1,n) if(i!=id && C[i]>m) Work(i);
	//cout<<"$"<<ans<<endl;
	rep(d,1,m) Solve(d);
	printf("%d\n",ans);
}