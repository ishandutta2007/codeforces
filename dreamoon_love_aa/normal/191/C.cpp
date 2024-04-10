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
int an[100010],used[100010],oo;
set<int>H[100010];
struct EE{
    int y,No;
};
vector<EE>e[100010];
vector<int>node[100010];
int dfs(int x){
    oo++;
    int i,now=oo;
    for(int i=0;i<node[x].size();i++){
        if(!H[now].count(node[x][i]))
            H[now].insert(node[x][i]);
        else
            H[now].erase(node[x][i]);
    }
    used[x]=1;
    for(i=0;i<e[x].size();i++){
        if(used[e[x][i].y]==0){
            int tmp=dfs(e[x][i].y);
            an[e[x][i].No]=H[tmp].size();
            if(H[now].size()<H[tmp].size()){
                set<int>::iterator it;
                for(it=H[now].begin();it!=H[now].end();it++){
                    if(!H[tmp].count(*it))
                        H[tmp].insert(*it);
                    else 
                        H[tmp].erase(*it);
                }
                now=tmp;
            }
            else{
                set<int>::iterator it;
                for(it=H[tmp].begin();it!=H[tmp].end();it++){
                    if(!H[now].count(*it))
                        H[now].insert(*it);
                    else
                        H[now].erase(*it);
                }
            }
        }
    }
    return now;
}
int main(){
    int i,j,k,n;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        e[x].pb((EE){y,i});
        e[y].pb((EE){x,i});
    }
    scanf("%d",&k);
    for(i=0;i<k;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        node[x].pb(i);
        node[y].pb(i);
    }
    dfs(1);
    printf("%d",an[1]);
    for(i=2;i<n;i++)printf(" %d",an[i]);
    puts("");
    return 0;
}