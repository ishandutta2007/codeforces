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

const int N=1e5+10,INF=1e9+10;

int n,m,s;
ll t;
int a,b;
int Go(int s,ll t){ return s<m?(s+t)%n:((s-t)%n+n)%n; }
int I[N],P[N];

int main(){
	n=rd(),m=rd(),s=rd()-1,t=rd<ll>();
	while(t%n) s=Go(s,t--);
	if(!t) return printf("%d\n",s+1),0;
	int c=0;
	while(t) {
		rep(i,0,n-1) s=Go(s,t--);
		P[++c]=s;
		if(I[s]) {
			t=(t/n)%(c-I[s]);
			s=P[I[s]+t];
			t=0;
		}
		I[s]=c;
	}
	printf("%d\n",s+1);
}