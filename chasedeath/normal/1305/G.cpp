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

const int N=1<<18,INF=1e9+10;

int n,a[N],F[N];
ll ans;
int Find(int x){ return F[x]==x?x:F[x]=Find(F[x]); }

int main(){
	n=rd();
	rep(i,1,n) {
		int x=rd();
		a[x]++,ans-=x;
	}
	a[0]++;
	rep(i,0,N-1) F[i]=i;
	drep(i,N-1,1) {
		for(int S=i,T;(S^i)<=S;S=(S-1)&i) if(a[S] && a[T=S^i] && Find(S)!=Find(T)) {
			ans+=1ll*(a[S]+a[T]-1)*i;
			a[S]=a[T]=1,F[Find(S)]=Find(T);
		}
	}
	printf("%lld\n",ans);
}