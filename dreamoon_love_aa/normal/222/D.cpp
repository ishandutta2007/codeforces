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
#define SIZE 100000
int a[SIZE],b[SIZE];
int main(){
    int i,j,k,n,x;
    cin>>n>>x;
    for(i=0;i<n;i++)cin>>a[i];
    for(i=0;i<n;i++)cin>>b[i];
    sort(a,a+n);
    sort(b,b+n);
    int cnt=0;
    for(i=0,j=n-1;i<n;i++){
        if(a[i]+b[j]>=x){
            cnt++;
            j--;
        }
    }
    printf("1 %d\n",cnt);
    return 0;
}