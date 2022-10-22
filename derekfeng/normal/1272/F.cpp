#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[202],t[202];
int f[202][202][402];
int dp(int x,int y,int z){
	if(x==n&&y==m&&z==0)return 0;
	if(z>400||z<0)return 1e5;
	if(~f[x][y][z])return f[x][y][z];
	f[x][y][z]=1e5;
	int c1=(x<n?s[x]-'(':2),c2=(y<m?t[y]-'(':2);
	for(int i=0;i<2;i++){
		int nx=x+(i==c1),ny=y+(i==c2),nz=z+(i==0?1:-1);
		f[x][y][z]=min(f[x][y][z],dp(nx,ny,nz)+1);
	}
	return f[x][y][z];
}
void built(int x,int y,int z){
	if(x==n&&y==m&&z==0)return;
	int c1=(x<n?s[x]-'(':2),c2=(y<m?t[y]-'(':2);
	for(int i=0;i<2;i++){
		int nx=x+(i==c1),ny=y+(i==c2),nz=z+(i==0?1:-1);
		if(f[x][y][z]==dp(nx,ny,nz)+1){
			putchar('('+i);
			built(nx,ny,nz);
			return;
		}
	}
}
int main(){
	memset(f,-1,sizeof(f));
	scanf("%s%s",s,t),n=strlen(s),m=strlen(t);
	dp(0,0,0);
	built(0,0,0);
}