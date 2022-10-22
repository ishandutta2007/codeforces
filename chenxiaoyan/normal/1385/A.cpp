/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
void mian(){
	int x,y,z;
	scanf("%d%d%d",&x,&y,&z);
	if(x>y)swap(x,y);if(y>z)swap(y,z);
	if(x>y)swap(x,y);if(y>z)swap(y,z);
	if(y!=z)return puts("NO"),void();
	puts("YES");
	cout<<1<<" "<<x<<" "<<y<<"\n";
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}