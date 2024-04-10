#include<cstdio>
using namespace std;
const int o=1e5+10;
int T,n,m;bool isb[o];
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i) isb[i]=0;
		for(int a,b,c;m--;isb[b]=1) scanf("%d%d%d",&a,&b,&c);
		for(int i=1;i<=n;++i) if(!isb[i]){
			for(int j=1;j<=n;++j) if(i^j) printf("%d %d\n",i,j);
			break;
		}
	}
	return 0;
}