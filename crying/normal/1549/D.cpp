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
ll T,n,a[MAXN],ans,d[MAXN];
ll st[MAXN][20];
ll power[20],logn[MAXN];
ll gcd(ll a,ll b){
	if(!b)return a;
	return gcd(b,a%b);
}
il ll query(ll L,ll R){
	ll len=R-L+1;
	len=logn[len];
	return gcd(st[L][len],st[R-power[len]+1][len]); 
}
int main(){
	power[0]=1;
	rep(i,1,19)power[i]=power[i-1]*2;
	rep(i,1,2e5){
		logn[i]=logn[i-1];
		if(power[logn[i]+1]==i){
			logn[i]++;
		}
	}
	cin>>T;
	while(T--){
		cin>>n;
		rep(i,1,n){
			cin>>a[i];
		}
		if(n==1){
			printf("1\n");
			continue;
		}
		rep(i,1,n-1){
			d[i]=a[i+1]-a[i];
			d[i]=abs(d[i]);
			st[i][0]=d[i];
		}
		rep(j,1,19){
			rep(i,1,n-1){
				if(i+power[j]-1>=n)break;
				st[i][j]=gcd(st[i][j-1],st[i+power[j-1]][j-1]);
			//	if(j<=2)printf("st[%d][%d]:%lld\n",i,j,st[i][j]);
			}
		}
		ll ans=1;
		rep(i,1,n-1){
			ll L=i,R=n-1,ret=0;
			while(L<=R){
				ll mid=(L+R)>>1;
				if(query(i,mid)!=1){
					ret=mid-i+2;
					L=mid+1;
				}else{
					R=mid-1;
				}
			}
		//	printf("i:%lld ret:%lld\n",i,ret);
			ans=Max(ans,ret); 
		}
		
	//	printf("TMP:%lld\n",query(3,4));
		cout<<ans<<endl;
	}

	return 0;
}
/*
1
5
1 5 2 4 6

8
465 55 3 54 234 12 45 78
*/