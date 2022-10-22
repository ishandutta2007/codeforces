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

const int N=2e6+10,INF=1e9+10;

int n;
int A[N],B[N],D[N],I[N],s[N];
int vis[N];
int m,t=0;

int Go(){
	rep(i,0,m) vis[i]=0;
	if(t==0) {
		rep(i,1,n) printf("%d ",A[i]);
		return 1;
	}
	rep(i,1,n) {
		vis[s[i-1]]=i;
		s[i]=(s[i-1]+D[I[i]])%m;
		if(vis[(s[i]+t)%m]) {
			int l=vis[(s[i]+t)%m];
			rep(j,1,l-1) printf("%d ",A[I[j]]);
			rep(j,l,i) printf("%d ",B[I[j]]);
			rep(j,i+1,n) printf("%d ",A[I[j]]);
			return 1;
		}
	}
	return 0;
}

int main(){
	srand(time(NULL));
	//freopen("test.in","r",stdin);
	n=rd();
	if(~n&1){
		puts("First");
		rep(i,1,n) printf("%d ",i);
		rep(i,1,n) printf("%d ",i);
		puts("");
	} else {
		puts("Second"),fflush(stdout);
		rep(i,1,n*2){
			int x=rd();
			if(!A[x]) A[x]=i;
			else B[x]=i;
		}
		m=2*n;
		rep(i,1,n) t=(t+A[i])%m,D[i]=(B[i]-A[i]+m)%m,I[i]=i;
		sort(I+1,I+n+1,[&](int x,int y){ return D[x]<D[y]; });
		if(!Go()) {
			sort(I+1,I+n+1,[&](int x,int y){ return D[x]%n<D[y]%n; });
			if(!Go()) {
				while(1) {
					random_shuffle(I+1,I+n+1);
					if(Go()) break;
				}
			}
		}
	}
	fflush(stdout),rd();
}