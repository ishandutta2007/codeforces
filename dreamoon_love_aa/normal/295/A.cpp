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
long long q[SIZE][3],d1[SIZE],d2[SIZE],a[SIZE];
void insert(long long d[],int x,long long v){
    while(x){
        d[x]+=v;
        x-=x&-x;
    }
}
long long qq(long long d[],int x){
    long long res=0;
    if(!x)return 0;
    while(x<SIZE){
        res+=d[x];
        x+=x&-x;
    }
    return res;
}
int main(){
    int i,j,k,n,m;
    cin>>n>>m>>k;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i<=m;i++)for(j=0;j<3;j++)cin>>q[i][j];
    for(i=1;i<=k;i++){
        int x,y;
        cin>>x>>y;
        insert(d1,y,1);
        insert(d1,x-1,-1);
    }
    for(i=1;i<=m;i++){
        long long cnt=qq(d1,i);
        insert(d2,q[i][1],cnt*q[i][2]);
        insert(d2,q[i][0]-1,-cnt*q[i][2]);
    }
    for(i=1;i<=n;i++){
        if(i!=1)printf(" ");
        cout<<a[i]+qq(d2,i);
    }
    puts("");
    return 0;
}