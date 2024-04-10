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
#define SIZE 100010
int a[SIZE],an[SIZE];
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    if(n==1){
        puts("+");
        return 0;
    }
    int now=a[n-1];
    for(i=n-2;i>=0;i--){
        if(now>=a[i]){
            an[i]^=1;
            an[i+1]^=1;
            now-=a[i];
        }
        else{
            an[i+1]^=1;
            now=a[i]-now;
        }
    }
    for(i=now=0;i<n;i++){
        now^=an[i];
        if(now)printf("-");
        else printf("+");
    }
    puts("");
    return 0;
}