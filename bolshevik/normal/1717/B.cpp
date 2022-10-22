#include<cstdio>
using namespace std;
int T,n,k,r,c;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%d%d%d",&n,&k,&r,&c);
		for(int i=1;i<=n;++i,putchar('\n'))
			for(int j=1;j<=n;++j) if((i+j)%k==(r+c)%k) putchar('X');else putchar('.');
	}
	return 0;
}