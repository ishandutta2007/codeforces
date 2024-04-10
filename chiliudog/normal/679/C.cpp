#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef vector<int> vin;
typedef vector<i64> v64;
typedef pair<int,int> pin;
#define mk(a,b) make_pair(a,b)
#define lowbit(x) ((x)&(-(x)))
#define sqr(a) ((a)*(a))
#define clr(a) (memset((a),0,sizeof(a)))
#define ls(x) ((x)<<1)
#define rs(x) (((x)<<1)|1)
#define pb push_back
#define w1 first
#define w2 second
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
/*******************************head*******************************/
const int maxn=505;
char s[maxn][maxn];
int k,n,a[maxn][maxn],tot=0;
int sz[maxn*maxn],nd[maxn][maxn];
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
inline int dfs(int x,int y,int cnt){
	nd[x][y]=cnt;int res=1;
	rep(i,0,3){
		int tx=x+dx[i],ty=y+dy[i];
		if(tx<1||tx>n||ty<1||ty>n)continue;
		if(nd[tx][ty])continue;
		if(!a[tx][ty])continue;
		res+=dfs(tx,ty,cnt);
	}return res;
}
int app[maxn*maxn];
int ans=0;
inline void add(int x,int y){
	if(a[x][y]){
		if(app[nd[x][y]]==0)ans+=sz[nd[x][y]];
		app[nd[x][y]]++;
		return;
	}ans++;
	rep(i,0,3){
		int tx=x+dx[i],ty=y+dy[i];
		if(tx<1||tx>n||ty<1||ty>n)continue;
		if(!nd[tx][ty])continue;
		if(app[nd[tx][ty]]==0)ans+=sz[nd[tx][ty]];
		app[nd[tx][ty]]++;
	}
}
inline void dec(int x,int y){	
	if(a[x][y]){
		if(app[nd[x][y]]==1)ans-=sz[nd[x][y]];
		app[nd[x][y]]--;
		return;
	}ans--;
	rep(i,0,3){
		int tx=x+dx[i],ty=y+dy[i];
		if(tx<1||tx>n||ty<1||ty>n)continue;
		if(!nd[tx][ty])continue;
		if(app[nd[tx][ty]]==1)ans-=sz[nd[tx][ty]];
		app[nd[tx][ty]]--;
	}

}
int main(){
	read(n);read(k);
	rep(i,1,n)scanf("%s",s[i]+1);
	rep(i,1,n)rep(j,1,n)if(s[i][j]=='.')a[i][j]=1;
	rep(i,1,n)rep(j,1,n){
		if((!a[i][j])||nd[i][j])continue;tot++;
		sz[tot]=dfs(i,j,tot);
	}int res=0;//cerr<<tot<<endl;
	rep(i,1,n-k+1){
		rep(x,1,k)rep(j,1,k)
			add(i+x-1,j);
		res=max(res,ans);
		rep(j,k+1,n){
			rep(x,1,k)
				add(i+x-1,j),dec(i+x-1,j-k);
			res=max(res,ans);
		}
		rep(x,1,k)rep(j,n-k+1,n)
			dec(i+x-1,j);
	}
	cout<<res<<endl;
	return 0;
}