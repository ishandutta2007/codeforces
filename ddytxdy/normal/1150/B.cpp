#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=60;
int n;char c[N][N];bool vis[N][N];
bool check(int x,int y){
	if(y==1||y==n||x>n-2)return 0;
	if(c[x+1][y-1]=='#'||vis[x+1][y-1])return 0;
	if(c[x+1][y]=='#'||vis[x+1][y])return 0;
	if(c[x+1][y+1]=='#'||vis[x+1][y+1])return 0;
	if(c[x+2][y]=='#'||vis[x+2][y])return 0;
	return 1;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%s",c[i]+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(c[i][j]=='#'||vis[i][j])continue;
			if(!check(i,j)){
				puts("NO");return 0;
			}
			else vis[i+1][j+1]=vis[i+1][j]=vis[i+1][j-1]=vis[i+2][j]=1;
		}
	}
	puts("YES");
	return 0;
}