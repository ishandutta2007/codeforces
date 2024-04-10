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
int main(){
    int i,j,k,n;
    double a,d,lan=0;
    cin>>n>>a>>d;
    for(i=0;i<n;i++){
        double t,v;
        scanf("%lf%lf",&t,&v);
        double base=v/a;
        double need=sqrt(2*d/a);
        if(need>base){
            double tmp=a*base*base*0.5;
            need=base+(d-tmp)/v;
        }
        if(t+need<lan){
            printf("%lf\n",lan);
        }
        else{
            printf("%lf\n",t+need);
            lan=t+need;
        }
    }
    return 0;
}