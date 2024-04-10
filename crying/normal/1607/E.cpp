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
const int MAXN=1e6+10,INF=1e9;
int t,n,m,len;
int sum[MAXN][2],maxn[MAXN][2],minn[MAXN][2];
char s[MAXN];
void solve(){
	scanf("%d%d%s",&n,&m,s+1);
	len=strlen(s+1);
	maxn[0][0]=maxn[0][1]=-INF;
	minn[0][0]=minn[0][1]=INF;
	rep(i,1,len){
		sum[i][0]=sum[i-1][0];sum[i][1]=sum[i-1][1];
		if(s[i]=='L')sum[i][0]--;
		else if(s[i]=='R')sum[i][0]++;
		else if(s[i]=='U')sum[i][1]--;
		else sum[i][1]++;
		maxn[i][0]=max(maxn[i-1][0],sum[i][0]);
		minn[i][0]=min(minn[i-1][0],sum[i][0]);
		maxn[i][1]=max(maxn[i-1][1],sum[i][1]);
		minn[i][1]=min(minn[i-1][1],sum[i][1]);
	}
	int ans=0;
	rep(i,1,len){
		int L=max(0,-minn[i][0]),R=max(0,maxn[i][0]),U=max(0,-minn[i][1]),D=max(0,maxn[i][1]);
		if(L+R>=m || U+D>=n)break;
		ans=i;
	}
	int L=max(0,-minn[ans][0]),U=max(0,-minn[ans][1]);
	printf("%d %d\n",U+1,L+1);
}
int main(){
	scanf("%d",&t);
	while(t--){
		solve();
	}

	return 0;
}