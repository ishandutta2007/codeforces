#include<cstdio>
using namespace std;
const int o=1010;
int T,n,a[o],se,fi;
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",fi+se),fi=se=0){
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			if(a[i]>fi) se=fi,fi=a[i];
			else if(a[i]>se) se=a[i];
		}
	}
	return 0;
}