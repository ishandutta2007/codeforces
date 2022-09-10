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
int a[1000000];
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j,k,n,an=0;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(i=0,j=0;i<n;i++){
        while(j<n&&a[i]*2>=a[j])j++;
        an=max(an,j-i);
    }
    printf("%d\n",n-an);
    return 0;
}