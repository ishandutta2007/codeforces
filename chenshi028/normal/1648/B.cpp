#include<cstdio>
#include<iostream>
using namespace std;
const int o=1e6+10;
int T,n,c,s[o];
inline void slv(){
	for(int i=1;i<=c;++i) s[i]=0;
	for(int a;n--;++s[a]) scanf("%d",&a);
	for(int i=1;i<=c;++i) s[i]+=s[i-1];
	for(int i=1;i<=c;++i) if(s[i]^s[i-1]) for(int j=1;i*j<=c;++j)
		if(s[j]==s[j-1]&&s[min(c,i*j+i-1)]-s[i*j-1]){printf("No\n");return;}
	printf("Yes\n");
}
int main(){for(scanf("%d",&T);T--;slv()) scanf("%d%d",&n,&c);return 0;}