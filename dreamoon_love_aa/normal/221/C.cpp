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
#define SIZE 100001
int a[SIZE],b[SIZE];
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    for(i=0;i<n;i++)
        b[i]=a[i];
    sort(b,b+n);
    int cnt=0;
    for(i=0;i<n;i++){
        if(a[i]!=b[i])cnt++;
    }
    puts(cnt<=2?"YES":"NO");
    return 0;
}