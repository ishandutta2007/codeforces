#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
const double eps=1e-9;
int main(){
    int i,j,k,n,a,b,m,dx,dy,dz;
    scanf("%d%d%d",&a,&b,&m);
    scanf("%d%d%d",&dx,&dy,&dz);
    double t=m*-1./dy;
    double nx=a*0.5+t*dx;
    double nz=t*dz;
    nx-=floor(nx/(2*a)+eps)*(2*a);
    nz-=floor(nz/(2*b)+eps)*(2*b);
    if(nx>a)nx=2*a-nx;
    if(nz>b)nz=2*b-nz;
    printf("%.9lf %.9lf\n",nx,nz);
    return 0;
}