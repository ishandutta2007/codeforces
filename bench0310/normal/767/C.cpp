#include <bits/stdc++.h>

using namespace std;

const int N=1000005;
vector<int> v[N];
vector<int> tin(N,0);
vector<int> tout(N,0);
vector<int> val(N,0);
vector<int> x(N,0);
vector<int> h(N,0);
int tcnt=1;
int root=1;
int t=0;
set<int> s;
array<int,2> res={0,0};

void dfs(int a)
{
    h[tcnt]=a;
    tin[a]=tcnt++;
    x[a]=val[a];
    for(int to:v[a])
    {
        dfs(to);
        x[a]+=x[to];
    }
    tout[a]=tcnt-1;
}

void solve(int a,int id)
{
    if(x[a]==t&&a!=root)
    {
        if(id!=0) res={id,a};
        s.erase(tin[a]);
        auto it=s.lower_bound(tin[a]);
        if(it!=s.begin())
        {
            it--;
            res={h[*it],a};
        }
        it=s.upper_bound(tout[a]);
        if(it!=s.end()) res={h[*it],a};
    }
    if(x[a]==2*t&&a!=root) id=a;
    for(int to:v[a]) solve(to,id);
    if(x[a]==t&&a!=root) s.insert(tin[a]);
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int p;
        scanf("%d%d",&p,&val[i]);
        if(p==0) root=i;
        else v[p].push_back(i);
    }
    dfs(root);
    bool ok=1;
    if((x[root]%3)!=0) ok=0;
    t=x[root]/3;
    for(int i=1;i<=n;i++) if(x[i]==t&&i!=root) s.insert(tin[i]);
    solve(root,0);
    if(res[0]==0) ok=0;
    if(ok) printf("%d %d\n",res[0],res[1]);
    else printf("-1\n");
    return 0;
}