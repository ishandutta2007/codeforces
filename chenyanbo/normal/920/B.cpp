#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
int n,t,c,f[1005],l[1008],r[2006];
int main()
{
	t=read();
	while(t--){
		n=read();
		c=0;
		for(int i=1; i<=n; ++i){
			f[i]=0; //200000000000000//ll
			l[i]=read();
			r[i]=read();
			if(r[i]<=c)continue;
			++c;
			c=max(c,l[i]);
			f[i]=c; //LL ///
		}
		for(int i=1; i<=n; ++i)printf("%d ",f[i]);puts("");
	}
}