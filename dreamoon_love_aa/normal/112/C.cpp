#include<stdio.h>
#include<iostream>
using namespace std;
int d[100000];
int main(){
    int n,y,i;
    long long x,now;
    cin>>n>>x>>y;
    if(n>y){
        puts("-1");
        return 0;
    }
    d[0]=y-n+1;
    for(i=1;i<n;i++)d[i]=1;
    now=0;
    for(i=0;i<n;i++){
        now+=(long long)d[i]*d[i];
        if(now>=x)break;
    }
    if(i==n)puts("-1");
    else{
        for(i=0;i<n;i++)cout<<d[i]<<endl;
    }
    return 0;
}