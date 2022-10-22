/*








 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
void mian(){
	int a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	if(d>e)cout<<d*min(a/2,b)+e*max(0ll,min(a/2-b,c))<<"\n";
	else cout<<e*min(a/2,c)+d*max(0ll,min(a/2-c,b))<<"\n";
}
signed main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}