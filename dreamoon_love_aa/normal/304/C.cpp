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
    if(n%2==0){
        puts("-1");
        return 0;
    }
    for(i=0;i<n;i++){
        if(i)printf(" ");
        printf("%d",i);
    }
    puts("");
    for(i=0;i<n;i++){
        if(i)printf(" ");
        printf("%d",i);
    }
    puts("");
    for(i=0;i<n;i++){
        if(i)printf(" ");
        printf("%d",i*2%n);
    }
    puts("");
    return 0;
}