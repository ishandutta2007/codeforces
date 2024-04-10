#include<cstdio>
#include<iostream>
using namespace std;
int T,x,y,f[60][60],a[10010];
int main(){
	for(int i=0;i<=100;++i) a[i*i]=1;
	for(int i=0;i<51;++i) for(int j=0;j<51;++j) f[i][j]=100000000;
	for(int i=f[0][0]=0;i<51;++i) for(int j=0;j<51;++j)
		for(int $=0;$<=i;++$) for(int _=0;_<=j;++_)
			if($<i||_<j) if(a[(i-$)*(i-$)+(j-_)*(j-_)]) f[i][j]=min(f[i][j],f[$][_]+1); 
	for(scanf("%d",&T);T--;printf("%d\n",f[x][y])) scanf("%d%d",&x,&y);
	return 0;
}