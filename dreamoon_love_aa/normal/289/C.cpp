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
    cin>>n>>k;
    if(k==1){
        if(n==1)puts("a");
        else puts("-1");
        return 0;
    }
    if(k>n){
        cout<<"-1"<<endl;
        return 0;
    }
    for(i=0;i<n-(k-2);i++){
        if(i&1)printf("b");
        else printf("a");
    }
    for(i=2;i<k;i++)printf("%c",'a'+i);
    puts("");
    return 0;
}