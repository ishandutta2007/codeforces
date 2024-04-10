/*









 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int n,a,b;
int main(){
	cin>>n>>a>>b;
	b*=5;
	int ans=inf;
	for(int i=0;i<=10000;i++)if(n>=a*i){
		int rst=(n-a*i)%b;
		ans=min(ans,rst);
	}
	cout<<ans;
	return 0;
}