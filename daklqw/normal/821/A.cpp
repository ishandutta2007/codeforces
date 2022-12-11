#include <iostream>
using namespace std;
int n,sums[60][60];bool ans=true;
bool check(int x,int y){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(sums[x][i]+sums[j][y]==sums[x][y])return true;
	return false;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>sums[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)if(sums[i][j]!=1)if(!check(i,j))ans=false;
	cout<<(ans?"Yes":"No")<<endl;
	return 0;
}