/*









 l l
*/
#include<bits/stdc++.h>
using namespace std;
int a,b,n;
int main(){
	cin>>a>>b>>n;
	int ans=0;
	for(int i=0;i<=a;i++)
		ans+=i<=n&&n-i<=b;
	cout<<ans;
	return 0;
}