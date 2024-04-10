#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define dzd(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
using namespace std;
int t,n,px[100005],py[100005];
double ans;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int c1=0,c2=0,i;
		rep(i,n+n){
			int x,y;
			scanf("%d%d",&x,&y);
			if(!x) py[++c2]=abs(y); else px[++c1]=abs(x);
		}
		sort(px+1,px+n+1);
		sort(py+1,py+n+1);
		ans=0;
		rep(i,n){
			ans+=sqrt(1.0*px[i]*px[i]+1.0*py[i]*py[i]); 
		}
		printf("%.10f\n",ans);
	}
	return 0;
}