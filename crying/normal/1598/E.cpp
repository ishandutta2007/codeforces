#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=1010;
ll n,m,q,x,y,ans,cnt;
ll f[MAXN][MAXN],a[MAXN][MAXN];
void calc(ll x,ll y,ll flag=1){
	if(x!=n){
		//down
		ll val=min(f[x][y],f[x+1][y]);
		ans+=flag*val;
		if(f[x][y]<=f[x+1][y]){
			ans+=flag*Max(0,f[x][y]-1);
		}else{
			ans+=flag*f[x+1][y];
		}
	}
	if(y!=m){
		//right
		ll val=min(f[x][y],f[x][y+1]);
		ans+=flag*val;
		if(f[x][y]<=f[x][y+1]){
			ans+=flag*Max(0,f[x][y]-1);
		}else{
			ans+=flag*f[x][y+1];
		}
	}
//	printf("%lld %lld %lld\n",x,y,ans);
}
void rec(ll x,ll y){
	if(a[x][y])cnt--;
	else cnt++;
	a[x][y]^=1;
	if(a[x][y])f[x][y]=1+f[x+1][y+1];
	else f[x][y]=0;	
}
void update(ll x,ll y,ll flag){
	ll u=x,v=y;
	while(u>=1 && v>=1){
		calc(u,v,flag);
		u--;v--;
	}
}
void update(ll x,ll y){
	update(x,y,-1);
	update(x-1,y,-1);
	update(x,y-1,-1);
	rec(x,y);
	ll u=x-1,v=y-1;
	while(u>=1 && v>=1){
		if(a[u][v])f[u][v]=1+f[u+1][v+1];
		else f[u][v]=0;
		u--;v--;
	}
	update(x,y,1);
	update(x-1,y,1);
	update(x,y-1,1);
}
int main(){
	cin>>n>>m>>q;
	cnt=n*m;
	rep(i,1,n)rep(j,1,m)a[i][j]=1;
	per(i,n,1)per(j,m,1){
		f[i][j]=1+f[i+1][j+1];
	}
	rep(i,1,n)rep(j,1,m){
		calc(i,j);
	}
//	cout<<ans<<endl;
	
	rep(i,1,q){
		cin>>x>>y;
		update(x,y);
		printf("%lld\n",ans+cnt);
	}
	
	return 0;
}