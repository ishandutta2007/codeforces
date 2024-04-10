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
const ll MAXN=3e5+10,INF=1e18; 
int T,n;
ll a[MAXN],s[MAXN];
int power[20],logn[MAXN];
ll minn[2][20][MAXN],ans;
vector<int>occ[MAXN];
map<ll,int>rk;
set<ll>val;
ll query(int mode,int L,int R){
	int len=logn[R-L+1];
	return min(minn[mode][len][L],minn[mode][len][R-power[len]+1]);
}
int query(int mode,int val,int L,int R){
	int sz=occ[val].size();
	if(!sz)return 0;
	if(occ[val][sz-1]<L)return 0;
	int pos=lower_bound(occ[val].begin(),occ[val].end(),L)-occ[val].begin();
	if(occ[val][sz-1]<=R)return sz-pos;
	int pos2=upper_bound(occ[val].begin(),occ[val].end(),R)-occ[val].begin();
	return pos2-pos;
}
void solve(){
	rk.clear();
	val.clear();
	ans=0;
	scanf("%d",&n);
	rep(i,1,n){scanf("%lld",&a[i]);}
	//+- 
	rep(i,1,n){
		s[i]=s[i-1];
		if(odd(i))s[i]+=a[i];
		else s[i]-=a[i];
		val.is(s[i]);
	}
	int cnt=0;
	for(auto u:val){
		cnt++;
		rk[u]=cnt;
	}
	rep(i,1,n)occ[rk[s[i]]].pb(i);
	//bulid st-table
	rep(i,1,n){
		minn[0][0][i]=minn[1][0][i]=INF;
		if(odd(i))minn[0][0][i]=s[i];
		else minn[1][0][i]=-s[i];
	}
	rep(k,0,1)rep(i,1,19)rep(j,1,n){
		if(j+power[i]-1>n)break;
		minn[k][i][j]=min(minn[k][i-1][j],minn[k][i-1][j+power[i-1]]);
	}
	rep(i,1,n){
		//
		int L=i,R=n,ret=-1;
		while(L<=R){
			int mid=(L+R)>>1;
			ll valL=query(0,i,mid),valR=query(1,i,mid);
			if(valL>=s[i-1] && valR>=-s[i-1]){
				ret=mid;
				L=mid+1;
			}else{
				R=mid-1;
			}
		}
		if(ret==-1)continue;
		ans+=query(0,rk[s[i-1]],i,ret);
	}
	printf("%lld\n",ans);
	//clear
	rep(i,1,n)occ[rk[s[i]]].clear();
}
int main(){
	power[0]=1;rep(i,1,19)power[i]=power[i-1]*2;
	logn[0]=-1;rep(i,1,3e5)logn[i]=logn[i>>1]+1; 
	scanf("%d",&T);
	while(T--){
		solve();
	}

	return 0;
}