#include<cstdio>
using namespace std;
const int o=1e5+10;
int T,n,k;char s[o];
int main(){
	for(scanf("%d",&T);T--;putchar('\n')){
		scanf("%d%s",&n,s+1);
		for(k=1;k<n&&(s[k+1]<s[k]||(s[k+1]==s[k]&&k>1));++k);
		for(int i=1;i<=k;++i) putchar(s[i]);
		for(int i=k;i;--i) putchar(s[i]);
	}
	return 0;
}