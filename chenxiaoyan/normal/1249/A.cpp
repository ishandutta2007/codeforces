/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n;
int a[N+1];
void mian(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)if(a[i]==a[i+1]-1){puts("2");return;}
	puts("1");
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}