#include <bits/stdc++.h>
using namespace std;
const int sz=5e3+10, sz2=1e5;
vector <pair <int, int> > sv[sz2];
int pref[sz][sz], q[sz], cnt[sz], n=2;
int previous[sz];
int build(int v, int l, int r, int x)
{
    if(x==1) q[v]=cnt[l];
    else
    {
        int prl=0;
        while(1)
        {
            int rg=min(r, l+(x-1-l%x));
            int pr=sv[v][0].first;
            sv[pr].back().second+=pref[x][l]-pref[x][prl];
            sv[v][0].second+=pref[x][l]-pref[x][prl];

            if(rg==r)
            {
                build(v, l, r, previous[x]);
                break;
            }
            else
            {
                sv[v].push_back({n, 0});
                sv[n].push_back({v, 0});
                build(n++, l, rg, previous[x]);

                sv[v].push_back({n, 0});
                sv[n].push_back({v, 0});
                v=n++;

                prl=l, l=rg+1;
            }
        }
    }
}
long long su=0;
void dfs(int v, int pr, int w)
{
    su+=1ll*q[v]*w;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first;
        if(ne!=pr)
        {
            dfs(ne, v, w+sv[v][a].second);
        }
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int k;
    cin>>k;
    for(int a=0; a<k; a++)
    {
        int x;
        scanf("%d", &x);
        cnt[max(1, x)]++;
    }
    int prime=1;
    for(int a=2; a<sz; a++)
    {
        bool ok=1;
        for(int b=2; b*b<=a; b++) if(a%b==0) ok=0;
        if(ok)
        {
            previous[a]=prime, prime=a;
            for(int b=a; b<sz; b*=a)
            {
                for(int c=b; c<sz; c+=b) pref[a][c]++;
            }
            for(int b=1; b<sz; b++) pref[a][b]+=pref[a][b-1];
        }
    }
    sv[0].push_back({1, 0});
    sv[1].push_back({0, 0});

    build(1, 1, sz-1, prime);
    long long an=1e18;

    for(int a=0; a<n; a++)
    {
        su=0, dfs(a, a, 0), an=min(an, su);
    }
    cout<<an;
}