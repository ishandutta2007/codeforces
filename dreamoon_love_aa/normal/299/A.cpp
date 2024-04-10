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
int a[100010];
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    if(n==1){
        printf("%d\n",a[0]);
        return 0;
    }
    int gg=__gcd(a[0],a[1]);
    for(i=2;i<n;i++)gg=__gcd(gg,a[i]);
    for(i=0;i<n;i++)
        if(a[i]==gg)break;
    if(i==n)puts("-1");
    else printf("%d\n",gg);
    return 0;
}