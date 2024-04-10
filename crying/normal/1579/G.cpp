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
const int MAXN=1e4+10,MAXM=2e3+10;
int f[2][MAXM];
int t,n,a[MAXN];
int check(int x){
	rep(i,0,x)f[0][x]=f[1][x]=0;
	rep(i,0,x)f[0][i]=1;
	rep(i,0,n-1){
		rep(j,0,x){f[(i+1)&1][j]=0;}
		rep(j,0,x){
			if(!f[i&1][j])continue;
			if(j+a[i+1]<=x)f[(i+1)&1][j+a[i+1]]|=1;
			if(j-a[i+1]>=0)f[(i+1)&1][j-a[i+1]]|=1; 
		}
	} 
	rep(i,0,x)if(f[n&1][i])return 1;
	return false;
}
void solve(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);
	}
	int L=1,R=2000,ans=2000;
	while(L<=R){
		int mid=(L+R)>>1;
		if(check(mid)){
			ans=mid;
			R=mid-1;
		}else{
			L=mid+1;
		}
	}
	printf("%d\n",ans);
}
int main(){
	scanf("%d",&t);
	while(t--){
		solve();
	}

	return 0;
}