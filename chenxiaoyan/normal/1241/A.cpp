/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
void mian(){
	int x;
	cin>>x;
	if(x<=4)cout<<4-x;
	else cout<<(x&1);
	puts("");
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}