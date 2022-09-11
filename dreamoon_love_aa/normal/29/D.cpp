#include<stdio.h>
#include<vector>
using namespace std;
vector<int>e[324],an;
int used[324][324];
bool dfs(int x,int y,int last){
    if(x==y)return 1;
    int i;
    for(i=0;i<e[x].size();i++){
        if(e[x][i]==last)continue;
        if(dfs(e[x][i],y,x)){
            an.push_back(x);
            return 1;
        }
    }
    return 0;
}
main(){
    int n,m,x,y,i;
    scanf("%d",&n);
    m=n-1;
    while(m--){
        scanf("%d%d",&x,&y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    y=1;
    an.push_back(1);
    while(scanf("%d",&x)!=EOF){
        dfs(x,y,0);
        y=x;
    }
    dfs(1,y,0);
    if(an.size()!=2*n-1)puts("-1");
    else{
        for(i=0;i<an.size();i++){
            if(i)putchar(' ');
            printf("%d",an[i]);
        }
        puts("");
    }
}