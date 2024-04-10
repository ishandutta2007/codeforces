#include<cstdio>
using namespace std;
const int o=2010;
int n,bl[o][o],z[o][o],v[o];char s[o][o];
int main(){
	scanf("%d",&n);
	if(n&1){printf("NONE");return 0;}
	for(int i=1;i<=n;++i) scanf("%s",s[i]+1);
	for(int i=1,x,y,col=0,j=1;i<n;i+=2,++j){
		for(x=i,y=1;1;--x,++y,col^=1){
			bl[x][y]=j;z[x][y]=col;
			if(x==1) break;
		}
		for(++y;1;++x,++y,col^=1){
			bl[x][y]=j;z[x][y]=col;
			if(y==n) break;
		}
		for(++x;1;++x,--y,col^=1){
			bl[x][y]=j;z[x][y]=col;
			if(x==n) break;
		}
		for(--y;1;--x,--y,col^=1){
			bl[x][y]=j;z[x][y]=col;
			if(y==1) break;
		}
	}
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j)
		if(s[i][j]=='S')
			if(v[bl[i][j]]&&(v[bl[i][j]]^z[i][j]^2)){printf("NONE");return 0;}
			else v[bl[i][j]]=z[i][j]^2;
		else if(s[i][j]=='G')
			if(v[bl[i][j]]&&(v[bl[i][j]]^z[i][j]^3)){printf("NONE");return 0;}
			else v[bl[i][j]]=z[i][j]^3;
	for(int i=1;i<=n/2;++i) if(!v[i]){printf("MULTIPLE");return 0;}
	printf("UNIQUE\n");
	for(int i=1;i<=n;++i,putchar('\n')) for(int j=1;j<=n;++j) putchar((z[i][j]^v[bl[i][j]])==2?'S':'G');
	return 0;
}