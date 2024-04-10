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
ll a,b,ans=1e18;
int d1[(int)1.5e7+10],d2[(int)1.5e7+10];
int check(ll x,ll y){
	ll val=d1[x];
	if(a/val<=y)return 1;
	val=d2[x];
	if(b/val<=y)return 1;
	return 0; 
}
int main(){
	cin>>a>>b;
	d1[1]=d2[1]=1;
	rep(i,1,1.5e7){
		d1[i]=d1[i-1];
		d2[i]=d2[i-1];
		if(a%i==0){
			d1[i]=i;
		}
		if(b%i==0){
			d2[i]=i;
		}
		
	}
	for(ll i=1;i<=(a+b);i++){
		ll x=i;
		if(x*x>(a+b))break;
		if((a+b)%x)continue;
		if(check(x,(a+b)/x)){
			ll y=(a+b)/x;
			ans=min(ans,x*2+y*2);
		}
	} 
	cout<<ans;

	return 0;
}