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
bitset<1000001>p;
int main(){
    int i,j,k,n,a,b;
    p[1]=1;
    for(i=2;i<1000;i++)
        if(!p[i])
            for(j=i+i;j<=1000000;j+=i)p[j]=1;
    cin>>a>>b>>k;
    vector<int>pp;
    pp.pb(a-1);
    for(i=a;i<=b;i++)
        if(!p[i])pp.pb(i);
    if((int)pp.size()<=k)puts("-1");
    else{
        pp.pb(b+1);
        int an=0;
        for(i=0;i+k<pp.size();i++){
            an=max(an,pp[i+k]-pp[i]-1);
        }
        printf("%d\n",an+1);
    }
    return 0;
}