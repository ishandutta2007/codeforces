#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10, inf=1e9;
int n, ve[sz][3], ans=0;
bool us[sz];
multiset <int> se;
void dfs(int v, int l, int r)
{
    if(l>r)
    {
        l=-1, r=-1;
    }
    int va=ve[v][0], ls=ve[v][1], rs=ve[v][2];
    if(l==-1)
    {
        if(ls!=-2) dfs(ls, -1, -1);
        if(rs!=-2) dfs(rs, -1, -1);
    }
    else
    {
        if(va>=l and va<=r)
        {
            se.erase(va);
            if(ls!=-2) dfs(ls, l, va-1);
            if(rs!=-2) dfs(rs, va+1, r);
        }
        else
        {
            if(va<l)
            {
                if(ls!=-2) dfs(ls, -1, -1);
                if(rs!=-2) dfs(rs, l, r);
            }
            else
            {
                if(ls!=-2) dfs(ls, l, r);
                if(rs!=-2) dfs(rs, -1, -1);
            }
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    for(int a=0; a<n; a++) us[a]=0;
    for(int a=0; a<n; a++)
    {
        cin>>ve[a][0]>>ve[a][1]>>ve[a][2];
        ve[a][1]--, ve[a][2]--;
        se.insert(ve[a][0]);
        if(ve[a][1]>=0) us[ve[a][1]]=1;
        if(ve[a][2]>=0) us[ve[a][2]]=1;
    }
    for(int a=0; a<n; a++) if(us[a]==0) dfs(a, 0, inf);
    cout<<se.size();
}