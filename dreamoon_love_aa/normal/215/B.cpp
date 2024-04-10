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
#define SIZE 10000
int x[SIZE],y[SIZE],z[SIZE];
int main(){
    int i,j,k,n,m,A,B,xx=0,yy=0,zz=1000000000;
    cin>>n;
    for(i=0;i<n;i++){cin>>x[i];xx=max(xx,x[i]);}
    cin>>m;
    for(i=0;i<m;i++){cin>>y[i];yy=max(yy,y[i]);}
    cin>>k;
    for(i=0;i<k;i++){cin>>z[i];zz=min(zz,z[i]);}
    cin>>A>>B;
    double ll=0,rr=xx;
    for(i=0;i<100;i++){
        double mm=(ll+rr)*0.5;
        if((1.*(xx*xx-mm*mm)*yy)/(1.*mm*mm*zz)*B<A)rr=mm;
        else ll=mm;
    }
    printf("%.12lf\n",(ll+rr)*0.5);
    return 0;
}