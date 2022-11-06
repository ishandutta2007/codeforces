#include<bits/stdc++.h>
using namespace std;
template<class T>
void read(T &x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
int a[45];
int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
int main(){
	int T,x,n,i,j,g;
	read(T);
	while(T--){
		read(n);
		g=0;
		memset(a,0,sizeof(a));
		for(i=1;i<=n;++i){
			read(x);
			for(j=0;j<=29;++j)if(x&(1<<j))++a[j];
		}
		for(j=0;j<=29;++j)g=gcd(g,a[j]);
		for(j=1;j<=n;++j)if(g%j==0)printf("%d ",j);puts("");
	}
	return 0;
}