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
const int MAXN=1e5+10;
int n,q,l,r;
ll a[MAXN],b[MAXN],c[MAXN],d[MAXN];
ll power[20],logn[MAXN];
struct ST{
	ll minn[MAXN][20],maxn[MAXN][20];
	void build(){
		rep(i,1,n)minn[i][0]=maxn[i][0]=d[i];
		rep(j,1,19){
			rep(i,1,n){
				if(i+power[j]-1>n)break;
				minn[i][j]=min(minn[i][j-1],minn[i+power[j-1]][j-1]);
				maxn[i][j]=max(maxn[i][j-1],maxn[i+power[j-1]][j-1]);
			}
		}
	}
	ll querymin(int l,int r){
		int len=logn[r-l+1];
		return min(minn[l][len],minn[r-power[len]+1][len]);
	}
	ll querymax(int l,int r){
		int len=logn[r-l+1];
		return max(maxn[l][len],maxn[r-power[len]+1][len]);
	}
}st;
int main(){
	power[0]=1;rep(i,1,19)power[i]=power[i-1]*2;
	logn[0]=-1;rep(i,1,1e5)logn[i]=logn[i>>1]+1;
	scanf("%d%d",&n,&q);
	rep(i,1,n){
		scanf("%lld",&a[i]);
	}
	rep(i,1,n){
		scanf("%lld",&b[i]);
	}
	rep(i,1,n){
		c[i]=b[i]-a[i];
		d[i]=d[i-1]+c[i];
	}
	st.build();
	rep(i,1,q){
		scanf("%d%d",&l,&r);
		if(d[r]-d[l-1]!=0){
			printf("-1\n");
			continue;
		}
		ll minn=st.querymin(l,r),maxn=st.querymax(l,r);
		minn-=d[l-1];maxn-=d[l-1];
		if(minn<0){
			printf("-1\n");
			continue;
		}
		printf("%lld\n",maxn);
	}

	return 0;
}