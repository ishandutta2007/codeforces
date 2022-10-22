#include<cstdio>
#define max(a,b)((a)>(b)?(a):(b))
const int N=101;
int n,m,k,a[N];
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<n;i++){
	  if(a[i]<a[i+1]-k)m-=(a[i+1]-k)-a[i];
	  if(m<0){puts("NO");goto Brk;}
	  if(a[i]>max(a[i+1]-k,0))m+=a[i]-max(a[i+1]-k,0);
	}
	puts("YES");
	Brk:;
	}return 0;
}