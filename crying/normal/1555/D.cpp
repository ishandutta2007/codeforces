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
const int MAXN=2e5+10;
ll n,m,q,l,r;
char s[MAXN];
ll sum[MAXN][3][3];
ll query(ll L,ll R,ll kind,ll ch){
	return sum[R][kind][ch]-sum[L-1][kind][ch];
}
void solve(ll L,ll R){
	ll ans=1e9;
	if(L==R){
		printf("0\n");
		return;
	}else if(L==R-1){
		if(s[L] == s[R])printf("1\n");
		else printf("0\n");
		return;
	}
	rep(i,0,2)rep(j,0,2)rep(k,0,2){
		if(i==j || i==k  || j==k)continue;
		ll ret=0;
		ret+=query(L,R,L%3,j)+query(L,R,L%3,k);
		ret+=query(L,R,(L+1)%3,i)+query(L,R,(L+1)%3,k);
		ret+=query(L,R,(L+2)%3,i)+query(L,R,(L+2)%3,j); 
		ans=Min(ans,ret);
	}
	printf("%lld\n",ans);
}
int main(){
	cin>>n>>q>>(s+1);
	rep(i,1,n){
		rep(j,0,2)rep(k,0,2)sum[i][j][k]=sum[i-1][j][k];
		sum[i][i%3][s[i]-'a']++;
	}
	rep(i,1,q){
		cin>>l>>r;
		solve(l,r);
	}

	return 0;
}