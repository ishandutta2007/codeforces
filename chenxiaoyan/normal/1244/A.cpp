/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
void mian(){
	int a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	int x=(a+c-1)/c,y=(b+d-1)/d;
	if(x+y>e)puts("-1");
	else cout<<x<<" "<<y<<"\n";
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}