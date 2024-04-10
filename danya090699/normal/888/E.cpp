#include <bits/stdc++.h>
using namespace std;
int n, m, ar[50], an=0;
set <int, greater <int> > se;
void dfs(int le, int va)
{
    if(le==n) se.insert(va);
    else
    {
        dfs(le+1, va), dfs(le+1, (va+ar[le])%m);
    }
}
void dfs2(int le, int va)
{
    if(le==(n/2+n%2))
    {
        set <int>::iterator it=se.upper_bound(m-va);
        int x=va;
        if(it!=se.end()) x=max(x, (x+(*it))%m);
        an=max(an, x);
    }
    else
    {
        dfs2(le+1, va), dfs2(le+1, (va+ar[le])%m);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m;
    for(int a=0; a<n; a++) cin>>ar[a];
    dfs(n/2+n%2, 0);
    dfs2(0, 0);
    cout<<an;
}