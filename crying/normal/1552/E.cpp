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
const int MAXN=110,MAXM=1e4+10;
int n,k,c[MAXM],occ[MAXN][MAXN];
int ans[MAXN][2],vis[MAXM];
vector<pi>t;
int main(){
	cin>>n>>k;
	rep(i,1,n*k){
		cin>>c[i];
		occ[c[i]][++occ[c[i]][0]]=i;
	}
	ll rest=n;
	rep(i,1,k-1){
		ll cnt=Min(rest,(n+k-2)/(k-1));
		t.clear();
		rep(j,1,n){
			if(vis[j])continue;
			t.pb(mp(occ[j][i+1],j));
		}
		sort(t.begin(),t.end());
		rep(j,0,cnt-1){
			ll color=t[j].se;
			vis[color]=1;
			ans[color][0]=occ[color][i];
			ans[color][1]=occ[color][i+1];
		}
	}
	rep(i,1,n){
		printf("%d %d\n",ans[i][0],ans[i][1]);
	}
	return 0;
}