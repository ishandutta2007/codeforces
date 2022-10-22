/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
void mian(){
	int n,m,s;
	cin>>n>>m>>s;
	int mx1=0,mx2=0;
	while(m--){int x;cin>>x;mx1=max(mx1,x);}
	while(s--){int x;cin>>x;mx2=max(mx2,x);}
	puts(mx1>mx2?"yes":"no");
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}