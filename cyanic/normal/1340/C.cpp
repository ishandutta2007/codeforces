#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define P(x) ((x)%SZ)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=10005,M=1005,SZ=N*M,inf=2e9;
int f[N][M],d[N],q[SZ][2],stk[SZ][2],L,R,top;
int n,m,g,r;

int main(){
	read(n),read(n);
	rep(i,1,n) read(d[i]);
	sort(d+1,d+n+1);
	read(g),read(r);
	memset(f,0x7f,sizeof f);
	q[R][0]=0,q[R++][1]=0,f[0][0]=0;
	while(top||L<R){
		int x=0,y=0;
		if(top) x=stk[top][0],y=stk[top--][1];
		else x=q[P(L)][0],y=q[P(L++)][1];
		if(1<x){
			int dis=d[x]-d[x-1];
			if(y+dis<g&&f[x][y]<f[x-1][y+dis]){
				stk[++top][0]=x-1;
				stk[top][1]=y+dis;
				f[x-1][y+dis]=f[x][y];
			}
			else if(y+dis==g&&f[x][y]+1<f[x-1][0]){
				q[P(R)][0]=x-1;
				q[P(R++)][1]=0;
				f[x-1][0]=f[x][y]+1;
				f[x-1][g]=f[x][y];
			}
		}
		if(x<n){
			int dis=d[x+1]-d[x];
			if(y+dis<g&&f[x][y]<f[x+1][y+dis]){
				stk[++top][0]=x+1;
				stk[top][1]=y+dis;
				f[x+1][y+dis]=f[x][y];
			}
			else if(y+dis==g&&f[x][y]+1<f[x+1][0]){
				q[P(R)][0]=x+1;
				q[P(R++)][1]=0;
				f[x+1][0]=f[x][y]+1;
				f[x+1][g]=f[x][y];
			}
		}
	}
	ll ans=(ll)inf*inf;
	rep(i,0,g) if(f[n][i]<inf)
		ans=min(ans,(ll)(g+r)*f[n][i]+i);
	if(ans==(ll)inf*inf) puts("-1");
	else cout<<ans<<endl;
	return 0;
}