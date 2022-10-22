/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
void mian(){
	long long a,b,n;
	scanf("%lld%lld%lld",&a,&b,&n);
	if(a>b)swap(a,b);
	if(b>n){puts("0");return;}
	for(int i=1;;i++){
		a+=b;
		swap(a,b);
		if(b>n){printf("%d\n",i);return;}
	}
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}