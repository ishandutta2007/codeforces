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
long long a[200011],mi[200011];
int n;
void go(long long d[]){
    int i,j;
    mi[n+1]=1100000000;
    for(i=n;i>0;i--)mi[i]=min(mi[i+1],d[i]);
    long long mm=1100000000;
    for(i=1;i<=n;i++){
        if(mi[i+1]>=d[i]+1&&mm>=d[i]){
            for(j=1;j<i;j++)d[j]-=d[i];
            for(j=i+1;j<=n;j++)d[j]-=d[i]+1;
            d[i]+=d[i]*(i-1)+(d[i]+1)*(n-i);
            return;
        }
    }
}
int main(){
    int i,j,k,x ;
    scanf("%d%d",&n,&x);
    for(i=1;i<=n;i++){
        cin>>a[i];
        a[n+i]=a[i];
    }
    go(a+x);
    for(i=1;i<=x;i++)a[i]=a[i+n];
    for(i=1;i<=n;i++){
        if(i!=1)printf(" ");
        cout<<a[i];
    }
    cout<<endl;
    return 0;
}