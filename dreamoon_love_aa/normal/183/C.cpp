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
#define SIZE 100010
struct data{
    int y,v;
};
vector<data>e[SIZE];
int used[SIZE],de[SIZE],an=0;
void dfs(int x,int v){
    used[x]=1;
    de[x]=v;
    for(int i=0;i<e[x].size();i++){
        int y=e[x][i].y;
        if(used[y]==0){
            dfs(y,v+e[x][i].v);
        }
        else{
            int tmp=abs(v+e[x][i].v-de[y]);
            if(!an)an=tmp;
            else an=__gcd(an,tmp);
        }
    }
}
int main(){
    int i,j,k,n,m;
    cin>>n>>m;
    for(i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        e[x].pb((data){y,1});
        e[y].pb((data){x,-1});
    }
    for(i=1;i<=n;i++){
        if(!used[i])dfs(i,1);
    }
    if(!an)printf("%d\n",n);
    else printf("%d\n",an);
    return 0;
}