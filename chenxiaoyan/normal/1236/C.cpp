/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
	int n;
	cin>>n;
	if(n%2==0){
		int now=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n/2;j++)cout<<++now<<" ",cout<<n*n-now+1<<" ";
			puts("");
		}
	}
	else{
		int now=0;
		vector<int> ans[n+1];
		for(int i=1;i<=n;i++)for(int j=1;j<=n/2;j++)ans[i].pb(++now),ans[i].pb(n*n-now+1);
		for(int i=1;i<=n;i++)ans[i].pb(now+i);
		for(int i=1;i<=n;i++){
			for(int j=0;j<n;j++)cout<<ans[i][j]<<" ";
			puts("");
		}
	}
	return 0;
}