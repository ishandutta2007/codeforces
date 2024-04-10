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

const int N=1e6+10;
const ll INF=1e18+10;

int n;
ll k,F[N],G[N];
int A[N];

int main(){
	F[0]=G[0]=1;
	rep(i,1,N-1) {
		F[i]=G[i-1];
		G[i]=min(INF,G[i-1]+F[i]);
	}
	rep(_,1,rd()) {
		n=rd(),k=rd<ll>();
		if(k>F[n]){ puts("-1"); continue; }
		rep(i,1,n) A[i]=i;
		rep(i,1,n) {
			int p=i;
			while(F[n-p]<k) k-=F[n-p],p++;
			reverse(A+i,A+p+1);
			i=p;
		}
		rep(i,1,n) printf("%d ",A[i]);
		puts("");
	}
}