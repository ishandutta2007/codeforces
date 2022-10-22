/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
void mian(){
	int n;
	cin>>n;
	int x;
	cin>>x;
	x&=1;
	n--;
	bool ok=true;
	while(n--){
		int y;
		cin>>y;
		ok&=(x==(y&1));
	}
	puts(ok?"YES":"NO");
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}