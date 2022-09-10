#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
#define SIZE 3024
int an[SIZE],used[SIZE],haha[SIZE],bfs[SIZE],end,j,over;
vector<int>e[SIZE];
bool dfs(int x,int last){
    used[x]=1;
    for(int i=0;i<e[x].size();i++){
        if(e[x][i]==last)continue;
        if(used[e[x][i]]==0){
            if(dfs(e[x][i],x)){
                if(over)return 1;
                bfs[j++]=x;
                haha[x]=1;
                if(x==end){
                    over=1;
                }
                return 1;
            }
        }
        else{
            haha[x]=1;
            bfs[j++]=x;
            end=e[x][i];
            return 1;
        }
    }
    return 0;
}
int main(){
    int i,k,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
    }
    dfs(1,0);
    for(i=0;i<j;i++){
        int x=bfs[i];
        for(k=0;k<e[x].size();k++){
            int y=e[x][k];
            if(haha[y]==0){
                haha[y]=1;
                an[y]=an[x]+1;
                bfs[j++]=y;
            }
        }
    }
    for(i=1;i<=n;i++){
        if(i!=1)putchar(' ');
        printf("%d",an[i]);
    }
    puts("");
}