#include<cstdio>
#include<algorithm>
using namespace std;
const int o=1e5+10;
int T,n,a[o],b[o],st1[o],tp1,st2[o],tp2;long long ans;
int main(){
	for(scanf("%d",&T);T--;printf("%lld\n",ans),ans=tp1=tp2=0){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		for(int i=1;i<=n;++i) scanf("%d",&b[i]),ans+=b[i];
		for(int i=1;i<=n;++i)
			if(!a[i]) st1[++tp1]=b[i];
			else st2[++tp2]=b[i];
		sort(st1+1,st1+tp1+1);sort(st2+1,st2+tp2+1);
		for(int i=tp1-min(tp1,tp2)+1;i<=tp1;++i) ans+=st1[i];
		for(int i=tp2-min(tp1,tp2)+1;i<=tp2;++i) ans+=st2[i];
		if(tp1==tp2) ans-=min(st1[1],st2[1]);
	}
	return 0;
}