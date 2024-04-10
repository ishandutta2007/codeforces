/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
const int N=100000;
int n;
int a[N+1];
int And[N+1],anD[N+2];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	And[0]=anD[n+1]=0;
	for(int i=1;i<=n;i++)And[i]=And[i-1]|a[i];
	for(int i=n;i;i--)anD[i]=anD[i+1]|a[i];
	pair<int,int> ans(0,0);
	for(int i=1;i<=n;i++){
		int tmp=And[i-1]|anD[i+1];
		ans=max(ans,mp((a[i]|tmp)-tmp,i));
	}
	cout<<a[ans.second]<<" ";
	for(int i=1;i<=n;i++)if(i!=ans.second)cout<<a[i]<<" ";
	return 0;
}