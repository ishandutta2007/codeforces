#include<stdio.h>
#include<iostream>
using namespace std;
main(){
    int n,i;
    long long j;
    scanf("%d",&n);
    if(n==2)puts("-1");
    else{
        for(i=0,j=3;i<n-2;i++){
            j*=2;
            cout<<j<<endl;
        }
        puts("10\n15");
    }
}