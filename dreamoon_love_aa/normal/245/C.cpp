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
int d[1001];
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=1;i<=n;i++)cin>>d[i];
    if(n<3||n%2==0){
        puts("-1");
        return 0;
    }
    int an=0;
    for(j=(n-1)/2;j>0;j--){
        int tmp=max(d[j*2],d[j*2+1]);
        if(j==1)tmp=max(tmp,d[1]);
        if(tmp>0){
            an+=tmp;
            d[j]-=tmp;
            
        }
    }
    cout<<an<<endl;
    return 0;
}