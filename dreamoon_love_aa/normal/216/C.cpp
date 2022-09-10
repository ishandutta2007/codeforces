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
vector<int>an;
int main(){
    int i,j,k,n,m;
    cin>>n>>m>>k;
    if(m<n){
        if(k>1||n>m+1){
            printf("%d\n",k*2);
            for(i=0;i<k;i++)an.pb(1);
            an.pb(n);
            for(i=0;i<k-1;i++)an.pb(n+1);
        }
        else{
            printf("%d\n",k*2+1);
            an.pb(1);
            an.pb(n);
            an.pb(n+1);
        }
    }
    else{
        if(k==1&&n==2){
            printf("%d\n",k*2+2);
            for(i=1;i<=4;i++)an.pb(i);
        }
        else{
            printf("%d\n",k*2+1);
            for(i=1;i<=k;i++)an.pb(1);
            an.pb(n);
            for(i=0;i<k-1;i++)an.pb(n+1);
            an.pb(n+2);
        }
    }
    for(i=0;i<an.size();i++){
        if(i)printf(" ");
        printf("%d",an[i]);
    }
    puts("");
    return 0;
}