#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10, sz2=30;
int bor[sz*sz2], to[sz*sz2][2], q=1, be, cv, cle;
long long an=0;
int find(int x)
{
    int cu=cv, re=0;
    for(int a=cle; a>=0; a--)
    {
        int ne=((x>>a)&1);
        if(to[cu][ne]==0)
        {
            re+=(1<<a), ne^=1;
        }
        cu=to[cu][ne];
    }
    return re;
}
void dfs(int v, int va, int le)
{
    if(le==-1) be=min(be, find(va));
    else
    {
        if(to[v][0]!=0) dfs(to[v][0], va, le-1);
        if(to[v][1]!=0) dfs(to[v][1], va+(1<<le), le-1);
    }
}
void find_re(int u, int v, int le)
{
    cv=v, cle=le, be=2e9;
    dfs(u, 0, le);
    an+=be+(1<<(le+1));
}
void mst(int v, int le)
{
    int l=to[v][0], r=to[v][1];
    if(l!=0 and r!=0)
    {
        if(bor[l]<bor[r]) find_re(l, r, le-1);
        else find_re(r, l, le-1);
    }
    if(l!=0) mst(l, le-1);
    if(r!=0) mst(r, le-1);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    set <int> se;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        if(se.find(x)==se.end())
        {
            se.insert(x);
            int cu=0;
            for(int b=sz2-1; b>=0; b--)
            {
                int ne=((x>>b)&1);
                bor[cu]++;
                if(to[cu][ne]==0)
                {
                    to[cu][ne]=q, q++;
                }
                cu=to[cu][ne];
            }
            bor[cu]++;
        }
    }
    mst(0, sz2-1);
    cout<<an;
}