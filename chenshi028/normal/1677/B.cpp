#include<cstdio>
using namespace std;
const int o=1e6+10;
int T,n,m,f[o],g[o];char s[o];
int main(){
	for(scanf("%d",&T);T--;putchar('\n')){
		scanf("%d%d%s",&n,&m,s+1);
		for(int i=0;i<m;++i) g[i]=0;
		for(int i=1,z=0;i<=n*m;++i){
			z+=s[i]-48;
			if(i>m) z-=s[i-m]-48,f[i]=f[i-m]+!!z;
			else f[i]=!!z;
		}
		for(int i=1,j=0;i<=n*m;++i){
			if(s[i]>48) if(!g[i%m]++) ++j;
			printf("%d ",f[i]+j);
		}
	}
	return 0;
}