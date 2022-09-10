#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
int main(){
    int i,x,n,a[128];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        a[x]=i+1;
    }
    for(i=1;i<=n;i++){
        if(i!=1)putc(' ',stdout);
        printf("%d",a[i]);
    }
    puts("");
    return 0;
}