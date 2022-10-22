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

int n,m;
ll s[N],a[N];

ll Check(int n,ll s,ll lim) {
	// max ;
	if(s>lim*n) return 0;
	return 1;
}

bool Med;
int main() {
	fprintf(stderr,"%.2lf\n",(&Med-&Mbe)/1024.0/1024.0);
	rep(_,1,rd()) {
		n=rd(),m=rd();
		rep(i,n-m+1,n) s[i]=rd();
		if(m==1) {
			puts(Check(n,s[n],1e9)?"Yes":"No");
			continue;
		}
		rep(i,n-m+2,n) {
			a[i]=s[i]-s[i-1];
		}
		int f=1;
		rep(i,n-m+3,n) f&=a[i]>=a[i-1];
		if(!f) { puts("No"); continue; }
		puts(Check(n-m+1,s[n-m+1],a[n-m+2])?"Yes":"No");
	}
}