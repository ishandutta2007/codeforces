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
int a[100000],an[100000];
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j,k,n,res=10000000;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    for(i=k=0;i<n;i++){
        if(a[i]>=0){
            k++;
        }
        an[i]+=k;
    }
    for(i=n-1,k=0;i>0;i--){
        if(a[i]<=0){
            k++;
        }
        an[i-1]+=k;
    }
    for(i=0;i<n-1;i++)res=min(res,an[i]);
    cout<<res<<endl;
    return 0;
}