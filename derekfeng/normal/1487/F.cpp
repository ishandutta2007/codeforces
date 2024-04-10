#include<bits/stdc++.h>
using namespace std;
const int INF=10000;
int n,lim1,lim2;
char ch[53];
int f[53][53][520][2];
int dp(int pos,int c,int x,int del){
	if(pos==n)return c?INF:0;
	if(c>lim1||c<-lim1||x>lim2||x<-lim2)return INF;
	if(!(~f[pos][c+lim1][x+lim2][(del>0)]))
		f[pos][c+lim1][x+lim2][(del>0)]=min(dp(pos,c,x+del,del)+n-pos,min(dp(pos+1,c*10+ch[pos+1]-x,x,1),dp(pos+1,c*10+ch[pos+1]-x,x,-1)));
	return f[pos][c+lim1][x+lim2][(del>0)];
}
int main(){
	scanf("%s",ch+2),n=strlen(ch+2)+1,lim2=5*n,lim1=lim2/10+1;
	for(int i=2;i<=n;i++)ch[i]-='0';
	memset(f,-1,sizeof(f));
	printf("%d",dp(0,0,0,1));
}