#include<cstdio>
using namespace std;
const int o=2e5+10;
int T,n,b,x,y,a;long long ans;
int main(){
	for(scanf("%d",&T);T--;printf("%lld\n",ans),ans=0)
		for(scanf("%d%d%d%d",&n,&b,&x,&y),a=0;n--;ans+=a)
			if(a+x<=b) a+=x;else a-=y;
	return 0;
}