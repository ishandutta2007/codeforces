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
int a[SIZE];
long long sum[SIZE],an[SIZE],one;
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    for(i=1;i<n;i++)one+=sum[i];
    int q;
    cin>>q;
    while(q--){
        long long x;
        cin>>x;
        if(x==1)cout<<one<<endl;
        else{
            long long now=1,tmp=1;
            long long res=0;
            while(n-now>0){
                res+=sum[n-now];
                tmp*=x;
                now+=tmp;
            }
            cout<<res<<endl;
        }
    }
    return 0;
}