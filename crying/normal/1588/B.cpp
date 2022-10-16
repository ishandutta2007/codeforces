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
ll T,n,sum;
map<ll,int>f;
void solve(){
	cin>>n;
	cout<<"? "<<1<<" "<<n<<endl;
	cin>>sum;
	ll L=1,R=n,ret=0;
	while(L<=R){
		ll mid=(L+R)>>1;
		cout<<"? "<<mid<<" "<<n<<endl;
		ll tmp;cin>>tmp;
		if(tmp==sum){
			ret=mid;
			L=mid+1;
		}else{
			R=mid-1;
		}
	}
	ll i=ret;
	cout<<"? "<<i+1<<" "<<n<<endl;
	ll tmp;cin>>tmp;
	tmp=sum-tmp;
	ll j=i+tmp+1,k;
	sum-=tmp*(tmp+1)/2;
//	printf("sum:%lld\n",sum);
	L=1,R=n,ret=0;
	while(L<=R){
		ll mid=(L+R)>>1;
		if(mid*(mid+1)/2==sum){
			ret=mid;break;
		}else if(mid*(mid+1)/2<sum){
			L=mid+1;
		}else{
			R=mid-1;
		}
	}
	k=j+ret;
	cout<<"! "<<i<<" "<<j<<" "<<k<<endl;
}
int main(){
	cin>>T;
	while(T--){
		solve();
	}

	return 0;
}