#include <bits/stdc++.h>
using namespace std;
const int sz=3e5+10;
int pr[sz], q[sz][2], ty[sz], fix[sz];
vector <int> sp[sz];
int f(int v)
{
    if(!fix[v]) return min(q[v][0], q[v][1]);
    else return q[v][1];
}
void cha(int v)
{
    swap(q[v][0], q[v][1]);
    for(int a=0; a<sp[v].size(); a++) ty[sp[v][a]]^=1;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector <int> ve[n];
    for(int a=0; a<k; a++)
    {
        int m;
        scanf("%d", &m);
        for(int b=0; b<m; b++)
        {
            int p;
            scanf("%d", &p);
            p--, ve[p].push_back(a);
        }
    }
    int an=0;
    for(int a=0; a<k; a++)
    {
        pr[a]=a, ty[a]=0, q[a][0]=1, fix[a]=0;
        sp[a].push_back(a);
    }
    for(int a=0; a<n; a++)
    {
        if(ve[a].size()==1)
        {
            //cout<<a;
            int v=ve[a][0];
            an-=f(pr[v]);
            if(ty[v]!=((s[a]-'0')^1)) cha(pr[v]);
            fix[pr[v]]=1;
            an+=f(pr[v]);
        }
        if(ve[a].size()==2)
        {
            int u=ve[a][0], v=ve[a][1];
            if(pr[u]!=pr[v])
            {
                if(sp[pr[u]].size()<sp[pr[v]].size()) swap(u, v);

                int d=ty[u]^ty[v]^(s[a]-'0')^1;

                u=pr[u], v=pr[v];

                an-=f(u)+f(v);

                if(d)
                {
                    if(fix[v]) cha(u);
                    else cha(v);
                }
                fix[u]|=fix[v];

                while(sp[v].size())
                {
                    int i=sp[v].back();
                    pr[i]=u, q[u][ty[i]]++;
                    sp[v].pop_back();
                    sp[u].push_back(i);
                }

                an+=f(u);
            }
        }
        printf("%d\n", an);
    }
}