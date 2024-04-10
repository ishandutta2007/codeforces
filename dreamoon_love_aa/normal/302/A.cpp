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
    int i,j,k,n,m,one=0;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x==1)one++;
    }
    while(m--){
        cin>>j>>k;
        k=k-j+1;
        if(k%2==1)puts("0");
        else{
            if(k/2<=min(one,n-one))puts("1");
            else puts("0");
        }
    }    
    return 0;
}