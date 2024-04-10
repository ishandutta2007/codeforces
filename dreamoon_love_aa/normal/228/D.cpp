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
#define SIZE 100001
long long d[5][10][SIZE];
int a[SIZE];
void insert(long long dd[],int x,long long v){
    while(x<SIZE){
        dd[x]+=v;
        x+=x&-x;
    }
}
long long qq(long long dd[],int x){
    long long res=0;
    while(x){
        res+=dd[x];
        x-=x&-x;
    }
    return res;
}
int f(int x,int d,int offset){
    x-=offset;
    x%=(d*2-2);
    if(x<0)x+=d*2-2;
    if(!x)return 2;
    if(x<=d)return x;
    return 2*d-x;
}
int main(){
    int i,j,k,n,Q;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        for(j=2;j<=6;j++)
            for(k=0;k<j*2-2;k++)
                insert(d[j-2][k],i,(long long)a[i]*f(i,j,k));
    }
    scanf("%d",&Q);
    while(Q--){
        int ty;
        scanf("%d",&ty);
        if(ty==2){
            int ll,rr,z;
            scanf("%d%d%d",&ll,&rr,&z);
            printf("%I64d\n",qq(d[z-2][(ll-1)%(2*z-2)],rr)-qq(d[z-2][(ll-1)%(2*z-2)],ll-1));
        }
        else{
            int p,v;
            scanf("%d%d",&p,&v);
            for(j=2;j<=6;j++)
                for(k=0;k<j*2-2;k++)
                    insert(d[j-2][k],p,(long long)(v-a[p])*f(p,j,k));
            a[p]=v;
        }
    }
    return 0;
}