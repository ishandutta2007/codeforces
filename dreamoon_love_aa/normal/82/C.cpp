#include<stdio.h>
#include<vector>
#include<queue>
#define SIZE 5001
using namespace std;
int cost[SIZE],foward[SIZE],a[SIZE],heavy[SIZE],day,get,an[SIZE];
struct data{
    int x;
    bool operator<(data b)const{
        return a[x]>a[b.x];
    }
};
priority_queue<data>Heap[SIZE];
struct EDGE{
    int y,c,No;
};
vector<EDGE>e[SIZE];
void dfs(int x,int last){
    int i;
    foward[x]=last;
    for(i=0;i<e[x].size();i++){
        if(e[x][i].y==last)continue;
        heavy[e[x][i].y]=cost[e[x][i].No];
        dfs(e[x][i].y,x);
    }
}
void dfs2(int x,int last){
    int i;
    if(x==1){
        while(!Heap[x].empty()){
            get++;
            an[Heap[x].top().x]=day;
            Heap[x].pop();
        }
    }
    else{
        for(i=0;i<heavy[x]&&!Heap[x].empty();i++){
            Heap[foward[x]].push(Heap[x].top());
            Heap[x].pop();
        }
    }
    for(i=0;i<e[x].size();i++){
        if(e[x][i].y==last)continue;
        dfs2(e[x][i].y,x);
    }
}
main(){
    int n,i,j,x,y,c;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<n;i++){
        scanf("%d%d%d",&x,&y,&c);
        cost[i]=c;
        e[x].push_back((EDGE){y,c,i});
        e[y].push_back((EDGE){x,c,i});
    }
    dfs(1,0);
    for(i=1;i<=n;i++)Heap[i].push((data){i});
    while(get<n){
        dfs2(1,0);
        day++;
    }
    for(i=1;i<=n;i++){
        if(i!=1)putchar(' ');
        printf("%d",an[i]);
    }
    puts("");
}