#include<stdio.h>
#include<vector>
using namespace std;
int n,r1,r2,an[50010];
vector<int>Map[50100];
void dfs(int x,int last){
    int i;
    for(i=0;i<Map[x].size();i++){
        if(Map[x][i]!=last){
            an[Map[x][i]]=x;
            dfs(Map[x][i],x);
        }
    }
}
main(){
    int i,x,first;
    scanf("%d%d%d",&n,&r1,&r2);
    for(i=1;i<=n;i++){
        if(i==r1)continue;
        scanf("%d",&x);
        Map[x].push_back(i);
        Map[i].push_back(x);
    }
    dfs(r2,0);
    first=1;
    for(i=1;i<=n;i++){
        if(i==r2)continue;
        if(!first)putchar(' ');
        printf("%d",an[i]);
        first=0;
    }
    puts("");
}