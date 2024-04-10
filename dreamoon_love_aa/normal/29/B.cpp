#include<stdio.h>
#include<math.h>
main(){
    int l,d,v,g,r;
    scanf("%d%d%d%d%d",&l,&d,&v,&g,&r);
    if(d%((g+r)*v)<g*v)printf("%.8lf\n",(double)l/v);
    else printf("%.8lf\n",ceil((double)d/v/(g+r))*(g+r)+(double)(l-d)/v);
}