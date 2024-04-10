#include<cstdio>
inline int read(){
	int a=0;char c=getchar();
	for(;c<48||c>57;c=getchar());for(;c>47&&c<58;a=a*10+c-48,c=getchar());
	return a;
}
int n,a,b,p[20],fl[20],t[20],k;
int main(){
	int f;
	n=read();
	a=read();b=read();
	for(int i=2;i*i<=a;i++){
	  f=0;
	  for(;a%i==0;)a/=i,f=1;
	  if(f)p[++k]=i;
	}if(a>1)p[++k]=a;
	for(int i=2;i*i<=b;i++){
	  f=0;
	  for(;b%i==0;)b/=i,f=1;
	  if(f)p[++k]=i;
	}if(b>1)p[++k]=b;
	for(;--n;){
	  a=read();b=read();
	  for(int j=1;j<=k;j++)
		if(a%p[j]&&b%p[j])fl[j]=1;
	}
	for(int i=1;i<=k;i++)if(!fl[i])
	  return 0*printf("%d",p[i]);
	return 0*puts("-1");
}