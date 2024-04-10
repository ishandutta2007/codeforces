#include<cstdio>
#include<algorithm>
using namespace std;
const int o=1e6+10;
int T,n,ans,x[o],y[o],st[o],tp,tar;
void slv(int n,int coef){
	if(n<=2){for(int i=1;i<=n;++i) st[++tp]=i*coef;return;}
	int p=1;
	for(;p*2<=n;p*=2);
	if(p==n){st[++tp]=n*coef;slv(n-1,coef);return;}
	for(int i=1;i<=n-p;++i) x[++ans]=(p-i)*coef,y[ans]=(p+i)*coef,st[++tp]=2*p*coef;
	slv(2*p-n-1,coef);slv(n-p,coef*2);st[++tp]=p*coef;
}
int main(){
	for(scanf("%d",&T);T--;putchar('\n'),ans=tp=0){
		scanf("%d",&n);
		if(n==2){printf("-1");continue;}
		for(tar=1;tar<n;tar*=2);
		slv(n,1);
		sort(st+1,st+tp+1);
		for(int i=1;i<tp;++i) if(st[i]==st[i+1]){x[++ans]=st[i];y[ans]=st[i+1];st[i]*=2;st[i+1]=0;break;}
		for(int i=1;i<=tp;++i) if(st[i])
			for(;st[i]<tar;st[i]*=2) x[++ans]=0,y[ans]=st[i],x[++ans]=st[i],y[ans]=st[i];
		for(int i=1;i<=tp;++i) if(!st[i]) x[++ans]=0,y[ans]=tar;
		printf("%d",ans);
		for(int i=1;i<=ans;++i) printf("\n%d %d",x[i],y[i]);
	}
	return 0;
}