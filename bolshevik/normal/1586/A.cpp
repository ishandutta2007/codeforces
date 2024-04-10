#include<cstdio>
using namespace std;
inline bool chk(int x){for(int i=2;i<x;++i) if(x%i==0) return true;return false;}
int T,n,a[110],s;
int main(){
	for(scanf("%d",&T);T--;s=0,putchar('\n')){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]),s+=a[i];
		if(chk(s)){
			printf("%d\n",n);
			for(int i=1;i<=n;++i) printf("%d ",i);
		}
		else{
			printf("%d\n",n-1);
			for(int i=1;i<=n;++i) if(a[i]&1){
				for(int j=1;j<=n;++j) if(i^j) printf("%d ",j);
				break;
			}
		}
	}
	return 0;
}