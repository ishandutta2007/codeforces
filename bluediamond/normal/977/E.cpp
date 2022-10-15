#include <cstdio>
#include <vector>

using namespace std;

const int N=200000;
int n,m;
vector<int>v[N+5];
bool viz[N+5];

bool ok=1;

void dfs(int nod)
{
    viz[nod]=1;
    int l=v[nod].size();
    if(l!=2)
        ok=0;
    for(int i=0;i<l;i++)
    {
        if(viz[v[nod][i]]==0)
            dfs(v[nod][i]);
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int nr=0;
    for(int i=1;i<=n;i++)
        if(viz[i]==0)
        {
            ok=1;
            dfs(i);
            nr+=ok;
        }
    printf("%d",nr);
    return 0;
}
/**
17 15
1 8
1 12
5 11
11 9
9 15
15 5
4 13
3 13
4 3
10 16
7 10
16 7
14 3
14 4
17 6

**/