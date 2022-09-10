#include<stdio.h>
#include<string>
#include<math.h>
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
int mi;
#define SIZE 300000
struct EDGE{
    int y,flag;
    EDGE(int _y,int _flag){y=_y,flag=_flag;}
};
vector<EDGE>e[SIZE];
vector<int>an;
int dfs0(int x,int last){
    int res=0;
    for(int i=0;i<e[x].size();i++){
        if(e[x][i].y==last)continue;
        res+=dfs0(e[x][i].y,x);
        if(e[x][i].flag==-1)res++;
    }
    return res;
}
bool used[SIZE];
int dfs1(int x,int v){
    used[x]=1;
    if(v==mi){
        an.pb(x);
    }
    else if(v<mi){
        mi=v;
        an.clear();
        an.pb(x);
    }
    for(int i=0;i<e[x].size();i++){
        if(used[e[x][i].y])continue;
        if(e[x][i].flag==1)dfs1(e[x][i].y,v+1);
        else dfs1(e[x][i].y,v-1);
    }
}
int main(){
    int i,j,k,n;
    scanf("%d",&n);
    mi=n;
    for(i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        e[x].pb(EDGE(y,1));
        e[y].pb(EDGE(x,-1));
    }
    mi=dfs0(1,0);
    dfs1(1,mi);
    printf("%d\n",mi);
    sort(an.begin(),an.end());
    an.resize(unique(an.begin(),an.end())-an.begin());
    for(i=0;i<an.size();i++){
        if(i)printf(" ");
        printf("%d",an[i]);
    }
    return 0;
}