/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
void mian(){
	int n;
	cin>>n;
	if(n==1)puts("-1");
	else{
		putchar('8');
		for(int i=1;i<n;i++)putchar('9');
		puts("");
	}
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}