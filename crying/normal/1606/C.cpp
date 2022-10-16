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
const ll MAXN=15;
ll T,n,k,a[MAXN],power[MAXN];
void solve(){
	cin>>n>>k;
	k++;
	rep(i,1,n){
		cin>>a[i];
	}
	ll ret=0;
	rep(i,1,n-1){
		ll diff=a[i+1]-a[i];
		ll num=power[diff]-1;
		if(k<=num){
			ret+=k*power[a[i]];
			printf("%lld\n",ret);
			return;
		}
		ret+=num*power[a[i]];
		k-=num;
	}
	ret+=k*power[a[n]];
	printf("%lld\n",ret);
}
int main(){
	power[0]=1;
	rep(i,1,14)power[i]=power[i-1]*10;
	cin>>T;
	while(T--){
		solve();
	}

	return 0;
}
/*
1
3 255
0 1 3
*/