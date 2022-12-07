#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10, inf=1e9;
bool us[sz];
vector <int> sv[sz];
int qu[sz], di[sz], c[sz];
main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=inf;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        vector <int> de;
        for(int b=2; b*b<=x; b++)
        {
            if(x%b==0)
            {
                int q=0;
                while(x%b==0) x/=b, q^=1;
                if(q) de.push_back(b);
            }
        }
        if(x>1) de.push_back(x);

        if(de.size()==0) an=1;
        if(de.size()==1)
        {
            if(us[de[0]]) an=min(an, 2);
            else us[de[0]]=1;
        }
        if(de.size()==2)
        {
            sv[de[0]].push_back(de[1]);
            sv[de[1]].push_back(de[0]);
        }
    }
    int l=0, r=0;
    for(int a=0; a<sz; a++)
    {
        if(us[a])
        {
            qu[r++]=a, di[a]=0, c[a]=a;
        }
        else di[a]=inf;
    }
    while(l<r)
    {
        int v=qu[l++];
        for(int a=0; a<sv[v].size(); a++)
        {
            int ne=sv[v][a];
            if(di[ne]==inf)
            {
                di[ne]=di[v]+1, c[ne]=c[v], qu[r++]=ne;
            }
            else if(c[ne]!=c[v]) an=min(an, di[v]+di[ne]+3);
        }
    }
    for(int a=0; a<1000; a++)
    {
        if(sv[a].size())
        {
            for(int b=0; b<sz; b++) di[b]=inf;
            l=0, r=0;
            for(int b=0; b<sv[a].size(); b++)
            {
                int to=sv[a][b];
                if(di[to]==inf)
                {
                    qu[r++]=to, di[to]=0, c[to]=to;
                }
                else an=min(an, 2);
            }
            while(l<r)
            {
                int v=qu[l++];
                for(int b=0; b<sv[v].size(); b++)
                {
                    int ne=sv[v][b];
                    if(ne!=a)
                    {
                        if(di[ne]==inf)
                        {
                            di[ne]=di[v]+1, c[ne]=c[v], qu[r++]=ne;
                        }
                        else if(c[ne]!=c[v]) an=min(an, di[v]+di[ne]+3);
                    }
                }
            }
        }
    }
    cout<<(an!=inf ? an : -1);
}