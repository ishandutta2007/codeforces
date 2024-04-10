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
long long a[501][501],q[501],d[501][501];
#define MAX 100000000000000000ll
long long an[501];
bool fresh(long long &x,long long v){
    if(x>v){x=v;return 1;}
    return 0;
}
long long go(long long lt[],int n){
    if(n==1)return 0;
    int i,j,k;
    long long res=0;
    for(i=1;i<n;i++){
        d[lt[0]][lt[i]]=MAX;
        d[lt[i]][lt[0]]=MAX;
        for(j=1;j<n;j++)fresh(d[lt[0]][lt[i]],d[lt[j]][lt[i]]+a[lt[0]][lt[j]]);
        for(j=1;j<n;j++)fresh(d[lt[i]][lt[0]],d[lt[i]][lt[j]]+a[lt[j]][lt[0]]);
    }
    for(i=1;i<n;i++)
        for(j=1;j<n;j++)fresh(d[lt[i]][lt[j]],d[lt[i]][lt[0]]+d[lt[0]][lt[j]]);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)res+=d[lt[i]][lt[j]];
    return res;
}
int main(){
    int i,j,k,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)scanf("%d",&a[i][j]);
    for(i=1;i<=n;i++)scanf("%d",&q[i]);
    for(i=n;i>=1;i--)
        an[i]=go(q+i,n-i+1);
    for(i=1;i<=n;i++){
        if(i!=1)printf(" ");
        cout<<an[i];
    }
    puts("");
    return 0;
}