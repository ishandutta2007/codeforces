#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500+5;
int n,m;
int ans[N][N];
int main(){
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) cin>>ans[i][i];
	for(i=n;i;i--){
		int c=ans[i][i]-1,x=i,y=i;
		while(c--){
			if(x<n&&!ans[x+1][y]) x++;
			else y--;
			ans[x][y]=ans[i][i];
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++) cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}