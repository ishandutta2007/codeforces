
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
const int MAXN=2e5+10,MAXK=(1<<17);
int n,k,ans;
int sum[MAXN][27];
int nxt[MAXN][17],f[MAXK]; 
char s[MAXN];
il int check(int L,int R,int k){
	//[L,R]k
	return (sum[R][26]-sum[L-1][26])+(sum[R][k]-sum[L-1][k])==(R-L+1);
}
il int check(int mid){
	rep(i,0,k-1)nxt[n+1][i]=n+1;
	per(i,n,1){
		rep(j,0,k-1)nxt[i][j]=nxt[i+1][j];
		if(i+mid-1>n)continue;
		rep(j,0,k-1){
			if(check(i,i+mid-1,j))nxt[i][j]=i+mid-1;
	//		printf("nxt[%d][%d]:%d\n",i,j,nxt[i][j]);
		}
	}
	f[0]=0;
	rep(i,1,(1<<k)-1)f[i]=n+1;
	rep(i,0,(1<<k)-1){
		if(f[i]>n)continue;
	//	printf("f[%d]:%d\n",i,f[i]);
		rep(j,0,k-1){
			if(i & (1<<j))continue;
			f[i | (1<<j)]=Min(f[i | (1<<j)],nxt[f[i]+1][j]);
		}
	}
	
	return f[(1<<k)-1]<=n;
}
int main(){
	cin>>n>>k>>(s+1);
	rep(i,1,n){
		rep(j,0,26)sum[i][j]=sum[i-1][j];
		if(s[i]=='?')sum[i][26]++;
		else sum[i][s[i]-'a']++; 
	}
	int L=1,R=n,ret=0;
	while(L<=R){
		int mid=(L+R)>>1;
		if(check(mid)){
			ans=mid;
			L=mid+1;
		}else{
			R=mid-1;
		}
	}
	printf("%d",ans);
	return 0;
}