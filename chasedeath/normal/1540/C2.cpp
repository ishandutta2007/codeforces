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
const int N=110,INF=1e9+10,P=1e9+7;

int n;
int c[N],b[N],t[N];
int dp[N][N*N];
int res[N*2];

int main() { 
	n=rd();
	rep(i,1,n) c[i]=rd();
	rep(i,2,n) b[i]=b[i-1]+rd(),t[i]=t[i-1]+b[i];
	//rep(i,1,n) cout<<t[i]<<' '; puts("");
	db _l=1e18,_r=1e18; int s=0;
	rep(i,1,n) {
		cmin(_l,-1.0*t[i]/i);
		s+=c[i],cmin(_r,1.0*(s-t[i])/i);
	}
	int l=floor(_l),r=floor(_r);
	rep(x,l,r) {
		dp[0][0]=1;
		int s=0,f=1;
		//cout<<"! "<<x<<endl;
		rep(i,1,n) {
			int a=max(0,t[i-1]+(i-1)*x),b=max(0,t[i]+i*x);
			if(b>s+c[i]) { f=0; break; }
			if(b) dp[i][b-1]=0;
			rep(j,b,s+c[i]) {
				int l=max(a,j-c[i]),r=min(j,s);
				if(l>r) dp[i][j]=0;
				else dp[i][j]=dp[i-1][r]-(l?dp[i-1][l-1]:0),Mod2(dp[i][j]);
				if(j) dp[i][j]+=dp[i][j-1],Mod1(dp[i][j]);
				//cout<<"#"<<i<<' '<<j<<' '<<dp[i][j]<<endl;
			}
			s+=c[i];
		}
		if(f) res[x-l]=dp[n][s];
	}
	rep(_,1,rd()) {
		int x=rd();
		if(x>r) puts("0");
		else printf("%d\n",res[max(0,x-l)]);
	}
}