#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
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
ll t,a,b,k;
ll gcd(ll a,ll b){
	if(!b)return a;
	return gcd(b,a%b);
}
int main(){
	cin>>t;
	while(t--){
		cin>>a>>b>>k;
		if(k==1){printf("REBEL\n");continue;}
		if(a>b)swap(a,b);
		ll t=gcd(a,b);a/=t,b/=t;
		if((k-1)*a+1>=b){
			printf("OBEY\n");
		}else{
			printf("REBEL\n");
		}
	}
	return 0;
}