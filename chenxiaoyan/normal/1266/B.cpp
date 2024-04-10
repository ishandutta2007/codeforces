/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
void mian(){
	int n;
	cin>>n;
	puts(n>=15&&1<=n%14&&n%14<=6?"YES":"NO");
}
signed main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}