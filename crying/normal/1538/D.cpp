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
const int MAXN=1e4+10,LIM=1e5+10;
ll a,b,k,T;
ll prime[LIM],isprime[LIM],tot;
ll cnt[2][MAXN],rest[2],common,another;
void solve(){
	rep(i,2,1e5){
		if(!isprime[i]){
			prime[++tot]=i;
		}
		rep(j,1,tot){
			if(prime[j]*i>1e5)break;
			isprime[prime[j]*i]=1;
			if(i%prime[j]==0)break; 
		}
	}
}
int main(){
	solve();
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld%lld",&a,&b,&k);
		if(k==1){
			if(a!=b && (a%b==0 || b%a==0)){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
			continue;
		}
		rep(i,1,3500){
			cnt[0][i]=cnt[1][i]=0;
		}
		rep(i,1,3500){
			if(prime[i]*prime[i]>1e9)break;
			while((a%prime[i])==0){
				cnt[0][i]++;
				a/=prime[i];
			}
			while((b%prime[i])==0){
				cnt[1][i]++;
				b/=prime[i];
			}
		}
		rest[0]=a;rest[1]=b;
		common=another=0;
		rep(i,1,3500){
			common+=Min(cnt[0][i],cnt[1][i])*2;
			ll val=Min(cnt[0][i],cnt[1][i]);
			cnt[0][i]-=val;cnt[1][i]-=val;
			another+=(cnt[0][i]+cnt[1][i]);
		}
		if(rest[0]==rest[1]){
			if(rest[0]!=1)common+=2; 
		}else{
			another+=(bool)(rest[0]!=1);
			another+=(bool)(rest[1]!=1);
		}
		if(k>another+common){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
	}

	return 0;
}