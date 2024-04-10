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
const int MAXN=1010;
ll T,n,x,w[MAXN],sum,flag;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>x;
		sum=0;
		rep(i,1,n)cin>>w[i],sum+=w[i];
		if(sum<x){
			printf("YES\n");rep(i,1,n)printf("%lld ",w[i]);printf("\n");continue;
		}else if(sum==x){
			printf("NO\n");continue;
		}
		sort(w+1,w+1+n,greater<int>());
		if(n==1 && x==w[1]){
			printf("NO\n");continue;
		}
		printf("YES\n");
		sum=0;flag=0;
		rep(i,1,n){
			if(flag){
				flag=0;continue;
			}
			sum+=w[i];
			if(sum!=x)printf("%lld ",w[i]);
			else{
				printf("%lld %lld ",w[i+1],w[i]);sum+=w[i+1];flag=1;
			}
		}
		printf("\n");
	}

	return 0;
}