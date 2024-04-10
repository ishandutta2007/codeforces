#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
const int o=2e5+10;
int T,n,x,a[o],ans;multiset<int> s;
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",ans),ans=0,s.clear()){
		scanf("%d%d",&n,&x);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]),s.insert(a[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;++i) if(s.find(a[i])!=s.end()){
			s.erase(s.find(a[i]));
			if(a[i]*1ll*x<=a[n]&&s.find(a[i]*x)!=s.end()) s.erase(s.find(a[i]*x));
			else ++ans;
		}
	}
	return 0;
}