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
    int i,j,k,n,m;
    cin>>n>>m;
    if(n==0){
        if(m==0)puts("0 0");
        else puts("Impossible");
    }
    else{
        printf("%d %d",n+max(0,m-n),n+max(m-1,0));
    }
    return 0;
}