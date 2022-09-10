#include<stdio.h>
#include<vector>
#define SIZE 101
using namespace std;
vector<int>e[SIZE];
bool used[SIZE];
int cou,d[SIZE];
void dfs(int x,int y,int last){
    d[y]=x;
    cou++;
    used[x]=1;
    for(int i=0;i<e[x].size();i++){
        if(e[x][i]==last)continue;
        if(used[e[x][i]])continue;
        dfs(e[x][i],y+1,x);
    }
}
main(){
    int n,m,an=1,x,y;
    scanf("%d%d",&n,&m);
    if(m!=n)an=0;
    while(m--){
        scanf("%d%d",&x,&y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    if(an==0)puts("NO");
    else{
        dfs(1,0,0);
        if(cou==n)puts("FHTAGN!");
        else puts("NO");
    }
}