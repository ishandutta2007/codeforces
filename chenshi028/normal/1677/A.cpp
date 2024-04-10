#include<cstdio>
using namespace std;
const int o=5010;
int T,n,p[o],a[o];long long ans;

int main(){
	for(scanf("%d",&T);T--;printf("%lld\n",ans),ans=0){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&p[i]);
		for(int i=2;i<n;++i){
			for(int j=1;j<=n;++j) a[j]=0;
			for(int j=1;j<i;++j) ++a[p[j]];
			for(int j=1;j<=n;++j) a[j]+=a[j-1];
			for(int j=i+1,s=0;j<=n;s+=a[p[j++]]) if(p[i]>p[j]) ans+=s;
		}
	}
	return 0;
}