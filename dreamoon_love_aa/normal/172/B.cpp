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
int tt[10000000];
long long r[1000000];
int main(){
    int i,j,k,n;
    long long a,b,m;
    memset(tt,-1,sizeof(tt));
    cin>>a>>b>>m>>r[0];
    tt[r[0]]=0;
    for(i=1;;i++){
        r[i]=(a*r[i-1]+b)%m;
        if(tt[r[i]]!=-1)break;
        tt[r[i]]=i;
    }
    cout<<i-tt[r[i]]<<endl;
    return 0;
}