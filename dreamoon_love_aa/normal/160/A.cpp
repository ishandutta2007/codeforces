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
int a[111];
int main(){
    int i,j,k,n,sum=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a,a+n);
    k=0;
    for(i=1;i<=n;i++){
        k+=a[n-i];
        if(k>sum-k)break;
    }
    cout<<i<<endl;
    return 0;
}