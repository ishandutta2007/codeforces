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
long long d[20][410000];
int a[100010];
int flag[20][410000];
void init(int lv,int id,int L,int R){
    if(L==R){
        if(a[L]&(1<<lv))d[lv][id]=1;
        return;
    }
    int M=(L+R)>>1;
    init(lv,id<<1,L,M);
    init(lv,(id<<1)|1,M+1,R);
    d[lv][id]=d[lv][id<<1]+d[lv][(id<<1)|1];
}
void flip(int lv,int id,int L,int R){
    d[lv][id]=R-L+1-d[lv][id];
}
void insert(int lv,int id,int L,int R,int ll,int rr){
    if(rr<L||ll>R)return;
    if(L>=ll&&R<=rr){
        flip(lv,id,L,R);
        flag[lv][id]^=1;
        return;
    }
    int mm=(L+R)>>1;
    if(flag[lv][id]){
        flag[lv][id]=0;
        flip(lv,id*2,L,mm);
        flip(lv,id*2+1,mm+1,R);
        flag[lv][id*2]^=1;
        flag[lv][id*2+1]^=1;
    }
    insert(lv,id*2,L,mm,ll,rr);
    insert(lv,id*2+1,mm+1,R,ll,rr);
    d[lv][id]=d[lv][id*2]+d[lv][id*2+1];
}
long long get(int lv,int id,int L,int R,int ll,int rr){
    if(rr<L||ll>R)return 0;
    if(L>=ll&&R<=rr)return d[lv][id];
    int M=(L+R)>>1;
    if(flag[lv][id]){
        flag[lv][id]=0;
        flip(lv,id*2,L,M);
        flip(lv,id*2+1,M+1,R);
        flag[lv][id*2]^=1;
        flag[lv][id*2+1]^=1;
    }
    long long res=0;
    res+=get(lv,id<<1,L,M,ll,rr);
    res+=get(lv,(id<<1)|1,M+1,R,ll,rr);
    d[lv][id]=d[lv][id*2]+d[lv][id*2+1];
    return res;
}
int main(){
    int i,j,k,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<20;i++)init(i,1,0,n-1);
    int qq;
    scanf("%d",&qq);
    while(qq--){
        int ty;
        scanf("%d",&ty);
        if(ty==1){
            int x,y;
            scanf("%d%d",&x,&y);
            x--;y--;
            long long res=0;
            for(i=0;i<20;i++){
                res+=get(i,1,0,n-1,x,y)<<i;
            }
            printf("%I64d\n",res);
        }
        else{
            int l,r,x;
            scanf("%d%d%d",&l,&r,&x);
            l--;r--;
            for(i=0;i<20;i++){
                if(x&(1<<i)){
                    insert(i,1,0,n-1,l,r);
                }
            }
        }
    }
    return 0;
}