#include<bits/stdc++.h>
using namespace std;
char s[102][102];
vector<int>e[102],F[102];
int deg[102];
set<int> S[102];
queue<int>Q;
void work(){
    int n,i,j;
    scanf("%d",&n);
    while(!Q.empty())Q.pop();
    for(i=1;i<=n;++i){
        e[i].clear();
        S[i].clear();
        deg[i] = 0;
        F[i].clear();
    }
    for(i=1;i<=n;++i)scanf("%s",s[i]+1);
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j){
            if(s[i][j]=='1'){
                e[i].push_back(j);
                F[j].push_back(i);
                ++deg[j];
            }
        }
    }
    int tot=0;
    for(i=1;i<=n;++i){
        if(deg[i]==0){
            Q.push(i);
        }
    }
    while(!Q.empty()){
        int h = Q.front();
        Q.pop();
        S[h].insert(++tot);
        for(auto y:e[h]){
            --deg[y];
            for(auto x:S[h])S[y].insert(x);
            if(deg[y] == 0)Q.push(y);
        }
    }
    for(i=1;i<=n;++i){
        printf("%d",S[i].size());
        for(auto x:S[i])printf(" %d",x);
        puts("");
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}