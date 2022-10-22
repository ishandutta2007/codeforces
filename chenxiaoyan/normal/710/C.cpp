/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=49;
int a[N+1][N+1];
int main(){
	int n;
	cin>>n;
	int x=1,y=n/2+1,now=0;
	while(now<n*n){
		a[x][y]=++now;
		if(x==1&&y<n)x=n,y++;
		else if(y==n&&x>1)y=1,x--;
		else if(x==1&&y==n||a[x-1][y+1])x++;
		else x--,y++;
	}
	for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)cout<<a[i][j]<<" ";puts("");}
	return 0;
}