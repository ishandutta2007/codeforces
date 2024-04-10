/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=200000;
int n;
char a[N+5];
int main(){
	cin>>n>>a+1;
	int ans=0;
	for(int i=1;i<n;i+=2)
		if(a[i]==a[i+1])
			ans++,a[i]='a',a[i+1]='b';
	cout<<ans<<"\n"<<a+1;
	return 0;
}