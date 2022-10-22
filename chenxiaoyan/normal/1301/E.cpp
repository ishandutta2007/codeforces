/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define y1 sdfjaweofe
const int N=500,M=500;
int n,m,qu;
char a[N+1][M+5];
int Sum[N+1][M+1][4];
int sum(int x1,int y1,int x2,int y2,int x){
	return Sum[x2][y2][x]-Sum[x1-1][y2][x]-Sum[x2][y1-1][x]+Sum[x1-1][y1-1][x];
}
int Sum0[N+1][M+1][N+1];
bool ok(int x1,int y1,int x2,int y2){
	if(x2>n||y2>m)return false;
	int x3=x1+x2>>1,y3=y1+y2>>1;
	return sum(x1,y1,x3,y3,0)+sum(x1,y3+1,x3,y2,1)+sum(x3+1,y1,x2,y3,2)+sum(x3+1,y3+1,x2,y2,3)==(x2-x1+1)*(y2-y1+1);
}
int sum0(int x1,int y1,int x2,int y2,int x){
	return Sum0[x2][y2][x]-Sum0[x1-1][y2][x]-Sum0[x2][y1-1][x]+Sum0[x1-1][y1-1][x];
}
int main(){
	const char trs[]="RGYB";
	cin>>n>>m>>qu;
	for(int i=1;i<=n;i++)cin>>a[i]+1;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)for(int k=0;k<4;k++)
		Sum[i][j][k]=Sum[i-1][j][k]+Sum[i][j-1][k]-Sum[i-1][j-1][k]+(a[i][j]==trs[k]);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)for(int k=1;k<=min(n,m)>>1;k++)
		Sum0[i][j][k]=Sum0[i-1][j][k]+Sum0[i][j-1][k]-Sum0[i-1][j-1][k]+ok(i,j,i+2*k-1,j+2*k-1);
	while(qu--){
		int b,c,d,e;
		scanf("%d%d%d%d",&b,&c,&d,&e);
		int ans=0;
		for(int i=10;~i;i--)
			if(2*(ans+(1<<i))<=min(d-b+1,e-c+1)&&sum0(b,c,d-2*(ans+(1<<i))+1,e-2*(ans+(1<<i))+1,ans+(1<<i)))
				ans+=1<<i;
		cout<<ans*ans*4<<"\n";
	}
	return 0;
}
/*1
5 5 5
RRGGB
RRGGY
YYBBG
YYBBR
RBBRG
1 1 5 5
2 2 5 5
2 2 3 3
1 1 3 5
4 4 5 5
*/
/*2
6 10 5
RRRGGGRRGG
RRRGGGRRGG
RRRGGGYYBB
YYYBBBYYBB
YYYBBBRGRG
YYYBBBYBYB
1 1 6 10
1 3 3 10
2 2 6 6
1 7 6 10
2 1 5 10
*/
/*3
8 8 8
RRRRGGGG
RRRRGGGG
RRRRGGGG
RRRRGGGG
YYYYBBBB
YYYYBBBB
YYYYBBBB
YYYYBBBB
1 1 8 8
5 2 5 7
3 1 8 6
2 3 5 8
1 2 6 8
2 1 5 5
2 1 7 7
6 5 7 5
*/