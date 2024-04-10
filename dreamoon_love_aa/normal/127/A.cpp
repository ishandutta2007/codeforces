#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
int x[1000],y[1000];
double sqr(double x){return x*x;}
int main(){
    int i,j,k,n;
    double an=0;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)scanf("%d%d",&x[i],&y[i]);
    for(i=1;i<n;i++)
        an+=sqrt(sqr(x[i]-x[i-1])+sqr(y[i]-y[i-1]));
    printf("%.10lf\n",an*k/50);
    return 0;
}