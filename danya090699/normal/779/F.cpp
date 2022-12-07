#include <bits/stdc++.h>
using namespace std;
const int sz=3e5, al=26;
int bor[sz][al], te[sz][al], n, *si, *si2, qq=0, su, sz2, le=1, best=1e9, ble;
void dfs(int v)
{
    si[v]=1;
    for(int a=0; a<al; a++)
    {
        int ne=bor[v][a];
        if(ne!=-1)
        {
            dfs(ne);
            si[v]+=si[ne];
        }
    }
}
void dfs2(int v)
{
    si2[v]=1;
    for(int a=0; a<al; a++)
    {
        int ne=te[v][a];
        if(ne!=-1)
        {
            dfs2(ne);
            si2[v]+=si2[ne];
        }
    }
}
void add(int u, int v)
{
    for(int a=0; a<al; a++)
    {
        int ne=bor[u][a], ne2=te[v][a];
        if(ne!=-1)
        {
            if(ne2==-1)
            {
                te[v][a]=sz2, sz2++;
                for(int b=0; b<al; b++) te[sz2-1][b]=-1;
            }
            ne2=te[v][a];
            add(ne, ne2);
        }
    }
}
void mer(int u, int v)
{
    for(int a=0; a<al; a++)
    {
        int ne=te[u][a], ne2=bor[v][a];
        if(ne!=-1)
        {
            if(ne2==-1) su+=si2[ne];
            else mer(ne, ne2);
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    si=new int[n], si2=new int[n];
    for(int a=0; a<n; a++) for(int b=0; b<26; b++) bor[a][b]=-1;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        char sy;
        scanf("%d%d", &u, &v);
        cin>>sy;
        u--, v--;
        bor[u][sy-'a']=v;
    }
    dfs(0);
    queue <int> qu;
    qu.push(0);
    while(qu.size()!=0)
    {
        int q=qu.size();
        su=qq;
        for(int a=0; a<q; a++)
        {
            int nu=qu.front(), ma=-1, bnu;
            for(int b=0; b<al; b++)
            {
                int ne=bor[nu][b];
                if(ne!=-1)
                {
                    if(si[ne]>ma)
                    {
                        ma=si[ne], bnu=ne;
                    }
                    qu.push(ne);
                }
            }
            if(ma!=-1)
            {
                sz2=1;
                for(int b=0; b<al; b++) te[0][b]=-1;
                for(int b=0; b<al; b++)
                {
                    int ne=bor[nu][b];
                    if(ne!=-1 and ne!=bnu) add(ne, 0);
                }
                dfs2(0);
                mer(0, bnu);
                su+=si[bnu];
            }
            else su++;
            qu.pop();
        }
        if(su<best)
        {
            best=su, ble=le;
        }
        qq+=q, le++;
    }
    cout<<best<<"\n"<<ble;
}