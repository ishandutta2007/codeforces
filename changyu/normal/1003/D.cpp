#include<cstdio>
#include<algorithm>
using namespace std;
#define lg(a)(31-__builtin_clz(a))
int m,n,a[200002],b[31],t,k,ans,f,l,g;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",a+i),b[lg(a[i])]++;
    sort(a+1,a+1+n);
    a[n+1]=2147483647;
    for(;m--;)
    {
      scanf("%d",&t);
      ans=0;f=1;g=0;
      for(;t;){
        k=lower_bound(a+1,a+n+1,t)-a;
        if(a[k]>t)k--;
        l=lg(a[k]);
        for(;l>=0;l--)if(!((1<<l)&g))break;
        if(l<0){puts("-1");f=0;break;}
        if((1ll*b[l]<<l)>t)ans+=t>>l,t&=(1<<l)-1;
        else t-=b[l]<<l,ans+=b[l];
        g+=1<<l;
      }if(f)printf("%d\n",ans);
    }
	return 0;
}