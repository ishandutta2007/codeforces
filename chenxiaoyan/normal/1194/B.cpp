#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=50000,M=50000;
int n,m;
char a[M+1];string s[N+1];
int cntr[N+1],cntc[M+1];
int main(){
	int qu;
	scanf("%d",&qu);
	while(qu--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%s",a);
			s[i]=(string)" "+a;
		}
		for(int i=1;i<=n;i++){
			cntr[i]=0;
			for(int j=1;j<=m;j++)cntr[i]+=s[i][j]=='.';
		}
		for(int j=1;j<=m;j++){
			cntc[j]=0;
			for(int i=1;i<=n;i++)cntc[j]+=s[i][j]=='.';
		}
		int ans=inf;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
			ans=min(ans,cntr[i]+cntc[j]-(s[i][j]=='.'));
		printf("%d\n",ans);
	}
//	return 0;
}
/*1
9
5 5
..*..
..*..
*****
..*..
..*..
3 4
****
.*..
.*..
4 3
***
*..
*..
*..
5 5
*****
*.*.*
*****
..*.*
..***
1 4
****
5 5
.....
..*..
.***.
..*..
.....
5 3
...
.*.
.*.
***
.*.
3 3
.*.
*.*
.*.
4 4
*.**
....
*.**
*.**
*/