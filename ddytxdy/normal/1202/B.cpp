#include<bits/stdc++.h>
using namespace std;
const int N=2e6+50,inf=0x3f3f3f3f;
int len,num[10][10],ans[10][10],d[10][10];char c[N];
void cmin(int &x,int y){y<x?x=y:0;}
int solve(int x,int y){
	memset(d,0x3f,sizeof(d));
	for(int i=0;i<10;i++)d[i][(i+x)%10]=1;
	for(int i=0;i<10;i++)d[i][(i+y)%10]=1;
	for(int k=0;k<10;k++)
		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
				cmin(d[i][j],d[i][k]+d[k][j]);
	int ret=0;
	for(int i=0;i<10;i++)for(int j=0;j<10;j++)if(num[i][j]){
		if(d[i][j]==inf)return -1;
		ret+=num[i][j]*(d[i][j]-1);
	}
	return ret;
}
int main(){
	scanf("%s",c+1);
	len=strlen(c+1);
	for(int i=1;i<len;i++)num[c[i]-'0'][c[i+1]-'0']++;
	for(int i=0;i<10;i++){
		for(int j=0;j<i;j++)printf("%d ",ans[j][i]);
		for(int j=i;j<10;j++)printf("%d ",ans[i][j]=solve(i,j));
		puts("");
	}
	return 0;
}