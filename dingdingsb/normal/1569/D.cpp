#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
typedef long long ll;
#define fi first
#define se second
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
const int N=1e6+1000;
int t;
int n,m,k;
map<int,bool>X,Y;
int x[N],y[N];
vector<int>A[N],B[N];
void solve(){
	X.clear();Y.clear();
	read(n,m,k);
	for(int i=1;i<=n;i++)read(x[i]),X[x[i]]=1,A[i].clear();
	for(int i=1;i<=m;i++)read(y[i]),Y[y[i]]=1,B[i].clear();
	for(int i=1,xx,yy;i<=k;i++){
		read(xx,yy);
		if(X[xx]&&Y[yy])continue;
		if(X[xx])
			B[lower_bound(y+1,y+1+m,yy)-y-1].pb(xx);
		else
			A[lower_bound(x+1,x+1+n,xx)-x-1].pb(yy);
	}
	ll ans=0;
	for(int i=1;i<n;i++){
		sort(A[i].begin(),A[i].end());
		for(int j=0;j<A[i].size();){
			int k=j;
			while(k+1<A[i].size()&&A[i][j]==A[i][k+1])k++;
			ans+=1ll*j*(k-j+1);
			j=k+1;
		}
	}
	for(int i=1;i<m;i++){
		sort(B[i].begin(),B[i].end());
		for(int j=0;j<B[i].size();){
			int k=j;
			while(k+1<B[i].size()&&B[i][j]==B[i][k+1])k++;
			ans+=1ll*j*(k-j+1);
			j=k+1;
		}
	}
	write(ans);putchar('\n');
}
signed main(){
	read(t);
	while(t--)solve();
}