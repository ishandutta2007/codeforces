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
const int MAXN=1e4+10;
ll n,k,A[MAXN];
ll f(ll x,ll y){
	ll a,b,sum=0;
	printf("and %lld %lld\n",x,y);
	fflush(stdout);
	cin>>a;sum+=a;
	printf("or %lld %lld\n",x,y);
	fflush(stdout);
	cin>>b;sum+=b;
	return sum;
}
int main(){
	cin>>n>>k;
	ll a=f(1,2);
	ll b=f(2,3);
	ll c=f(1,3);
	A[1]=(a+b+c)/2-b;
	A[2]=(a+b+c)/2-c;
	A[3]=(a+b+c)/2-a;
	rep(i,4,n){
		A[i]=f(1,i)-A[1];
	}
	sort(A+1,A+1+n);
	printf("finish %lld",A[k]);
	fflush(stdout);
	return 0;
}