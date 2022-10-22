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
int F[N],R[N],stk[N],top;
int Find(int x){ return !F[x]?x:F[x]=Find(F[x]); }

bool Med;
int main() {
	n=rd(),m=rd();
	rep(i,1,n+1) R[i]=INF;
	rep(i,1,m) {
		int o=rd();
		if(!o) {
			int l=rd(),r=rd();
			if(!rd()) { 
				l=Find(l),r=Find(r+1);
				while(l<r) F[l]=r,cmin(R[r],R[l]),l=Find(l+1);
			} else cmin(R[Find(l)],r);
		} else {
			int p=rd();
			if(F[p]) puts("NO");
			else {
				if(Find(p+1)>R[p]) puts("YES");
				else puts("N/A");
			}
		}
	}
}