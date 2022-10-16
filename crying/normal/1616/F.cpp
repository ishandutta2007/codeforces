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
const int MAXM=300,MAXN=260*32;
int n,m,g[70][70],idx[70][70],T,cnt;
int ans[MAXM];
int a[MAXN][MAXM];
void Swap(int x,int y){
	rep(j,1,m+1){
		swap(a[x][j],a[y][j]);
	}
}
void Add(int x,int y,int k){
	rep(j,1,m+1){
		a[x][j]=(a[x][j]+a[y][j]*k)%3;
	}
}
void E(int i,int j){
	if(i>cnt || j>m)return;
	int k=0;
	rep(r,i,cnt){
		if(a[r][j]){
			k=r;break;
		}
	}
	if(!k){E(i,j+1);return;}
	Swap(i,k);
	if(a[i][j]==2)Add(i,i,1);
	rep(r,i+1,cnt){
		if(a[r][j]==0)continue;
		Add(r,i,3-a[r][j]);
	}
	E(i+1,j+1);
}
void C(){
	per(r,cnt,1){
		int pos=0;
		rep(j,1,m){
			if(a[r][j]!=0){
				pos=j;
				break;
			}
		}
		if(!pos && a[r][m+1]!=0){
			printf("-1\n");
			return;
		}
		if(pos){
			ans[pos]=a[r][m+1];
			rep(rr,1,r-1){
				a[rr][m+1]=(a[rr][m+1]-ans[pos]*a[rr][pos]%3+3)%3;
				a[rr][pos]=0;
			}
		}
	}
	rep(i,1,m)if(!ans[i])ans[i]=3;
	rep(i,1,m)printf("%d ",ans[i]);printf("\n");
}
void solve(){
	cin>>n>>m;
	memset(g,0,sizeof g);
	memset(idx,0,sizeof idx);
	memset(ans,0,sizeof ans);
	rep(i,1,m){
		int u,v,w;cin>>u>>v>>w;
		g[u][v]=g[v][u]=w;
		idx[u][v]=idx[v][u]=i;
		if(w!=-1)ans[i]=w;
	}
	cnt=0;
	rep(i,1,n)rep(j,i+1,n)rep(k,j+1,n){
		if(g[i][j] && g[i][k] && g[k][j]){
			cnt++;
			int sum=0;
			if(g[i][j]!=-1)sum+=g[i][j];
			if(g[i][k]!=-1)sum+=g[i][k];
			if(g[j][k]!=-1)sum+=g[j][k];
			sum=(-sum%3+3)%3;
			a[cnt][m+1]=sum;
			if(g[i][j]==-1)a[cnt][idx[i][j]]=1;
			if(g[i][k]==-1)a[cnt][idx[i][k]]=1;
			if(g[j][k]==-1)a[cnt][idx[j][k]]=1;
		}
	}
	/*
	rep(i,1,cnt){
		rep(j,1,m+1){
			printf("%d ",A(i,j));
		}
		printf("\n");
	}
	*/
//	output();
	E(1,1);
//	output();
	C();
	rep(i,0,cnt)rep(j,0,m+2)a[i][j]=0;
}
int main(){
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}