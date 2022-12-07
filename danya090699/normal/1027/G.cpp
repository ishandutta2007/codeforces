#include <bits/stdc++.h>
#define int long long
using namespace std;
void get_di(int x, vector <pair <int, int> > &sp)
{
    for(int a=2; a*a<=x; a++)
    {
        if(x%a==0)
        {
            sp.push_back(make_pair(a, 0));
            while(x%a==0)
            {
                x/=a, sp.back().second++;
            }
        }
    }
    if(x>1) sp.push_back(make_pair(x, 1));
}
vector <pair <int, int> > sp;
vector <vector <pair <int, int> > > sp2;
vector <int> st;
int x2, an=0;
int mul(int x, int y, int mod)
{
    int re=0;
    while(x)
    {
        re=(re+(x&((1<<15)-1))*y)%mod;
        x>>=15, y=(y<<15)%mod;
    }
    return re;
}
int po(int x, int y, int mod)
{
    int re=1%mod;
    while(y)
    {
        if(y&1) re=mul(re, x, mod);
        y>>=1;
        x=mul(x, x, mod);
    }
    return re;
}
int po2(int x, int y)
{
    int re=1;
    while(y)
    {
        if(y&1) re*=x;
        y>>=1;
        x*=x;
    }
    return re;
}
void dfs(int i, int mod)
{
    if(i==sp.size())
    {
        int x=x2%mod, ef=1;
        map <int, int> ma;
        for(int a=0; a<st.size(); a++)
        {
            int q=st[a], va=sp[a].first;
            if(q)
            {
                ef*=va-1;
                for(int b=0; b<sp2[a].size(); b++) ma[sp2[a][b].first]+=sp2[a][b].second;
            }
            if(q>1)
            {
                ma[va]+=q-1, ef*=po2(va, q-1);
            }
        }
        int cy=1;
        for(auto it=ma.begin(); it!=ma.end(); it++)
        {
            int q=(*it).second, va=(*it).first, add=1;
            ef/=po2(va, q);
            for(int a=0; a<=q; a++)
            {
                if(po(x, ef*add, mod)==1)
                {
                    cy*=add;
                    break;
                }
                add*=va;
            }
            ef*=po2(va, q);
        }
        an+=ef/cy;
    }
    else
    {
        int cu=1;
        for(int a=0; a<=sp[i].second; a++)
        {
            st.push_back(a);
            dfs(i+1, mod*cu), cu*=sp[i].first;
            st.pop_back();
        }
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int m, x;
    cin>>m>>x;
    x2=x;
    get_di(m, sp);
    for(int a=0; a<sp.size(); a++)
    {
        vector <pair <int, int> > ve;
        sp2.push_back(ve);
        get_di(sp[a].first-1, sp2.back());
    }
    dfs(0, 1);
    cout<<an;
}