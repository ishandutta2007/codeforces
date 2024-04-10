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
    long long bb;
    cin>>n>>k;
    bb=n*(n-1)/2;
    if(k>=bb)puts("no solution");
    else{
        for(i=0;i<n;i++)printf("%d %d\n",0,i);
    }
    return 0;
}