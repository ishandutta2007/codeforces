#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
#define SIZE 100010
vector<int>e[SIZE],an[SIZE];
int No[SIZE],back[SIZE],M;
bool dfs(int x,int last){
    int i;
    back[x]=M;
    No[x]=M++;
    for(i=0;i<e[x].size();i++){
        if(e[x][i]==last)continue;
        if(No[e[x][i]]){
            if(No[e[x][i]]>No[x])continue;
            back[x]=min(back[x],No[e[x][i]]);
            an[x].push_back(e[x][i]);
        }
        else{
            if(!dfs(e[x][i],x))return 0;
            back[x]=min(back[x],back[e[x][i]]);
            if(back[e[x][i]]>No[x])return 0;
            an[x].push_back(e[x][i]);
        }
    }
    return 1;
}
main(){
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    M=1;
    while(m--){
        int x,y;
        scanf("%d%d",&x,&y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    if(!dfs(1,0))puts("0");
    else{
        for(i=1;i<=n;i++){
            for(j=0;j<an[i].size();j++)printf("%d %d\n",i,an[i][j]);
        }
    }
}