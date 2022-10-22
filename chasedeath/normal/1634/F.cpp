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

bool Mbe;
const int N=1e6+10,INF=1e9+10;

int n,m,q;
char op[3];
int A[N],F[N];
int cnt;
void Add(int i,int x) {
	if(i>n) return;
	cnt-=!!A[i];
	A[i]=(A[i]+x)%m;
	cnt+=!!A[i];
}

bool Med;
int main() {
	//fprintf(stderr,"%.2lf\n",(&Med-&Mbe)/1024.0/1024.0);
	n=rd(),q=rd(),m=rd();
	rep(i,1,n) A[i]=rd();
	rep(i,1,n) A[i]=(A[i]-rd())%m;
	F[0]=F[1]=1;
	rep(i,2,n) F[i]=(F[i-1]+F[i-2])%m;
	drep(i,n,2) A[i]=(0ll+A[i]-A[i-1]-A[i-2])%m;
	rep(i,1,n) cnt+=!!A[i];
	while(q--) {
		scanf("%s",op);
		int k=*op=='A'?1:-1,l=rd(),r=rd();
		Add(l,k);
		Add(r+1,-k*F[r+1-l]);
		Add(r+2,-k*F[r-l]);
		puts(cnt?"NO":"YES");
	}
}