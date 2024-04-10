#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    long long k,l,an=0,now=1;
    cin>>k>>l;
    if(k==1){
        if(l==1){
            puts("YES\n0");
        }
        else puts("NO");
        return 0;
    }
    while(now<l){
        now*=k;
        an++;
    }
    if(now==l){
        puts("YES");
        printf("%I64d\n",an-1);
    }
    else puts("NO");
    return 0;
}