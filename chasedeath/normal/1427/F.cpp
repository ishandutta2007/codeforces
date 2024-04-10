#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
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

const int N=1210,INF=1e9+10;

int n;

struct Node{ int k,a,b,c; };
typedef vector <Node> V;

int A[N],S[N],I[N],T;
Node B[N];
int C;
int X[2][N],ind[N],R[2],F[N];
void Check(int i){ if(!ind[i]) X[B[i].k][++R[B[i].k]]=i; }

int main(){
	n=rd()*6;
	rep(i,1,n) A[i]=1;
	rep(i,1,n/2) A[rd()]=0;
	rep(i,1,n) {
		S[++T]=i;
		I[T]=(T==1 || A[S[T-1]]!=A[S[T]])?++C:I[T-1];
		//cout<<"Ins "<<i<<' '<<T<<' '<<I[T]<<endl;
		if(T>2 && A[S[T]]==A[S[T-1]] && A[S[T]]==A[S[T-2]]) {
			int u=I[T];
			B[u]=(Node){A[S[T]],S[T-2],S[T-1],S[T]};
			ind[F[u]=I[T-=3]]++;
		}
	}
	//rep(i,1,C) cout<<"$"<<B[i].a<<' '<<B[i].b<<' '<<B[i].c<<' '<<F[i]<<endl;
	rep(i,1,C) Check(i);
	rep(i,1,n/6) {
		rep(j,0,1) {
			if(!F[X[1][R[1]]]) swap(X[1][R[1]],X[1][1]);
			int u=X[j][R[j]--];
			printf("%d %d %d\n",B[u].a,B[u].b,B[u].c);
			if(F[u]) --ind[F[u]],Check(F[u]);
		}
	}
}