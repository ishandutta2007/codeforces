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
int an=0,n,d[10];
void check(int x){
    while(x){
        if(d[x%10]){
            an++;
            return;
        }
        x/=10;
    }
}
int main(){
    int i,j,k,nn;
    cin>>n;
    nn=n;
    while(nn){
        d[nn%10]=1;
        nn/=10;
    }
    for(i=1;i*i<n;i++){
        if(n%i==0){
            check(i);
            check(n/i);
        }
    }
    if(i*i==n)check(i);
    printf("%d\n",an);
    return 0;
}