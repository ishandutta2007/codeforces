#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;
const int MAXN=110;
int T,n,a[MAXN],ans;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,1,n){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		ans=n-1;
		rep(i,2,n){
			if(a[i]==a[1])ans--;
		}
		printf("%d\n",ans);
	}
	
	return 0;
}