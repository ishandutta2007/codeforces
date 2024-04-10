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
    for(i=n-1;i>0;i--)
        if(a[i]<a[i-1])break;
    printf("%d\n",i);
    return 0;
}