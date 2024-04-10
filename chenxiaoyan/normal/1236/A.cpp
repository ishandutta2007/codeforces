/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
void mian(){
	int a,b,c;
	cin>>a>>b>>c;
	int ans=0;
	for(int i=0;i<=100;i++)for(int j=0;j<=100;j++)
		if(i<=a&&2*i+j<=b&&2*j<=c)ans=max(ans,3*(i+j));
	cout<<ans<<"\n";
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}