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
int a[SIZE],b[SIZE];
int x[SIZE<<2],y[SIZE<<2],need[SIZE<<2],xx,yy;
int qq(int L,int R,int id,int v){
    if(need[id]==1){
        return a[v-y[id]+x[id]];
    }
    if(L==R)return b[v];
    int mm=(L+R)>>1;
    if(v<=mm)return qq(L,mm,id*2,v);
    else return qq(mm+1,R,id*2+1,v);
}
void insert(int L,int R,int id,int qqll,int rr){
    if(R<qqll||rr<L)return;
    if(qqll<=L&&R<=rr){
        need[id]=1;
        x[id]=xx;
        y[id]=yy;
        return;
    }
    int mm=(L+R)>>1;
    if(need[id]==1){
        need[id]=0;
        need[id*2]=need[id*2+1]=1;
        x[id*2]=x[id*2+1]=x[id];
        y[id*2]=y[id*2+1]=y[id];
    }
    insert(L,mm,id*2,qqll,rr);
    insert(mm+1,R,id*2+1,qqll,rr);
}
int main(){
    int i,j,k,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(i=1;i<=m;i++){
        int ty;
        scanf("%d",&ty);
        if(ty==2){
            int x;
            scanf("%d",&x);
            printf("%d\n",qq(1,n,1,x));
        }
        else{
            int x,y;
            scanf("%d%d%d",&xx,&yy,&k);
            insert(1,n,1,yy,yy+k-1);
        }
    }
    return 0;
}