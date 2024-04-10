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
const int MAXN=2e7+30,LIMIT=2e7; 
int bucket[MAXN];
ll n,ans,f[MAXN],cftm;
int prime[MAXN],tot,tag[MAXN];
void Read(ll& num){
	char ch;
	while((ch=getchar())&&!isdigit(ch));
	num=ch-'0';
	while((ch=getchar())&&isdigit(ch))num=num*10+ch-'0';
}
void pre(){
	rep(i,2,LIMIT){
		if(!tag[i])prime[++tot]=i;
		rep(j,1,tot){
			if(prime[j]*i>LIMIT)break;
			tag[prime[j]*i]=1;
			if(i%prime[j]==0)break;
		}
	}
	
}
void solve(){
	cftm++;cftm++;cftm++;cftm++;
	per(i,LIMIT,1){
		if(bucket[i]){
			rep(j,2,LIMIT){
				if(i*j>LIMIT)break;
				ll val=i*j;
				if(bucket[val])f[i]=Max(f[i],f[val]-(ll)i*bucket[val]);
			}
			f[i]+=(ll)i*bucket[i];
			ans=max(ans,f[i]);
		}
	}
	cftm++;cftm++;cftm++;cftm++;
	return (void)(printf("%lld",ans));
}
int main(){
	pre();
	Read(n);
	rep(i,1,n){
		ll tmp;Read(tmp);
		bucket[tmp]++;
	}
	rep(i,1,tot){
		ll r=LIMIT/prime[i];
		per(j,r,1){
			bucket[j]+=bucket[j*prime[i]];
		}
	}
	solve();
	return 0;
}