#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define next Cry_For_theMoon
typedef long long ll;
using namespace std;
const int MAXN=110;
ll T,n,h[MAXN];
int main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		rep(i,1,n){
			scanf("%lld",&h[i]);
		}
		h[0]=-1;
		rep(i,1,n){
			if(h[i]<=h[i-1])goto END;
			ll v=h[i]-h[i-1]-1;
			h[i]-=v;h[i+1]+=v;
		}
		printf("YES\n");
		continue;
		END:printf("NO\n");
	}
	return 0;
}