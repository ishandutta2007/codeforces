#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
#define SIZE 128
vector<int>e[SIZE];
int x[SIZE],y[SIZE],used[SIZE];
bool insect(int x1,int y1,int x2,int y2){
    if(x1>y1)swap(x1,y1);
    if(x2>y2)swap(x2,y2);
    if(y1<=x2)return 0;
    if(y2<=x1)return 0;
    if(x1<=x2&&y1>=y2)return 0;
    if(x1>=x2&&y1<=y2)return 0;
    return 1;
}
bool dfs(int v){
    int i;
    for(i=0;i<e[v].size();i++){
        if(used[e[v][i]]==0){
            used[e[v][i]]=-used[v];
            if(!dfs(e[v][i]))return 0;
        }
        else if(used[e[v][i]]==used[v])return 0;
    }
    return 1;
}
main(){
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d%d",&x[i],&y[i]);
        for(j=0;j<i;j++){
            if(insect(x[i],y[i],x[j],y[j])){
                e[i].push_back(j);
                e[j].push_back(i);
            }
        }
    }
    for(i=0;i<m;i++){
        if(!used[i]){
            used[i]=1;
            if(!dfs(i))break;
        }
    }
    if(i==m){
        for(i=0;i<m;i++){
            if(used[i]==1)putchar('o');
            else putchar('i');
        }
        puts("");
    }
    else puts("Impossible");
}