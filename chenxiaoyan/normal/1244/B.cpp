/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n;
char a[N+5];
void mian(){
	cin>>n>>a+1;
	int ans=n;
	for(int i=1;i<=n;i++)
		if(a[i]=='1')ans=max(ans,2*max(i,n-i+1));
	cout<<ans<<"\n";
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}