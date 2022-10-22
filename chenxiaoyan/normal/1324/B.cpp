/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=5000;
int n;
int a[N+1];
void mian(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)for(int j=i+2;j<=n;j++)if(a[i]==a[j]){puts("YES");return;}
	puts("NO");
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}