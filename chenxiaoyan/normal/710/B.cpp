/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=300000;
int n;
int a[N+1];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	sort(a+1,a+n+1);
	if(n&1)cout<<a[n/2+1];
	else cout<<a[n/2];
	return 0;
}