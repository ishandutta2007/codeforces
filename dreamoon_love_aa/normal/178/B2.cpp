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
int d[SIZE];
struct EDGE{
};
vector<int>e[SIZE],new_e[SIZE];
int order[SIZE],oo,back[SIZE],cs,used[SIZE];
int find(int x){return x!=d[x]?(d[x]=find(d[x])):x;}
void uu(int x,int y){
    x=find(x);
    y=find(y);
    d[x]=y;
}
vector<int>bridge;
void dfs(int x,int last){
    used[x]=cs;
    order[x]=oo;
    back[x]=oo++;
    for(int i=0;i<e[x].size();i++){
        int y=e[x][i];
        if(y==last)continue;
        if(used[y]==cs){
            back[x]=min(back[x],order[y]);
        }
        else{
            dfs(y,x);
            back[x]=min(back[x],back[y]);
            if(back[y]<=order[x]){
                uu(x,y);
            }
            else{
                bridge.pb(x);
                bridge.pb(y);
            }
        }
    }
}
int de[SIZE],No,ha[SIZE*10],mi[SIZE*10];
void build(int x,int v){
    used[x]=cs;
    de[x]=v;
    order[x]=No;
    ha[No++]=x;
    for(int i=0;i<new_e[x].size();i++){
        int y=new_e[x][i];
        if(used[y]==cs)continue;
        build(y,v+1);
        ha[No++]=x;
    }
}
void create(int id,int L,int R){
    if(L==R){
        mi[id]=de[ha[L]];
        return;
    }
    int MM=(L+R)/2;
    create(id*2,L,MM);
    create(id*2+1,MM+1,R);
    mi[id]=min(mi[id*2],mi[id*2+1]);
}
void build2(){
    create(1,1,No-1);
}
int qq(int id,int L,int R,int x,int y){
    if(x<=L&&R<=y)return mi[id];
    int MM=(L+R)/2;
    if(MM>=y)return qq(id*2,L,MM,x,y);
    if(MM<x)return qq(id*2+1,MM+1,R,x,y);
    return min(qq(id*2,L,MM,x,y),qq(id*2+1,MM+1,R,x,y));
}
int com(int x,int y){
    //printf("[%d,%d]\n",order[x],order[y]);
    return qq(1,1,No-1,min(order[x],order[y]),max(order[x],order[y]));
}
int main(){
    int i,j,k,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)d[i]=i;
    while(m--){
        int x,y;
        scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
    }
    cs++;
    dfs(1,0);
    for(i=0;i<bridge.size();i+=2){
        new_e[find(bridge[i])].pb(find(bridge[i+1]));
        new_e[find(bridge[i+1])].pb(find(bridge[i]));
    }
    cs++;
    No=1;
    build(find(1),0);
    build2();
    //for(i=1;i<No;i++)printf("(%d,%d)",ha[i],de[ha[i]]);
    int Q;
    scanf("%d",&Q);
    while(Q--){
        int x,y;
        scanf("%d%d",&x,&y);
        x=find(x);
        y=find(y);
        if(x==y){
            puts("0");
        }
        else{
            //printf("[%d,%d,%d]\n",de[x],de[y],com(x,y));
            printf("%d\n",de[x]+de[y]-com(x,y)*2);
        }
    }
    return 0;
}