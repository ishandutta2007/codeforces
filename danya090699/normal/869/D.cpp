#include <bits/stdc++.h>
#define iter set <int>::iterator
using namespace std;
const int mod=1e9+7;
int n, m, re[4][2], an;
int sp[4][2];
set <int> us;
bool is_pr(int v, int u)
{
    while(1)
    {
        if(v==u) return true;
        if(v==0) break;
        v>>=1;
    }
    return false;
}
void path(int u, int v, vector <int> &ve)
{
    vector <int> ve2;
    while(!is_pr(v, u))
    {
        ve.push_back(u);
        u>>=1;
    }
    ve.push_back(u);
    while(v!=u)
    {
        ve2.push_back(v);
        v>>=1;
    }
    reverse(ve2.begin(), ve2.end());
    ve.insert(ve.end(), ve2.begin(), ve2.end());
}
int si(int v)
{
    int st=0, q=0;
    while((v<<st)<=n)
    {
        q+=min(1<<st, n-(v<<st)+1), st++;
    }
    return q;
}
int cou(int v)
{
    int q=si(v);
    vector <int> pre;
    for(iter it=us.begin(); it!=us.end(); it++)
    {
        if(is_pr(*it, v)) pre.push_back(*it);
    }
    for(int a=0; a<pre.size(); a++)
    {
        bool ok=1;
        for(int b=0; b<pre.size(); b++)
        {
            if(a!=b)
            {
                if(is_pr(pre[a], pre[b])) ok=0;
            }
        }
        if(ok) q-=si(pre[a]);
    }
    return q;
}
int up(int v)
{
    int q=0;
    while(v!=1)
    {
        if(us.find(v>>1)!=us.end()) break;
        q+=cou(v^1)+1, v>>=1;
    }
    return q;
}
void rec(int le)
{
    if(le<m)
    {
        for(int a=0; a<m; a++)
        {
            int fo=0;
            for(int b=0; b<le; b++) if(sp[b][0]==a) fo=1;
            if(fo==0)
            {
                sp[le][0]=a, sp[le][1]=0, rec(le+1);
                sp[le][0]=a, sp[le][1]=1, rec(le+1);
            }
        }
    }
    if(le>0)
    {
        bool ok=1;
        for(int a=0; a<le-1; a++)
        {
            int u=re[sp[a][0]][sp[a][1]^1], v=re[sp[a+1][0]][sp[a+1][1]];
            vector <int> way;
            path(u, v, way);
            for(int b=0; b<way.size(); b++)
            {
                if(us.find(way[b])!=us.end())
                {
                    ok=0;
                    break;
                }
                else us.insert(way[b]);
            }
        }
        if(ok)
        {
            int u=re[sp[0][0]][sp[0][1]], v=re[sp[le-1][0]][sp[le-1][1]^1];
            if(u!=v)
            {
                vector <int> way, ve;
                path(u, v, way);
                bool fo=0;
                for(int a=0; a<way.size(); a++)
                {
                    ve.push_back(0);
                    int v=way[a], v1=-1, v2=-1;
                    if(a!=0) v1=way[a-1];
                    if(a+1!=way.size()) v2=way[a+1];
                    if(us.find(v)==us.end())
                    {
                        ve[a]=1;
                        if(v*2!=v1 and v*2!=v2) ve[a]=(ve[a]+cou(v*2))%mod;
                        if(v*2+1!=v1 and v*2+1!=v2) ve[a]=(ve[a]+cou(v*2+1))%mod;
                        if(v/2!=v1 and v/2!=v2) ve[a]=(ve[a]+up(v))%mod;
                    }
                    else fo=1;
                }
                if(fo)
                {
                    int q1=0, q2=0;
                    for(int a=0; ; a++)
                    {
                        if(us.find(way[a])!=us.end()) break;
                        q1=(q1+ve[a])%mod;
                    }
                    for(int a=way.size()-1; ; a--)
                    {
                        if(us.find(way[a])!=us.end()) break;
                        q2=(q2+ve[a])%mod;
                    }
                    an=(an+1ll*q1*q2)%mod;
                }
                else
                {
                    for(int a=0; a<way.size()-1; a++)
                    {
                        int su=0;
                        for(int b=a+1; b<way.size(); b++) su=(su+ve[b])%mod;
                        an=(an+1ll*ve[a]*su)%mod;
                    }
                }
            }
        }
        us.clear();
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m;
    for(int a=0; a<m; a++)
    {
        cin>>re[a][0]>>re[a][1];
    }
    an=(1ll*n*n)%mod;
    rec(0);
    cout<<an;
}