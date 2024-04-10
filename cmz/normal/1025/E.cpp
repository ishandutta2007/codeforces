#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>


using namespace std;
const int maxn=100+10;
struct Node{
    int x,y,id;
    bool operator<(const Node& rhs)const{
        return (x<rhs.x||(x==rhs.x&&y<rhs.y));
    }
}node[maxn],anss[10800],anst[10800];
int n,m;
int Move(int step,int x1,int y1,int x2,int y2){
    while(x1!=x2){
        if(x1<x2){
            anss[++step].x=x1,anss[step].y=y1;
            ++x1;
            anst[step].x=x1,anst[step].y=y1;
        }else{
            anss[++step].x=x1,anss[step].y=y1;
            --x1;
            anst[step].x=x1,anst[step].y=y1;
        }
    }
    while(y1!=y2){
        if(y1<y2){
            anss[++step].x=x1,anss[step].y=y1;
            ++y1;
            anst[step].x=x1,anst[step].y=y1;
        }else{
            anss[++step].x=x1,anss[step].y=y1;
            --y1;
            anst[step].x=x1,anst[step].y=y1;
        }
    }
    return step;
}
int solve(int step){
    sort(node+1,node+1+m);
    for(int i=1;i<=m;i++){
        if(node[i].x>i){
            step=Move(step,node[i].x,node[i].y,i,node[i].y);
            node[i].x=i;
        }
    }
    for(int i=m;i>=1;i--){
        step=Move(step,node[i].x,node[i].y,i,node[i].y);
        node[i].x=i;
    }
    for(int i=1;i<=m;i++){
        step=Move(step,node[i].x,node[i].y,node[i].x,node[i].id);
        node[i].y=node[i].id;
    }
    for(int i=1;i<=m;i++){
        step=Move(step,node[i].x,node[i].y,node[i].id,node[i].y);
        node[i].x=node[i].id;
    }
    return step;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&node[i].x,&node[i].y);
        node[i].id=i;
    }
    int step1=solve(0);

    for(int i=1;i<=m;i++){
        scanf("%d%d",&node[i].x,&node[i].y);
        node[i].id=i;
    }

    int step2=solve(step1);
    printf("%d\n",step2);
    for(int i=1;i<=step1;i++){
        printf("%d %d %d %d\n",anss[i].x,anss[i].y,anst[i].x,anst[i].y);
    }
    for(int i=step2;i>step1;i--){
        printf("%d %d %d %d\n",anst[i].x,anst[i].y,anss[i].x,anss[i].y);
    }

return 0;
}