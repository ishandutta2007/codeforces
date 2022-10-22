/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=100000;
int n;
int a[N+1];
void mian(){
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=30;~i;i--){
		int zero=0,one=0;
		for(int j=1;j<=n;j++)if(a[j]&1<<i)one++;else zero++;
		if(one%2==0)continue;
		if(zero%2==1)return puts("WIN"),void();
		else
			if((one-1)/2%2==0)return puts("WIN"),void();
			else return puts("LOSE"),void();
	}
	puts("DRAW");
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}