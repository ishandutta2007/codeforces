#include<bits/stdc++.h> 
using namespace std;

#define reg register
typedef long long ll;
typedef unsigned int ui;
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)

#define pb push_back
template <class T> inline void cmin(T &a,T b){ if(a>b) a=b; }
template <class T> inline void cmax(T &a,T b){ if(a<b) a=b; }

char IO;
int rd(){
	int s=0;
	int f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=1010,P=998244353;

int n,m,a[N];
int c[N],g[N][N];
int gcd(int a,int b){ return b==0?a:gcd(b,a%b); }
int pri[N],pc;
int p[N],mk[20];


int main(){
	rep(i,1,N-1) rep(j,1,N-1) g[i][j]=gcd(i,j);
	rep(i,2,sqrt(1000)) {
		int fl=1;
		rep(j,2,i-1) if(i%j==0) {
			fl=0;
			break;
		}
		if(fl) pri[++pc]=i;
	}
	rep(kase,1,rd()) {
		n=rd();
		rep(i,1,n) a[i]=rd();
		memset(mk,0,sizeof mk);
		rep(i,1,n) rep(j,1,pc) if(a[i]%pri[j]==0) {
			mk[p[i]=j]=1;
			break;
		}
		m=0;
		rep(i,1,pc) if(mk[i]) mk[i]=++m;
		printf("%d\n",m);
		rep(i,1,n) printf("%d ",mk[p[i]]); puts("");
	}
}