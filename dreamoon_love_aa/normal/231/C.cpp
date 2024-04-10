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
#define SIZE 100010
long long a[SIZE];
int main(){
    int i,j,k,n;
    long long an1=0,an2=0;
    cin>>n>>k;
    for(i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    long long now=0;
    for(i=j=0;i<n;i++){
        while(j+1<n&&(a[j+1]-a[j])*(j-i+1)+now<=k){
            now+=(a[j+1]-a[j])*(j-i+1);
            j++;
        }
        if(an1<j-i+1){
            an1=j-i+1;
            an2=a[j];
        }
        now-=a[j]-a[i];
    }
    printf("%I64d %I64d\n",an1,an2);
    return 0;
}