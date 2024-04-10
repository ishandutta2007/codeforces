/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=50,M=50;
int n,m;
char a[N+1][M+5];
int Sum1[N+1][M+1],Sum2[M+1][N+1];
int sum1(int x,int y,int z){
	if(y>z)swap(y,z);
	return Sum1[x][z]-Sum1[x][y-1];
}
int sum2(int x,int y,int z){
	if(y>z)swap(y,z);
	return Sum2[x][z]-Sum2[x][y-1];
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i]+1;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)Sum1[i][j]=Sum1[i][j-1]+(a[i][j]=='B');
	for(int j=1;j<=m;j++)for(int i=1;i<=n;i++)Sum2[j][i]=Sum2[j][i-1]+(a[i][j]=='B');
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)for(int k=1;k<=n;k++)for(int o=1;o<=m;o++)if(a[i][j]=='B'&&a[k][o]=='B'){
		int mx=max(sum1(i,j,o)+sum2(o,i,k),sum1(k,j,o)+sum2(j,i,k));
		if(mx<abs(i-k)+abs(j-o)+2)return puts("NO"),0;
	}
	puts("YES");
	return 0;
}
/*1
3 4
WWBW
BWWW
WWWB
*/
/*2
3 1
B
B
W
*/
/*3
3 3
WBB
BBW
BWW
*/