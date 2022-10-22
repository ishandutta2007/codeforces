#include<cstdio>
using namespace std;
int T,n;
int main(){
	for(scanf("%d",&T);T--;putchar('\n')){
		scanf("%d",&n);
		for(int i=1;i<=n;printf("%d ",++i));
	}
	return 0;
}