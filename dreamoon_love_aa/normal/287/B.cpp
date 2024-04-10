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
    int i,k;
    long long n,j=1;
    cin>>n>>k;
    if(n==1){
        puts("0");
        return 0;
    }
    for(i=k-1;i>0;i--){
        j+=i;
        if(j>=n){
            printf("%d\n",k-i);
            return 0;
        }
    }
    puts("-1");
    return 0;
}