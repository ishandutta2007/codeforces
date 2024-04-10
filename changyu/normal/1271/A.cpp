#include<cstdio>
#define min(a,b)((a)<(b)?(a):(b))
#define max(a,b)((a)>(b)?(a):(b))
int a,b,c,d,e,f,ans;
int main(){
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	for(int i=0;i<=100000;i++)if(a>=i&&d>=i)
	  ans=max(ans,i*e+f*min(b,min(c,d-i)));
	printf("%d",ans);
	return 0;
}