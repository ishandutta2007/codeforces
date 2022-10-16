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
const int MAXN=1e6+10;
int n,m,p,a[MAXN],b[MAXN];
int main(){
	scanf("%d%d%d",&n,&m,&p);
	rep(i,0,n-1){
		scanf("%d",&a[i]);
	}
	rep(i,0,m-1){
		scanf("%d",&b[i]);
	}
	rep(i,0,n-1){
		if(a[i]%p==0)continue;
		rep(j,0,m-1){
			if(b[j]%p==0)continue;
			printf("%d",i+j);return 0;
		}
	}
	return 0;
}