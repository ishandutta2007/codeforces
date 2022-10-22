#include<cstdio>
#include<cmath>
#define p(a)1ll*(a)*(a)
int x,y,xx,yy,r;int main(){scanf("%d%d%d%d%d",&r,&x,&y,&xx,&yy);printf("%.lf",ceil(sqrt(p(x-xx)+p(y-yy))/(r*2)));return 0;}