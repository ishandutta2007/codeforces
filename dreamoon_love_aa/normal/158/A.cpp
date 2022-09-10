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
int a[55];
int main(){
    int i,j,k,n,an=0;
    cin>>n>>k;
    for(i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(i=0;i<n-1-i;i++)swap(a[i],a[n-1-i]);
    if(a[k-1]==0)k=1;
    else k=a[k-1];
    for(i=0;i<n;i++)
        if(a[i]>=k)an++;
    cout<<an<<endl;
    return 0;
}