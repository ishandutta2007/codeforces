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
    int i,j,an1,an2;
    long long x,y,n;
    long double dd=110000000;
    cin>>x>>y>>n;
    for(i=1;i<=n;i++){
        long long k=(long long)x*i/y;
        if(fabs(x*(long double)1./y-k*(long double)1./i)+1e-15<dd){
            dd=fabs(x*(long double)1./y-k*(long double)1./i);
            an1=k;
            an2=i;
        }
        if(fabs(x*(long double)1./y-(k+1)*(long double)1./i)+1e-15<dd){
            dd=fabs(x*(long double)1./y-(k+1)*(long double)1./i);
            an1=k+1;
            an2=i;
        }
    }
    printf("%d/%d\n",an1,an2);
    return 0;
}