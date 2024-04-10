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
int d[3];
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>k;
        d[i%3]+=k;
    }
    k=0;
    for(i=0;i<3;i++){
        if(d[i]>k)k=d[i];
    }
    if(d[0]==k)puts("chest");
    else if(d[1]==k)puts("biceps");
    else puts("back");
    return 0;
}