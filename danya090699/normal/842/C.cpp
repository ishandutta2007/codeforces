//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
int n, va[sz], q[sz], an[sz];
vector <int> sv[sz];

void dfs(int v, int pr, int h)
{
    int x=va[v];
    an[v]=0;
        for(int a=1; a*a<=x; a++)
        {
            if(x%a==0)
            {
                q[a]++;
                if(q[a]>=h-1) an[v]=max(an[v], a);
                if(a!=x/a)
                {
                    q[x/a]++;
                    if(q[x/a]>=h-1) an[v]=max(an[v], x/a);
                }
            }
        }
    if(pr!=-1)
    {
        int x2=va[pr];
        //cout<<q[6]<<" ";
        for(int a=1; a*a<=x2; a++)
        {
            if(x2%a==0)
            {
                if(q[a]>=h-1) an[v]=max(an[v], a);
                if(a!=x2/a)
                {
                    if(q[x2/a]>=h-1) an[v]=max(an[v], x2/a);
                }
            }
        }
    }
    else an[v]=x;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr) dfs(ne, v, h+1);
    }
    for(int a=1; a*a<=x; a++)
    {
        if(x%a==0)
        {
            q[a]--;
            if(a!=x/a) q[x/a]--;
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    for(int a=0; a<n; a++) scanf("%d", &va[a]);
    for(int a=0; a<sz; a++) q[a]=0;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    dfs(0, -1, 1);
    for(int a=0; a<n; a++) printf("%d ", an[a]);
}