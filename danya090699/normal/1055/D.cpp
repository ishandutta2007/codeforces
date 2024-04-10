#include <bits/stdc++.h>
using namespace std;
const int sz=3e3+10, inf=1e9;
string s[sz], t[sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        char ss[sz];
        scanf("%s", ss);
        for(int b=0; ss[b]; b++) s[a].push_back(ss[b]);
    }
    for(int a=0; a<n; a++)
    {
        char ss[sz];
        scanf("%s", ss);
        for(int b=0; ss[b]; b++) t[a].push_back(ss[b]);
    }
    int l[n], r[n], ok=1;
    for(int a=0; a<n; a++)
    {
        l[a]=inf, r[a]=-inf;
        for(int b=0; b<s[a].size(); b++)
        {
            if(s[a][b]!=t[a][b]) l[a]=min(l[a], b), r[a]=max(r[a], b);
        }
        if(l[a]!=inf) swap(s[0], s[a]), swap(t[0], t[a]), swap(l[0], l[a]), swap(r[0], r[a]);
    }
    for(int a=1; a<n; a++)
    {
        if(l[a]!=inf)
        {
            if(r[0]-l[0]!=r[a]-l[a])
            {
                ok=0;
                break;
            }
            int d=l[0]-l[a];
            for(int b=l[a]; b<=r[a]; b++)
            {
                if(s[a][b]!=s[0][b+d] or t[a][b]!=t[0][b+d]) ok=0;
            }
        }
    }
    if(ok==0)
    {
        cout<<"NO";
        return 0;
    }
    while(l[0]>0)
    {
        char sy=s[0][l[0]-1];
        bool fo=0;
        for(int a=1; a<n; a++)
        {
            if(l[a]!=inf)
            {
                if(l[a]==0) fo=1;
                else if(s[a][l[a]-1]!=sy) fo=1;
            }
        }
        if(fo) break;
        for(int a=0; a<n; a++) if(l[a]!=inf) l[a]--;
    }
    while(r[0]+1<s[0].size())
    {
        char sy=s[0][r[0]+1];
        bool fo=0;
        for(int a=1; a<n; a++)
        {
            if(l[a]!=inf)
            {
                if(r[a]+1==s[a].size()) fo=1;
                else if(s[a][r[a]+1]!=sy) fo=1;
            }
        }
        if(fo) break;
        for(int a=0; a<n; a++) if(r[a]!=-inf) r[a]++;
    }
    string an, an2;
    for(int a=l[0]; a<=r[0]; a++) an.push_back(s[0][a]), an2.push_back(t[0][a]);

    for(int a=0; a<n; a++)
    {
        string cu=an+s[a];
        int m=cu.size(), fo=-1;
        int zf[m], lg=0, rg=-1;
        zf[0]=0;
        for(int a=1; a<m; a++)
        {
            zf[a]=0;
            if(rg>=a) zf[a]=min(zf[a-lg], rg-a+1);
            while(a+zf[a]<m)
            {
                if(cu[zf[a]]==cu[a+zf[a]]) zf[a]++;
                else break;
            }
            if(a>=an.size() and zf[a]>=an.size())
            {
                fo=a-an.size();
                break;
            }
            if(a+zf[a]-1>rg) lg=a, rg=a+zf[a]-1;
        }

        if(l[a]==inf)
        {
            if(fo!=-1) ok=0;
        }
        else if(fo!=l[a]) ok=0;
    }
    if(ok)
    {
        cout<<"YES\n"<<an<<"\n"<<an2;
    }
    else cout<<"NO";
}