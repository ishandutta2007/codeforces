#include<cstdio>
#include<algorithm>
int n,a[1000001],p,p1,b[10001];double x;
int main()
{
    int f,la;
    int T;scanf("%d",&T);for(;T--;){
    scanf("%d",&n);
    x=1e15;
    for(int i=1;i<=n;i++)scanf("%d",a+i),b[a[i]]++;
    std::sort(a+1,a+n+1);
    f=0;la=0;
    for(int i=1;i<=n;i++){
      if(b[a[i]]>=4)
        {printf("%d %d %d %d\n",a[i],a[i],a[i],a[i]);f=1;break;}
      if(b[a[i]]>=2&&a[i]!=a[la]){
        if(la&&x>4.0*a[i]/a[la]+4.0*a[la]/a[i]+8)
          x=4.0*a[i]/a[la]+4.0*a[la]/a[i]+8,p=i,p1=la;
        la=i;
      }
    }
    if(!f)printf("%d %d %d %d\n",a[p],a[p],a[p1],a[p1]);
    for(int i=1;i<=n;i++)b[a[i]]--;
    }return 0;
}