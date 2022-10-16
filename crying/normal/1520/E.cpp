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
const int MAXN=1e6+10;
ll T,n,val[MAXN];
char s[MAXN];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>(s+1);
		ll ans=0;
		ll cnt=0,tot=0;
		rep(i,1,n){
			if(s[i]=='.')continue;
			val[++tot]=i-cnt;
			cnt++;
		//	printf("%lld\n",val[tot]);
		}
		ll tgt=n-cnt+1;
		ll idx=(cnt+1)/2;
		if(val[idx]+cnt-1<=n)tgt=val[idx];
	//	printf("tgt:%lld\n",tgt);
		rep(i,1,tot){
			ans+=abs(val[i]-tgt);
		}
		cout<<ans<<endl;
	}

	return 0;
}
/*
5
6
**.*..
*/