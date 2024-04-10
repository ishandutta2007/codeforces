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
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=1e5+10;
int T,n,k,a[MAXN],ans;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);ans=n;
		rep(i,1,n){
			scanf("%d",&a[i]);
		}
		if(!k){
			printf("%d\n",ans);continue;
		}
		sort(a+1,a+1+n);
		int MEX=0;
		rep(i,1,n){
			if(a[i]==MEX){
				MEX++;
			}else break;
		}
		if(MEX==n){
			printf("%d\n",ans+k);continue;
		}
		int val=(MEX+a[n]+1)/2;
		rep(i,1,n){
			if(a[i]==val)goto END;
		}
		k--;ans++;
		END:printf("%d\n",ans);
	}
	return 0;
}