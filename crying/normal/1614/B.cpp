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
const int MAXN=2e5+10;
pi a[MAXN];
ll T,ans,n,p[MAXN];
void solve(){
	ans=0;cin>>n;
	rep(i,1,n)cin>>a[i].fr,a[i].se=i;
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	p[0]=0;
	rep(i,1,n){
		ll& val=p[a[i].se];
		if(odd(i))val=((even(i))?i/2:i/2+1);
		else val=-i/2;
		ans+=a[i].fr*2*abs(val);
	}
	cout<<ans<<endl;
	rep(i,0,n)printf("%lld ",p[i]);
	printf("\n");
	
}
int main(){
	cin>>T;
	while(T--){
		solve();
	}

	return 0;
}