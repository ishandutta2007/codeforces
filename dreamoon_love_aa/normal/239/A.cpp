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
vector<int>res;
int main(){
    int i,j,k,n,y;
    cin>>y>>k>>n;
    for(i=y/k*k;i<=n;i+=k){
        if(i>=y+1)res.pb(i-y);
    }
    if(res.size()==0)puts("-1");
    else{
        printf("%d",res[0]);
        for(i=1;i<res.size();i++)printf(" %d",res[i]);
        puts("");
    }
    return 0;
}