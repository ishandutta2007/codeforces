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
int T,n,k,q;
ll sum;
ll Add(int a,int b){
	ll ret=0,ans=0,base=1;
	rep(i,1,20){
		if(!a && !b)break;
		ll val=(a%k+b%k)%k;
		ret=ret+val*base;
		base*=k;
		a/=k;b/=k;
	}
	return ret;
}
ll Minus(int a,int b){
	ll ret=0,ans=0,base=1;
	rep(i,1,20){
		if(!a && !b)break;
		ll val=(a%k-b%k+k)%k;
		ret=ret+val*base;
		base*=k;
		a/=k;b/=k;
	}
	return ret;
}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		sum=0;
		rep(i,1,n){
			if(i==1)q=0;
			else{
				if(odd(i))q=Add(sum,i-1);
				else q=Minus(sum,i-1);
			}
			cout<<q<<endl;
			int r;
			cin>>r;
			if(r==1)break;
			sum=Minus(q,sum);
		}
	}
	return 0;
}