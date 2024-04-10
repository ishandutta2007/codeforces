#include<cstdio>
#include<algorithm>
inline int read(){
	int a=0;char c=getchar();
	for(;c<48||c>57;c=getchar());for(;c>47&&c<58;a=a*10+c-48,c=getchar());
	return a;
}
const int N=1e5+1;
int m,t,f[N],u[N],v[N],c[N],ans=2e9;
int main(){
	read(),m=read();t=read();
	for(int i=m;i;i--)u[i]=read(),v[i]=read(),c[i]=read();
	for(;t--;)f[read()]=1;
	for(int i=m;i;i--)if(f[u[i]]^f[v[i]]&&c[i]<ans)ans=c[i];
	return 0*printf("%d",ans==2e9?-1:ans);
}