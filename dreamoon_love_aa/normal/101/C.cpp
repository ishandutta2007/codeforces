#include<stdio.h>
#include<algorithm>
using namespace std;
long long Ax,Ay,Bx,By,Cx,Cy,verCx,verCy;
long long sqr(long long x){return x*x;}
bool check(long long Dx,long long Dy){
    long long aa=Dx*Cx+Dy*Cy,bb=Dx*verCx+Dy*verCy,l2=sqr(Cx)+sqr(Cy);
    if(l2==0){
        return Dx==0&&Dy==0;
    }
    return aa%l2==0&&bb%l2==0;
}
int main(){
    int i;
    scanf("%I64d%I64d",&Ax,&Ay);
    scanf("%I64d%I64d",&Bx,&By);
    scanf("%I64d%I64d",&Cx,&Cy);
    verCx=-Cy,verCy=Cx;
    for(i=0;i<4;i++){
        swap(Ax,Ay);
        Ax=-Ax;
        if(check(Bx-Ax,By-Ay))break;
    }
    if(i<4)puts("YES");
    else puts("NO");
    return 0;
}