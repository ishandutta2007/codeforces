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
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=3e4+10;
int T,n,a[MAXN],d[MAXN],sum;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);sum=0;
		rep(i,1,n)scanf("%d",&a[i]);
		rep(i,1,n)d[i]=a[i]-a[i-1];
		rep(i,1,n)if(d[i]<0)sum-=d[i];
		printf("%s\n",(sum>a[1])?"NO":"YES");
	}
	return 0;
}