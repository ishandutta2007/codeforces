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
ll a[N],stk[N];
int pos[N],top;

int main(){
	rep(_,1,rd()) {
		n=rd();
		rep(i,1,n) a[i]=rd<ll>();
		rep(i,1,--n) a[i]=abs(a[i]-a[i+1]);
		int ans=0;
		top=0;
		rep(i,1,n) {
			rep(j,1,top) if(a[i]%stk[j]!=0) stk[j]=__gcd(a[i],stk[j]);
			while(top>1 && stk[top]==stk[top-1]) top--;
			if(stk[top]!=a[i]) stk[++top]=a[i],pos[top]=i;
			rep(j,1,top) if(stk[j]>1) cmax(ans,i-pos[j]+1);
		}
		printf("%d\n",ans+1);
	}
}