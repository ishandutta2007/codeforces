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
#define SIZE 2222
int d[SIZE];
int find(int x){return x!=d[x]?(d[x]=find(d[x])):x;}
void uu(int x,int y){
    x=find(x);
    y=find(y);
    if(x!=y)d[x]=y;
}
int main(){
    int i,j,k,n,m;
    const int MOD=1000000007;
    long long an=1;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;i++)d[i]=i;
    for(i=0;i+k<=n;i++)
        for(j=0;j<k-1-j;j++)uu(d[i+j],d[i+k-1-j]);
    for(i=0;i<n;i++)
        if(d[i]==i)an=an*m%MOD;
    cout<<an<<endl;
    return 0;
}