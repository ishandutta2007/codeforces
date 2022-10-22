#include<cstdio>
using namespace std;
int T,n,ans;
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",ans)){
		scanf("%d",&n);
		for(ans=0;ans<n-1;ans=ans*2+1);
		for(int i=0,p;i<n;++i){
			scanf("%d",&p);
			if(i^p) ans&=p;
		}
	}
	return 0;
}