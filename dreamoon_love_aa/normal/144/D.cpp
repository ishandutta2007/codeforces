#include<stdio.h>
#include<string>
#include<math.h>
#include<queue>
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
#define SIZE 100001
struct data{
    int y,v;
    bool operator<(const data& b)const{return v>b.v;}
};
vector<data>e[SIZE];
int used[SIZE];
int mi[SIZE],bfs[SIZE];
priority_queue<data>H;
int main(){
    int i,j,k,n,m,s,d;
    double an=0;
    cin>>n>>m>>s;
    for(i=0;i<m;i++){
        int x,y,v;
        scanf("%d%d%d",&x,&y,&v);
        e[x].pb((data){y,v});
        e[y].pb((data){x,v});
    }
    cin>>d;
    if(d==0){
        puts("1");
        return 0;
    }
    H.push((data){s,0});
    while(!H.empty()){
        data now=H.top();H.pop();
        if(used[now.y])continue;
        used[now.y]=1;
        mi[now.y]=now.v;
        for(i=0;i<e[now.y].size();i++){
            int v=e[now.y][i].v+now.v;
            H.push((data){e[now.y][i].y,v});
        }
    }
    bfs[0]=s;
    used[0]=2;
    for(i=0,j=1;i<j;i++){
        if(mi[bfs[i]]==d)an++;
        for(k=0;k<e[bfs[i]].size();k++){
            if(mi[bfs[i]]<d&&mi[bfs[i]]+e[bfs[i]][k].v>d){
                if(mi[bfs[i]]+e[bfs[i]][k].v==mi[e[bfs[i]][k].y])an++;
                else{
                    if((d-mi[bfs[i]])+(d-mi[e[bfs[i]][k].y])<e[bfs[i]][k].v)an++;
                    else if((d-mi[bfs[i]])+(d-mi[e[bfs[i]][k].y])==e[bfs[i]][k].v)an+=0.5;
                }
            }
            if(mi[bfs[i]]+e[bfs[i]][k].v==mi[e[bfs[i]][k].y]){
                if(used[e[bfs[i]][k].y]!=2){
                    used[e[bfs[i]][k].y]=2;
                    bfs[j++]=e[bfs[i]][k].y;
                }
            }
        }
    }
    printf("%.0lf\n",an);
    return 0;
}