/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin>>n;
	bool now=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x%2)cout<<(now?(x>>1):(x>>1)+1)<<"\n",now^=1;
		else cout<<x/2<<"\n";
	}
	return 0;
}