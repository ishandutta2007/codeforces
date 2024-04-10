#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e6+50;
LL T;long long n,nn,a[4]={0,2,3,1},b[4]={0,3,1,2};
int  main(){
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);LL x=1;
		while(n>x*3)n-=x*3,x<<=2;
		if(n%3==1)printf("%lld\n",x+n/3);
		else if(n%3==2){
			n/=3;LL ans=x<<1;
			for(LL i=x>>2;i;i>>=2){
				LL dat=n/i;
				ans|=a[dat]*i;n%=i;
			}
			cout<<ans<<endl;
		}
		else{
			n--;n/=3;LL ans=x<<1|x;
			for(LL i=x>>2;i;i>>=2){
				LL dat=n/i;ans|=b[dat]*i;n%=i;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}