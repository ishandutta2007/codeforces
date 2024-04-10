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
const int MAXN=110;
int t,n,a[MAXN],sum,maxn;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		sum=maxn=0;
		rep(i,1,n)scanf("%d",&a[i]),sum+=a[i],maxn=Max(maxn,a[i]);
		if(maxn>sum-maxn)printf("T\n");
		else printf("%s",(sum&1)?"T\n":"HL\n");
	}
	return 0;
}