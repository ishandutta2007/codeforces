/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
void mian(){
	int x;
	cin>>x;
	int a=0,b=0;
	for(int i=2;i<=sqrt(x);i++)if(x%i==0){x/=i;a=i;break;}
	for(int i=2;i<=sqrt(x);i++)if(x%i==0&&i!=a){x/=i;b=i;break;}
	if(!a||!b||a==x||b==x)puts("NO");
	else printf("YES\n%d %d %d\n",a,b,x);
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}