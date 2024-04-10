#include<cstdio>
inline int read(){
	int a=0;char c=getchar();
	for(;c<48||c>57;c=getchar());for(;c>47&&c<58;a=a*10+c-48,c=getchar());
	return a;
}
int n,x,m=2e9,cx,cm,a;
int main(){
	n=read();
	for(;n--;){
	  a=read();
	  if(a==x)cx++;if(a==m)cm++;
	  if(a>x)cx=1,x=a;if(a<m)cm=1,m=a;
	}printf("%d %I64d",x-m,m==x?1ll*cm*(cm-1)/2:1ll*cm*cx);
	return 0;
}