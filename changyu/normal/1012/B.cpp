#include<cstdio>
const int N=2e5+1;
int n,m,q,p[N+N],k=n+m;
int Find(int k){return p[k]==k?k:p[k]=Find(p[k]);}
int main()
{
	int x,y;
	scanf("%d%d%d",&n,&m,&q);k=n+m;
	for(int i=1;i<=n+m;i++)p[i]=i;
	for(;q--;){
	  scanf("%d%d",&x,&y);y+=n;
	  if(Find(x)!=Find(y))p[Find(x)]=Find(y),k--;
	}
	printf("%d",k-1);
	return 0;
}