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
int sqr(int x){return x*x;}
int main(){
    int i,j,k,n,x1,y1,x2,y2,r1,r2;
    scanf("%d%d%d",&x1,&y1,&r1);
    scanf("%d%d%d",&x2,&y2,&r2);
    if(sqr(r1-r2)<sqr(x1-x2)+sqr(y1-y2))printf("%.12lf\n",max(0.,sqrt(sqr(x1-x2)+sqr(y1-y2))-r1-r2)*0.5);
    else printf("%.12lf\n",(max(r1,r2)-sqrt(sqr(x1-x2)+sqr(y1-y2))-min(r2,r1))*0.5);
    return 0;
}