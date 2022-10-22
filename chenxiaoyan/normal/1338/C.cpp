/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
void mian(){
	int n;
	scanf("%lld",&n);
	int m=0,now=0;
	while(true){
		now+=3ll<<m;
		m+=2;
		if(now>=n)break;
	}
	for(int i=2;i<m;i+=2)n-=3ll<<i-2;
	int ans=n%3==1?1ll<<m-2:n%3==2?1ll<<m-1:1ll<<m-2|1ll<<m-1;
	while(m>2){
		m-=2;
		if(n<=3ll<<m-2);
		else if(n<=6ll<<m-2)ans|=n%3==1?1ll<<m-2:n%3==2?1ll<<m-1:1ll<<m-2|1ll<<m-1,n-=3ll<<m-2;
		else if(n<=9ll<<m-2)ans|=n%3==1?1ll<<m-1:n%3==2?1ll<<m-2|1ll<<m-1:1ll<<m-2,n-=6ll<<m-2;
		else if(n<=12ll<<m-2)ans|=n%3==1?1ll<<m-2|1ll<<m-1:n%3==2?1ll<<m-2:1ll<<m-1,n-=9ll<<m-2;
	}
	printf("%lld\n",ans);
}
signed main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}