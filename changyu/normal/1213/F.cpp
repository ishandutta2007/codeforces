#include<cstdio>
#define min(a,b)((a)<(b)?(a):(b))
#define max(a,b)((a)>(b)?(a):(b))
const int N=2e5+3;
int n,k,a[N],b[N],c[N],d;char s[N],t;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++)scanf("%d",b+i);
	t='a';
	for(int i=1,j=1;i<=n;i++){
	  if(!c[a[i]])c[a[i]]=1,d++;
	  if(!c[b[i]])c[b[i]]=1,d++;
	  if(d==i){
		for(;j<=i;j++)s[a[j]]=t;
		if(t<'z'&&i<n)t++;
	  }
	}
	if(t<96+k)return 0*puts("NO");
	puts("YES");
	printf("%s",s+1);
	return 0;
}