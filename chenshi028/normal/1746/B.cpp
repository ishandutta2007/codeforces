#include<cstdio>
using namespace std;
const int o=1e5+10;
int T,n,a[o],ans;
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",ans),ans=0){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		for(int i=1,r=n;i<=n;++i) if(a[i]){
			for(;r>i&&a[r];--r);
			if(i<r) a[r]=1,++ans;
		}
	}
	return 0;
}