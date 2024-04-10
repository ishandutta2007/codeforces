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
int a[100];
double an[100];
int main(){
    int i,j,k,n,b,all=0;
    cin>>n>>b;
    all=b;
    for(i=0;i<n;i++){cin>>a[i];all+=a[i];}
    double v=1.*all/n;
    for(i=0;i<n;i++){
        an[i]=v-a[i];
        if(an[i]<-1e-9)break;
    }
    if(i==n){
        for(i=0;i<n;i++)printf("%.9lf\n",an[i]);
    }
    else puts("-1");
    return 0;
}