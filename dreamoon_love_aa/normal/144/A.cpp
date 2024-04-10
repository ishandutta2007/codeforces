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
int a[111];
int main(){
    int i,j,k,n,now;
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i];
    now=0;
    for(i=1;i<=n;i++){
        if(a[i]>now){
            now=a[i];
            j=i;
        }
    }
    now=111;
    for(i=n;i>0;i--){
        if(a[i]<now){
            now=a[i];
            k=i;
        }
    }
    printf("%d\n",j-1+n-k-(j>k));
    return 0;
}