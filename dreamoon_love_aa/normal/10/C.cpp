#include<stdio.h>
#include<iostream>
using namespace std;
long long d[9];
main(){
    int n,i,j;
    long long an=0;
    scanf("%d",&n);
    for(i=0;i<9;i++){
        d[i]=n/9;
        if(n%9>=i)d[i]++;
    }
    d[0]--;
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
            an+=d[i]*d[j]*d[(i*j)%9];
    for(i=1;i<=n;i++)an-=n/i;
    cout<<an<<endl;
}