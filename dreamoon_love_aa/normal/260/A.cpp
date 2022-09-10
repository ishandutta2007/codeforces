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
    int i,j,k,n,a,b;
    cin>>a>>b>>n;
    k=a%b;
    for(i=0;i<n;i++){
        for(j=0;j<10;j++){
            if((k*10+j)%b==0){
                res.pb(j);
                k=0;
                break;
            }
        }
        if(j==10)break;
    }
    if(i<n)puts("-1");
    else{
        printf("%d",a);
        for(i=0;i<res.size();i++)printf("%d",res[i]);
        puts("");
    }
    return 0;
}