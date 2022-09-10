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
    cin>>n>>k;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=n;i>0&&a[i]==a[n];i--);
    if(i>=k)puts("-1");
    else printf("%d\n",i);
    return 0;
}