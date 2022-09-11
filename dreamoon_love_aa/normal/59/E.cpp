#include<stdio.h>
#include<set>
#include<vector>
using namespace std;
vector<int>e[3001],last;
struct data{
    int x,y,v;
    bool operator<(data b)const{
        return x<b.x||(x==b.x&&y<b.y)||(x==b.x&&y==b.y&&v<b.v);
    }
};
bool used[3001][3001];
vector<data>bfs;
set<data>H;
void print(int x){
    if(bfs[x].x==0){
        printf("1 ");
        return;
    }
    print(last[x]);
    printf("%d ",bfs[x].x+1);
}
main(){
    int n,m,k,x,y,z,i,j;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        x--,y--;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    while(k--){
        scanf("%d%d%d",&x,&y,&z);
        x--,y--,z--;
        H.insert((data){x,y,z});
    }
    for(i=0;i<e[0].size();i++){
        bfs.push_back((data){0,e[0][i],1});
        last.push_back(0);
        used[0][e[0][i]]=1;
    }
    for(i=0;i<bfs.size();i++){
        if(bfs[i].y==n-1)break;
        for(j=0;j<e[bfs[i].y].size();j++){
            if(!H.count((data){bfs[i].x,bfs[i].y,e[bfs[i].y][j]})&&!used[bfs[i].y][e[bfs[i].y][j]]){
                used[bfs[i].y][e[bfs[i].y][j]]=1;
                bfs.push_back((data){bfs[i].y,e[bfs[i].y][j],bfs[i].v+1});
                last.push_back(i);
            }
        }
        if(j<e[bfs[i].y].size())break;
    }
    if(i==bfs.size())puts("-1");
    else{
        printf("%d\n",bfs[i].v);
        print(i);
        printf("%d\n",n);
    }
}