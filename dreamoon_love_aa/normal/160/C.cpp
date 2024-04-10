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
int a[SIZE];
int main(){
    int i,n;
    long long j,k;
    cin>>n>>k;
    for(i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(i=0;i<n;i+=j){
        for(j=1;i+j<n&&a[i+j]==a[i];j++);
        if(j*n>=k){
            printf("%d %d\n",a[i],a[(k-1)/j]);
            return 0;
        }
        else k-=j*n;
    }
    return 0;
}