#include<cstdio>
int n,m,x,y;
int main()
{
    scanf("%d%d",&n,&m);
    for(;m--;){
      scanf("%d%d",&x,&y);
      if(n&1)printf("%I64d\n",1ll*(x-1)*n+y&1?1ll*(x-1)*n+y+1>>1:(1ll*n*n>>1)+1+(1ll*(x-1)*n+y>>1));
      else printf("%I64d\n",((x^y)&1)*(1ll*n*n>>1)+1ll*(x-1)*(n>>1)+(y+1>>1));
    }return 0;
}