
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
#define SIZE 2001
#define MAX 1111111111
int d[SIZE],dn;
struct data{
    int x,y,v;
}a[SIZE];
int en;
struct EDGE{
    int x,y,f,c,v;
    EDGE(int _x=1,int _y=1,int _f=0,int _c=0,int _v=0){x=_x,y=_y,f=_f,c=_c,v=_v;}
    void print(){printf("[%d,%d,%d,%d,%d]\n",x,y,f,c,v);}
}ee[SIZE*10];
vector<EDGE*>e[SIZE];
EDGE* r[SIZE];
int bfs[SIZE*SIZE],used[SIZE];
bool flow(){
    int mi[SIZE],i,j,k,last[SIZE];
    memset(used,0,sizeof(used));
    bfs[0]=0;
    for(i=0;i<=dn+1;i++)mi[i]=-MAX;
    mi[0]=0;
    for(i=0,j=1;i<j;i++){
        int x=bfs[i];
        used[x]=0;
        for(k=0;k<e[x].size();k++){
            int y,cc;
            if(x==e[x][k]->x){
                if(e[x][k]->f>0){
                    y=e[x][k]->y;
                    cc=e[x][k]->v;
                    if(mi[x]+cc>mi[y]){
                        mi[y]=mi[x]+cc;
                        last[y]=x;
                        r[y]=e[x][k];
                        if(!used[y]){
                            used[y]=1;
                            bfs[j++]=y;
                        }
                    }
                }
            }
            else{
                if(e[x][k]->f<e[x][k]->c){
                    y=e[x][k]->x;
                    cc=-e[x][k]->v;
                    if(mi[x]+cc>mi[y]){
                        mi[y]=mi[x]+cc;
                        last[y]=x;
                        r[y]=e[x][k];
                        if(!used[y]){
                            used[y]=1;
                            bfs[j++]=y;
                        }
                    }
                }
            }
        }
    }
    if(mi[dn+1]<=0)return 0;
    int now=dn+1;
    while(now){
        if(r[now]->x==now)r[now]->f++;
        else r[now]->f--;
        now=last[now];
    }
    return 1;
}
int main(){
    int i,j,k,n;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++){
        int s,t,c;
        scanf("%d%d%d",&s,&t,&c);
        a[i]=(data){s,s+t-1,c};
        d[dn++]=a[i].x;
        d[dn++]=a[i].y;
    }
    sort(d,d+dn);
    dn=unique(d,d+dn)-d;
    for(i=0;i<n;i++){
        a[i].x=lower_bound(d,d+dn,a[i].x)-d+1;
        a[i].y=lower_bound(d,d+dn,a[i].y)-d+1;
        ee[en++]=(EDGE){a[i].x,a[i].y+1,1,1,a[i].v};
        e[a[i].x].pb(&ee[en-1]);
        e[a[i].y+1].pb(&ee[en-1]);
    }
    for(i=0;i<=dn;i++){
        ee[en++]=(EDGE){i,i+1,k,k,0};
        e[i].pb(&ee[en-1]);
        e[i+1].pb(&ee[en-1]);
    }
    //for(i=0;i<en;i++)ee[i].print();
    while(flow());
    for(i=0;i<n;i++){
        if(i)printf(" ");
        if(!ee[i].f)printf("1");
        else printf("0");
    }
    puts("");
    return 0;
}