#include <stdio.h>
#include <vector>

using namespace std;

int color[100005];
int edge[100005][2];

vector<int> adj[100005];
bool visited[100005];

bool dfs(int c, int now)
{
    if(color[now] != c) return false;
    for(int i = 0; i < adj[now].size(); i++)
    {
        if(visited[adj[now][i]])    continue;
        visited[adj[now][i]] = true;
        if(!dfs(c, adj[now][i])) return false;
        visited[adj[now][i]] = false;
    }
    return true;
}

int main()
{
    int n, i;
    bool isPossible;
    
    scanf("%d", &n);
    
    for(i = 1; i <= n - 1; i++)
    {
        scanf("%d %d", &edge[i][0], &edge[i][1]);
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }
    
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &color[i]);
    }
    
    for(i = 1; i <= n - 1; i++)
    {
        if(color[edge[i][0]] != color[edge[i][1]])    break;
    }
    
    if(i > n - 1)
    {
        printf("YES\n1");
        return 0;
    }
    
    int root1 = edge[i][0], root2 = edge[i][1];

    visited[root1] = true;
    isPossible = true;
    for(i = 0; i < adj[root1].size(); i++)
    {
        visited[adj[root1][i]] = true;
        if(!dfs(color[adj[root1][i]], adj[root1][i]))   isPossible = false;
        visited[adj[root1][i]] = false;
    }
    
    if(isPossible)
    {
        printf("YES\n%d", root1);
        return 0;
    }
    
    for(int i = 0; i <= n; i++) visited[i] = false;
    
    visited[root2] = true;
    isPossible = true;
    for(i = 0; i < adj[root2].size(); i++)
    {
        visited[adj[root2][i]] = true;
        if(!dfs(color[adj[root2][i]], adj[root2][i]))   isPossible = false;
        visited[adj[root2][i]] = false;
    }
    
    if(isPossible)
    {
        printf("YES\n%d", root2);
        return 0;
    }
    
    printf("NO");
    
    return 0;
}