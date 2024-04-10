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
#include<queue>
#define pb push_back
using namespace std;
#define SIZE 900
struct EDGE{
    int x,y,v,c;
    double r;
    EDGE(int _x=0,int _y=0,int _v=0,int _c=0,double _r=0){x=_x;y=_y;v=_v;c=_c;r=_r;}
}ee[100000];
int en,used[2000],tt;
double an;
vector<EDGE*>e[2000];
void add(int x,int y,int v,double r){
    ee[en]=EDGE(x,y,0,v,r);
    e[x].pb(&ee[en]);
    e[y].pb(&ee[en]);
    en++;
}
bool fresh(double &x,double v){
    if(x>v+1e-9){
        x=v;
        return 1;
    }
    return 0;
}
int lastNo[SIZE],lastV[SIZE];
EDGE* lastE[SIZE];
double mi[20000];
int bfs[1000000];
bool flow(int n){
    int i,ll=0,rr=0;
    for(i=0;i<=n;i++)mi[i]=1e18;
    mi[0]=0;
    queue<int>qq;
    bfs[rr++]=0;
    while(ll<rr){
        int x=bfs[ll];
        ll++;
        used[x]=0;
        for(i=0;i<e[x].size();i++){
            int y;
            if(x==e[x][i]->x){
                y=e[x][i]->y;
                if(e[x][i]->v<e[x][i]->c){
                    if(fresh(mi[y],mi[x]+e[x][i]->r)){
                        lastNo[y]=x;
                        lastE[y]=e[x][i];
                        lastV[y]=1;
                        if(!used[y]){
                            bfs[rr++]=y;
                            used[y]=1;
                        }
                    }
                }
            }
            else{
                y=e[x][i]->x;
                if(e[x][i]->v>0){
                    if(fresh(mi[y],mi[x]-e[x][i]->r)){
                        lastNo[y]=x;
                        lastE[y]=e[x][i];
                        lastV[y]=-1;
                        if(!used[y]){
                            bfs[rr++]=y;
                            used[y]=1;
                        }
                    }
                }
            }
        }
    }
    if(mi[n]>1e17)return 0;
    an+=mi[n];
    int now=n;
    while(now){
        lastE[now]->v+=lastV[now];
        now=lastNo[now];
    }
    return 1;
}
int xx[SIZE],yy[SIZE];
int main(){
    int i,j,k,n,top=-1000000;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d%d",&xx[i],&yy[i]);
        top=max(top,yy[i]);
    }
    k=0;
    for(i=1;i<=n;i++){
        add(n+i,n+n+1,2,0);
        if(yy[i]==top){
            k++;
        }
        else{
            add(0,i,1,0);
        }
    }
    if(k>1){
        puts("-1");
        return 0;
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
            if(yy[i]<yy[j])add(i,j+n,1,sqrt((xx[i]-xx[j])*(xx[i]-xx[j])+(yy[i]-yy[j])*(yy[i]-yy[j])));
        }
    for(i=1;i<n;i++){
        if(!flow(n+n+1)){
            puts("-1");
            return 0;
        }
    }
    printf("%.12lf\n",an);
    return 0;
}