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
void print(int r,int n){
    int i,j;
    for(i=0;i<n;i++,puts("")){
        for(j=0;j<n;j++){
            int tmp=min(min(i,j),min(n-1-i,n-1-j));
            if((tmp&1)^r)printf("b");
            else printf("w");
        }
    }
}
int main(){
    int i,j,k,n;
    cin>>n;
    if(n%2==1)puts("-1");
    else{
        for(i=1;i<=n;i++){
            if(i!=1)printf("\n");
            print(i&1,n);
        }
    }
    return 0;
}