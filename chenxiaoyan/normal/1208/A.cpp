/*








 l l
*/
#include<bits/stdc++.h>
using namespace std;
void mian(){
	int a,b,c;
	cin>>a>>b>>c;
	c%=3;
	cout<<(c==0?a:c==1?b:a^b)<<"\n";
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}