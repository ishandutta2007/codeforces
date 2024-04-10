#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<queue>
using namespace std;
#define SIZE 100001
#define MOD 10000000
struct EDGE{
    int y,v;
};
struct data{
    long long v;
    int No;
    bool operator<(data b)const{return v>b.v||(v==b.v&&No>b.No);}
};
priority_queue<data>Heap;
vector<EDGE>e[SIZE];
int last[SIZE],bfs[SIZE];
long long mi[SIZE];
bool used[SIZE];
main(){
    int n,m,x,y,v,i;
    memset(mi,-1,sizeof(mi));
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d%d%d",&x,&y,&v);
        e[x].push_back((EDGE){y,v});
        e[y].push_back((EDGE){x,v});
    }
    Heap.push((data){0,1});
    while(!Heap.empty()){
        data tmp=Heap.top();
        Heap.pop();
        if(!used[tmp.No]){
            used[tmp.No]=1;
            mi[tmp.No]=tmp.v;
            for(i=0;i<e[tmp.No].size();i++)
                if(mi[e[tmp.No][i].y]<0||mi[e[tmp.No][i].y]>e[tmp.No][i].v+mi[tmp.No]){
                    last[e[tmp.No][i].y]=tmp.No;
                    mi[e[tmp.No][i].y]=e[tmp.No][i].v+mi[tmp.No];
                    Heap.push((data){mi[e[tmp.No][i].y],e[tmp.No][i].y});
                }
        }
    }
    if(mi[n]==-1)puts("-1");
    else{
        bfs[0]=n;
        for(i=0;bfs[i]!=1;i++){
            bfs[i+1]=last[bfs[i]];
        }
        printf("1");
        for(i--;i>=0;i--)printf(" %d",bfs[i]);

        puts("");
    }
}