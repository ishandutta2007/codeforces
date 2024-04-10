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
#define mapit map<int,int>::iterator
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
#define pr pair
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=5e6+10;
int n,a[MAXN];
pr<int,int>t[MAXN];
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);
	}
	rep(i,1,n){
		rep(j,i+1,n){
			int sum=a[i]+a[j];
			if(!t[sum].first){
				t[sum]=mp(i,j);
				continue;
			}
			if(t[sum].first && t[sum].first!=i && t[sum].first!=j && t[sum].second!=i && t[sum].second!=j){
				printf("YES\n");
				printf("%d %d %lld %lld\n",t[sum].first,t[sum].second,i,j);
				return 0;
			}
		}
	}
	printf("NO");
	return 0;
}