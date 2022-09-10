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
int d[20000],a[20000];
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i];
    d[0]=d[n+1]=1;
    for(i=1;i<=1000;i++){
        for(j=1;j<=n;j++)
            if(a[j]==i){
                d[j]=1;
                if(d[j-1]||d[j+1])break;
            }
        if(j<=n)break;
    }
    printf("%d\n",i);
    return 0;
}