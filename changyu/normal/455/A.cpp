#include<cstdio>
inline int read(){
	int a=0;char c=getchar();
	for(;c<48||c>57;c=getchar());for(;c>47&&c<58;a=a*10+c-48,c=getchar());
	return a;
}
int m;long long f1,f,f2,a[100001];
int main(){
	long long t;
	m=read();
	for(;m--;)t=read(),a[t]+=t;
	f=a[1];f1=a[2];f2=a[3]+a[1];
	for(int i=4;i<=100000;i++)
	  t=(f>f1?f:f1)+a[i],f=f1,f1=f2,f2=t;
	printf("%I64d",f1>f2?f1:f2);
	return 0;
}