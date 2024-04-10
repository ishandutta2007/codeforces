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
const int MAXN=5e5+10,INF=1e9;
int T,n,a[MAXN],lim,dp[MAXN];
int sum[MAXN][2];
char tmp;
il pi calc(int L,int R){
	return mp(sum[R][0]-sum[L-1][0],sum[R][1]-sum[L-1][1]);
}
bool operator==(const pi& p1,const pi& p2){
	return ((ll)p1.fr*p2.se)==((ll)p1.se*p2.fr);
}
ll gcd(ll a,ll b){
	if(!b)return a;
	return gcd(b,a%b);
}
il pi Easy(const pi& p){
	int a=p.fr,b=p.se;
	if(!b)return mp(INF,INF);
	int G=gcd(a,b);
	return mp(a/G,b/G);
}
map<pi,int>f;
int main(){
	cin>>T;
	while(T--){
		f.clear();
		cin>>n;lim=n;
		sum[0][0]=sum[0][1]=0;
		rep(i,1,n){
			cin>>tmp;
			sum[i][0]=sum[i-1][0];
			sum[i][1]=sum[i-1][1];
			if(tmp=='D')a[i]=0,sum[i][0]++;
			else a[i]=1,sum[i][1]++;
		}
		rep(i,1,lim){
			pi val=calc(1,i);
			val=Easy(val);
		//	printf("%d,%d\n",val.fr,val.se);
			int j=f[val];
		//	printf("j:%d\n",j);
			dp[i]=dp[f[val]]+1;
			
			f[val]=i;
		}
		
		rep(i,1,n)printf("%d ",dp[i]);
		printf("\n");
	}

	return 0;
}