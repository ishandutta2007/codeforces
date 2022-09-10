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
    cin>>n;
    if(n&1)puts("-1");
    else{
        for(i=1;i<=n;i++){
            if(i!=1)printf(" ");
            if(i&1)printf("%d",i+1);
            else printf("%d",i-1);
        }
        puts("");
    }
    return 0;
}