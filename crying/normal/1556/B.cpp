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
ll T,n,a[MAXN],b[MAXN],ans;
ll pos[MAXN];
ll solve(){
	ll tot=0,num=0,ans=0;
	rep(i,1,n){
		if(b[i]==0)pos[++tot]=i;
	}
	rep(i,1,n){
		if(a[i]==0){
			num++;
			ans+=abs(pos[num]-i);
		}
	}
	return ans;
}
int main(){
	cin>>T;
	while(T--){
		cin>>n;ans=1e18;
		ll cnt1=0,cnt2=0;
		rep(i,1,n){
			cin>>a[i];
			a[i]=even(a[i]);
			if(a[i])cnt1++;
			else cnt2++;
		}
		if(even(n)){
			if(cnt1!=cnt2){
				printf("-1\n");continue;
			}
			rep(i,1,n){
				b[i]=even(i);
			}
			ans=min(ans,solve());
			rep(i,1,n){
				b[i]=odd(i);
			}
			ans=min(ans,solve());
		}else{
			if(abs(cnt1-cnt2)!=1){
				printf("-1\n");continue;
			}
			if(cnt1>cnt2)rep(i,1,n)b[i]=odd(i);
			else rep(i,1,n)b[i]=even(i);
			ans=min(ans,solve());
		}
		printf("%lld\n",ans);
	}

	return 0;
}