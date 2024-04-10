#include<cstdio>
using namespace std;
const int o=2e5+10;
int T,n,ans;char s[o];
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",ans)){
		scanf("%d%s",&n,s+1);ans=(n&1);
		for(int i=n/2;i&&s[i]==s[(n+1)/2];--i) ans+=2;
	}
	return 0;
}