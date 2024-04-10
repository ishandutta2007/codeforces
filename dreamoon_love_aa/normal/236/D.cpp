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
#define SIZE 100000
double p[SIZE];
int main(){
    int i,j,k,n;
    scanf("%d",&n);
    double now,an=0;
    for(i=0;i<n;i++){scanf("%lf",&p[i]);an+=p[i];}
    now=0;
    for(i=0;i<n;i++){
        an+=now*p[i];
        now=(now+1)*p[i];
    }
    now=0;
    for(i=n-1;i>=0;i--){
        an+=now*p[i];
        now=(now+1)*p[i];
    }
    printf("%.15lf\n",an);
    return 0;
}