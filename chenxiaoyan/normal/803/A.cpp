/*








*/
#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,m; 
bool a[N+1][N+1];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(!a[i][j]){
		int need=i==j?1:2;
		if(m>=need)m-=need,a[i][j]=a[j][i]=1;
	}
	if(m)return puts("-1"),0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)cout<<a[i][j]<<" ";
		puts("");
	}
	return 0;
}