#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
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
const int MAXN=35,next_x[4]={1,0,-1,0},next_y[4]={0,1,0,-1},BASE=7*6*5*4*3*2*1;
char s[MAXN][MAXN],ret[MAXN][MAXN];
int n,m,tot,ans;
int tag[MAXN][MAXN],rest[MAXN],color[MAXN],state[MAXN][MAXN],cnt[MAXN][MAXN];
pi p[MAXN]; //2*2 
pi over[MAXN][MAXN]; //
void check(){
	rep(i,1,n)rep(j,1,m)state[i][j]=color[tag[i][j]];
	rep(i,1,7){rep(j,i,7)cnt[i][j]=0;}
	rep(i,1,n){
		rep(j,1,m){
			if(s[i][j]=='.')continue;
			int x=i,y=j,x2=over[x][y].fr,y2=over[x][y].se;
			cnt[Min(state[x][y],state[x2][y2])][Max(state[x][y],state[x2][y2])]++;
		}
	}
	rep(i,1,7)rep(j,i,7)if(cnt[i][j]!=2)return;
	ans++;
	if(ans==1){
		rep(i,1,n)rep(j,1,m){
			if(s[i][j]=='.')ret[i][j]='.';
			else ret[i][j]=state[i][j]-1+'0';
		}
	}
} 
void dfs(int u,int r){
	//r[1,r) 
	if(u==15){
		// 
		check();
		return;
	}
	rep(c,1,r-1){
		if(!rest[c])continue;
		color[u]=c;rest[c]--;
		dfs(u+1,r);rest[c]++;
	}
	if(r<=7){
		color[u]=r;rest[r]--;
		dfs(u+1,r+1);rest[r]++;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)rep(j,1,m)scanf(" %c",&s[i][j]);
	rep(i,1,n){
		rep(j,1,m){
			if(s[i][j]=='.')continue;
			rep(k,0,3){
				int cx=i+next_x[k],cy=j+next_y[k]; 
				if(s[cx][cy]==s[i][j])over[i][j]=mp(cx,cy);
			}
			if(tag[i][j])continue;tot++;
			p[tot]=mp(i,j);tag[i][j]=tag[i+1][j]=tag[i][j+1]=tag[i+1][j+1]=tot;
		}
	}
	rep(i,1,7)rest[i]=2;
	dfs(1,1);
	printf("%lld\n",(ll)ans*BASE);
	rep(i,1,n){
		rep(j,1,m)printf("%c",ret[i][j]);
		printf("\n");
	}
	return 0;
}