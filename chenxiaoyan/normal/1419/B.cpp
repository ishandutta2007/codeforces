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
	int now=0;
	for(int i=1;;i++){
		now+=((1ll<<i)-1)*(1ll<<i)/2;
		if(now>n)return cout<<i-1<<"\n",void();
	}
}
signed main(){
	int testnum=1;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}