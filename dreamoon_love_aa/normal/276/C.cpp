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
#define SIZE 200002
int a[SIZE],d[SIZE];
int main(){
    int i,j,k,n,q;
    cin>>n>>q;
    for(i=1;i<=n;i++)cin>>a[i];
    while(q--){
        cin>>i>>j;
        d[i]++;
        d[j+1]--;
    }
    for(i=2;i<=n;i++)d[i]+=d[i-1];
    sort(d+1,d+1+n);
    sort(a+1,a+1+n);
    long long an=0;
    for(i=1;i<=n;i++)an+=(long long)a[i]*d[i];
    cout<<an<<endl;
    return 0;
}