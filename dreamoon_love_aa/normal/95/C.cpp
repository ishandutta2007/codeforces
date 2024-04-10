#include<stdio.h>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;
struct EDGE{
    int y;
    long long v;
    bool operator<(EDGE b)const{return v>b.v||(v==b.v&&y<b.y);}
};
vector<EDGE>e1[1024],e2[1024];
int used[1024],cnt;
void f1(int x,int t,int c){
    int i;
    cnt++;
    priority_queue<EDGE>heap;
    heap.push((EDGE){x,0});
    while(!heap.empty()){
        EDGE tmp=heap.top();
        heap.pop();
        if(used[tmp.y]==cnt)continue;
        used[tmp.y]=cnt;
        if(tmp.v>t)return;
        e2[x].push_back((EDGE){tmp.y,c});
        for(i=0;i<e1[tmp.y].size();i++){
            heap.push((EDGE){e1[tmp.y][i].y,tmp.v+e1[tmp.y][i].v});
        }
    }
}
main(){
    int n,m,S,E,x,y,v,i,j,t,c;
    long long an=-1;
    scanf("%d%d",&n,&m);
    scanf("%d%d",&S,&E);
    for(i=0;i<m;i++){
        scanf("%d%d%d",&x,&y,&v);
        e1[x].push_back((EDGE){y,v});
        e1[y].push_back((EDGE){x,v});
    }
    for(i=1;i<=n;i++){
        scanf("%d%d",&t,&c);
        f1(i,t,c);
    }
    priority_queue<EDGE>heap;
    cnt++;
    heap.push((EDGE){S,0});
    while(!heap.empty()){
        EDGE tmp=heap.top();
        heap.pop();
        if(used[tmp.y]==cnt)continue;
        used[tmp.y]=cnt;
        if(tmp.y==E){
            an=tmp.v;
            break;
        }
        for(i=0;i<e2[tmp.y].size();i++){
            heap.push((EDGE){e2[tmp.y][i].y,e2[tmp.y][i].v+tmp.v});
        }
    }
    printf("%I64d\n",an);
}