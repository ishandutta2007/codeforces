/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
void mian(){
	int n;
	cin>>n;
	int sum1=0,sum2=0;
	while(n--){
		int x;
		cin>>x;
		sum1^=x;
		sum2+=x;
	}
	int x=1ll<<55;
	sum1^=x;sum2+=x;
	if(sum2&1)sum1^=x^x+1,sum2+=1,x+=1;
	printf("3 %lld %lld %lld\n",x,2*sum1-sum2>>1,2*sum1-sum2>>1);
}
signed main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}