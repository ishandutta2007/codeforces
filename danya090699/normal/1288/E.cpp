#include <bits/stdc++.h>
using namespace std;
const int sz=3e5+10;
int n, m, last[sz], l[sz], r[sz];
int fen[2][sz];
void cha(int i, int p, int va)
{
    while(p<sz)
    {
        fen[i][p]+=va, p=p|(p+1);
    }
}
int que(int i, int p)
{
    int re=0;
    while(p>=0)
    {
        re+=fen[i][p], p=(p&(p+1))-1;
    }
    return re;
}
void add(int t, int x)
{
    if(last[x]==-1)
    {
        r[x]+=que(0, n-1)-que(0, x);
        if(t!=m)
        {
            l[x]=0, cha(0, x, 1);
        }
    }
    else
    {
        if(t!=m) cha(1, last[x], -1);
        r[x]=max(r[x], que(1, m-1)-que(1, last[x]));
    }

    if(t!=m)
    {
        last[x]=t;
        cha(1, t, 1);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m;
    for(int a=0; a<n; a++) l[a]=a, r[a]=a, last[a]=-1;
    for(int a=0; a<m; a++)
    {
        int x;
        scanf("%d", &x);
        x--, add(a, x);
    }
    for(int a=0; a<n; a++) add(m, a);
    for(int a=0; a<n; a++) printf("%d %d\n", l[a]+1, r[a]+1);
}