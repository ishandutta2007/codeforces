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
const int MAXN=1e6+10,INF=1e9,tag=1e9+1;
int T,n,p[MAXN];
int f[MAXN][2][2];
pi pre[MAXN][2][2];
void upd(int& x,int y,pi& a,pi b){
	if(x==tag)x=y,a=b;
	else if(x>y)x=y,a=b;
}
void construct(int n,int i,int j){
	int val=(i?-p[n]:p[n]);
	if(n==1){
		printf("%d ",val);return;
	}
	construct(n-1,pre[n][i][j].fr,pre[n][i][j].se);
	printf("%d ",val);
}
void solve(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&p[i]);
	rep(i,0,n+1)rep(j,0,1)rep(k,0,1)f[i][j][k]=tag;
	f[1][0][0]=f[1][1][0]=-INF;
	rep(i,1,n-1)rep(j,0,1)rep(k,0,1){
		if(f[i][j][k]==tag)continue;
		int x,y;
		if(k==0){
			x=(j?-p[i]:p[i]);
			y=f[i][j][k];
		}else{
			y=(j?-p[i]:p[i]);
			x=f[i][j][k];
		}
		rep(flag,0,1){
			int val=(flag?-p[i+1]:p[i+1]);
			if(val>x){
				upd(f[i+1][flag][0],y,pre[i+1][flag][0],mp(j,k));
			}else if(val>y){
				upd(f[i+1][flag][1],x,pre[i+1][flag][1],mp(j,k));
			}
		}
	} 
	rep(i,0,1)rep(j,0,1){
		if(f[n][i][j]!=tag){
			printf("YES\n");
			construct(n,i,j);printf("\n");
			return;
		}
	}
	printf("NO\n");
}
int main(){
	scanf("%d",&T);
	while(T--){
		solve();
	}

	return 0;
}