#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;

int T;
ll x,y,ans,res;

void doit(ll i){
	ll tmpx=x,tmpy=y;
	while (tmpx%i==0) tmpx/=i;
	tmpy/=i;
	while (tmpy%i==0) tmpy/=i,tmpx*=i;
	ans=max(ans,tmpx);	
}

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%lld%lld",&x,&y);
		if (x%y!=0) printf("%lld\n",x); 
		else {
			ans=1,res=y;
			for(ll i=2;i<=sqrt(res);i++) if (res%i==0){
				doit(i);
				while (res%i==0) res/=i;
			}
			if (res>1) doit(res);
			printf("%lld\n",ans);
		}
	}
}