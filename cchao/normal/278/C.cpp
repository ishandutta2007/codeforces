#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
vector<int> lan[100];
int v[30000], first[100], next[30000], sz=0;
int vis[100][100] = {{0}}, done[100]={0};

void add(int U, int V){
    v[sz] = V;
    next[sz] = first[U];
    first[U] = sz++;
}

void dfs(int x){
    done[x] = 1;
    for(int i = first[x]; i!=-1; i = next[i]){
        int y = v[i];
        if(done[y]==0){
            done[y] = 1;
            dfs(y);
        }
    }
}
int main(){
    memset(first, -1, sizeof(first));
    int n, m, f=0;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i){
        int x, y; scanf("%d", &x);
        if(x) f=1;
        for(int j = 0; j < x; ++j){
            scanf("%d", &y); --y;
            lan[y].push_back(i);
        }
    }
    if(f==0){
        printf("%d\n", n);
        return 0;
    }
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < lan[i].size(); ++j)
            for(int k = 0; k < lan[i].size(); ++k){
                int a, b;
                a= lan[i][j], b = lan[i][k];
                if(!vis[a][b]){
                    vis[a][b] = 1;
                    add(a,b);
                }
            }
    int cnt = 0;
    for(int i = 0; i < n; ++i)
        if(!done[i]) ++cnt,dfs(i);
    cout << cnt-1 << endl;
    return 0;
}