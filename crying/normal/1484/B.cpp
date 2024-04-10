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
const int MAXN=1e5+10;
ll t,n,a[MAXN],k,m;
int main(){
	cin>>t;
	while(t--){
		cin>>n;m=0;
		rep(i,1,n)cin>>a[i];a[n+1]=0;
		rep(i,1,n-1)if(a[i]!=a[i+1])goto FAIL1;
		printf("0\n");continue;
		FAIL1:;
		k=a[2]-a[1];
		rep(i,1,n-1){
			if(a[i]+k!=a[i+1]){
				// 
				if(!m){
					m=Max(a[i+1],a[i]+k)-Min(a[i+1],a[i]+k);
					break;
				}
			}
		}
		if(!m){
			printf("0\n");continue;
		}
		k=(k+m)%m;
		if(a[1]>=m)goto FAIL2;
		rep(i,1,n-1){
			if((a[i]+k)%m!=a[i+1])goto FAIL2;
		}
		printf("%lld %lld\n",m,k);continue;
		FAIL2:printf("-1\n");
	}
	return 0;
}