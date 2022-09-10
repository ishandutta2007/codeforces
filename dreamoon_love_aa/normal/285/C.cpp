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
int a[400000];
int main(){
    int i,j,k,n;
    long long an=0;
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(i=1;i<=n;i++)an+=abs(a[i]-i);
    cout<<an<<endl;
    return 0;
}