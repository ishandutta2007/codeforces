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
int a[20000];
int main(){
    int i,j,k,n;
    cin>>n>>k;
    for(i=0;i<=2*n;i++)scanf("%d",&a[i]);
    for(i=1;i<=n&&k;i++){
        if(a[2*i-1]>a[2*i-2]+1&&a[2*i-1]>a[2*i]+1){
            k--;
            a[2*i-1]--;
        }
    }
    for(i=0;i<=2*n;i++){
        if(i)printf(" ");
        printf("%d",a[i]);
    }
    puts("");
    return 0;
}