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
#define SIZE 200001
using namespace std;
int d[SIZE],an[SIZE],een,cs,used[SIZE];
struct EDGE{
    int x,y,v,No;
    bool operator<(const EDGE& b)const{return v<b.v;}
}e[SIZE];
struct EE{
    int x,y,No;
    EE(int _x=0,int _y=0,int _No=0){x=_x,y=_y,No=_No;}
    bool operator<(const EE& b)const{return x<b.x||(x==b.x&&y<b.y);}
}ee[SIZE];
int find(int x){return x!=d[x]?(d[x]=find(d[x])):x;}
bool same(int x,int y){
    return find(x)==find(y);
}
void uu(int x,int y){
    d[find(x)]=find(y);
}
int nn[SIZE],st[SIZE],e_used[SIZE],MM,back[SIZE];
void dfs(int x){
    int i,j;
    used[x]=cs;
    nn[x]=MM;
    back[x]=++MM;
    for(i=st[x];i<een&&ee[i].x==x;i++){
        if(e_used[ee[i].No]==cs)continue;
        e_used[ee[i].No]=cs;
        if(used[ee[i].y]==cs){
            an[ee[i].No]=1;
            back[x]=min(back[x],nn[ee[i].y]);
        }
        else{
            dfs(ee[i].y);
            if(back[ee[i].y]<=nn[ee[i].x])an[ee[i].No]=1;
            back[x]=min(back[x],back[ee[i].y]);
        }
    }
}
int main(){
    int i,j,k,n,m;
    cin>>n>>m;
    for(i=0;i<m;i++){cin>>e[i].x>>e[i].y>>e[i].v;e[i].No=i;}
    sort(e,e+m);
    for(i=1;i<=n;i++)d[i]=i;
    for(i=0;i<m;i+=j){
        een=0;
        for(j=0;i+j<m&&e[i+j].v==e[i].v;j++){
            if(same(e[i+j].x,e[i+j].y))an[e[i+j].No]=-1;
            else{
                ee[een++]=EE(find(e[i+j].x),find(e[i+j].y),e[i+j].No);
                ee[een++]=EE(find(e[i+j].y),find(e[i+j].x),e[i+j].No);
            }
        }
        sort(ee,ee+een);
        cs++;
        for(j=0;j<een;j++){
            if(!j||ee[j].x!=ee[j-1].x)st[ee[j].x]=j;
        }
        for(j=0;j<een;j++){
            if(used[ee[j].x]!=cs){
                MM=0;
                dfs(ee[j].x);
            }
        }
        for(j=0;i+j<m&&e[i+j].v==e[i].v;j++){
            if(!same(e[i+j].x,e[i+j].y))uu(e[i+j].x,e[i+j].y);
        }
    }
    for(i=0;i<m;i++){
        if(an[i]==-1)puts("none");
        else if(an[i]==1)puts("at least one");
        else puts("any");
    }
    return 0;
}