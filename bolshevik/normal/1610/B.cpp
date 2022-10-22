#include<cstdio>
using namespace std;
const int o=2e5+10;
int T,n,a[o],b,c;
inline int chk(int d){
	for(int i=1,j=n;i<j;++i,--j)
		if(a[i]==d) ++j;else if(a[j]==d) --i;else if(a[i]^a[j]) return false;
	return true;
}
int main(){
	for(scanf("%d",&T);T--;b=c=0){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		for(int i=1;i<=n;++i) if(a[i]!=a[n-i+1]){b=a[i];c=a[n-i+1];break;}
		printf((!b||chk(b)||chk(c))?"YES\n":"NO\n");
	}
	return 0;
}