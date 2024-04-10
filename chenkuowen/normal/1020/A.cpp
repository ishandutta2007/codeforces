#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX_N=1005;
template<typename T> struct Interval{
	T l; T r;
};
int main(){
	int n,h; Interval<int> base;
	scanf("%d%d%d%d",&n,&h,&base.l,&base.r);
	int q; scanf("%d",&q);
	while(q--){
		int t[2],f[2];
		scanf("%d%d%d%d",&t[0],&f[0],&t[1],&f[1]);
		int ans=abs(t[1]-t[0]);
		if(t[1]!=t[0]){
			for(int i=0;i<2;++i){
				if(f[i]<base.l) ans+=base.l-f[i],f[i]=base.l;
				if(f[i]>base.r) ans+=f[i]-base.r,f[i]=base.r;
			}
		}
		ans+=abs(f[1]-f[0]);
		printf("%d\n",ans);
	}
	return 0;
}