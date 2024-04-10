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
int a[4999];
int main(){
    int i,j,k,n;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(i=0;i<n;i++){
        int cnt=0;
        for(j=0;j<n;j++){
            if(a[j]>=a[i])cnt++;
        }
        if(cnt==k){
            printf("%d %d\n",a[i],a[i]);
            return 0;
        }
    }
    puts("-1");
    return 0;
}