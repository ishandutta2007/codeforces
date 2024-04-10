#include<cstdio>
using namespace std;
int T,n,a,s;
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",!!(s%n)),s=0){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a),s+=a;
	}
	return 0;
}