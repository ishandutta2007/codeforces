#include<cstdio>
using namespace std;
const int o=1e6;
int T,n,ans;char s[o];
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",ans)){
		scanf("%d%s",&n,s+1);ans=n+1;
		for(int i=1;i<2*n;++i) ans-=(s[i]=='('&&s[i+1]==')');
	}
	return 0;
}