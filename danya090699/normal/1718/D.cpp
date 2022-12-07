#include <bits/stdc++.h>
using namespace std;
const int sz=3e5+10, inf=1e9;
int n, ar[sz], ar2[sz], p[sz], dot[sz*4], ok;
void build(int nu, int l, int r)
{
    if(l==r) dot[nu]=ar[l];
    else
    {
        int mid=(l+r)>>1;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        dot[nu]=max(dot[nu*2], dot[nu*2+1]);
    }
}
int que(int nu, int l, int r, int lg, int rg)
{
    if(l>=lg and r<=rg) return dot[nu];
    else if(l>rg or r<lg) return 0;
    else
    {
        int mid=(l+r)>>1;
        return max(que(nu*2, l, mid, lg, rg), que(nu*2+1, mid+1, r, lg, rg));
    }
}
vector <pair <int, int>> ot;
int dfs(int l, int r, int up)
{
    int ma=que(1, 0, n-1, l, r);
    int i=p[ma], dow=0;
    if(i>l) dow=max(dow, dfs(l, i-1, ar2[i] ? ar2[i] : up));
    if(i<r) dow=max(dow, dfs(i+1, r, ar2[i] ? ar2[i] : up));

    int lg=dow+1, rg=up-1;
    if(lg>rg) ok=0;
    if(ar2[i] and (ar2[i]<lg or ar2[i]>rg)) ok=0;

    if(ar2[i]==0) ot.push_back({lg, rg});

    return (ar2[i] ? ar2[i] : dow);
}
int us[sz];
vector <int> sv[sz];
void dfs2(int v)
{
    us[v]=1;
    for(int a=0; a<sv[v].size(); a++) dfs2(sv[v][a]);
}
int32_t main() {
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int q, k=0;
        cin>>n>>q;
        for(int a=0; a<n; a++)
        {
            scanf("%d", &ar[a]);
            ar[a]--;
            p[ar[a]]=a;
        }
        build(1, 0, n-1);
        for(int a=0; a<n; a++)
        {
            scanf("%d", &ar2[a]);
            if(ar2[a]==0) k++;
        }
        ok=1;
        dfs(0, n-1, inf);

        vector <pair <int, int>> pt;
        for(int a=0; a<k-1; a++)
        {
            int x;
            scanf("%d", &x);
            pt.push_back({x, -1});
        }
        for(int a=0; a<q; a++)
        {
            int x;
            scanf("%d", &x);
            pt.push_back({x, a});
        }
        pt.push_back({inf+1, -2});
        int ptr=0, rt, num[q];
        set <pair <int, int>> se;
        sort(pt.begin(), pt.end());
        sort(ot.begin(), ot.end());
        if(ok) {
            for (int a = 0; a < pt.size(); a++) {
                while (ptr < ot.size() and ot[ptr].first <= pt[a].first) {
                    se.insert({ot[ptr].second, ptr});
                    ptr++;
                }
                while (se.size() and (*se.begin()).first < pt[a].first) {
                    rt = (*se.begin()).second;
                    se.erase(se.begin());
                }
                if(pt[a].second>=0)
                {
                    if(se.size()) num[pt[a].second] = (*se.begin()).second;
                    else num[pt[a].second] = -1;
                }
                else if(pt[a].second == -1) {
                    if (se.size()) {
                        int to = (*se.begin()).second;
                        se.erase(se.begin());
                        if (se.size()) {
                            int v = (*se.begin()).second;
                            sv[v].push_back(to);
                        }
                    } else ok = 0;
                }
            }
            if (ok) {
                for (int a = 0; a < k; a++) us[a] = 0;
                dfs2(rt);
            }
        }
        for(int a=0; a<q; a++)
        {
            if(ok and num[a]!=-1 and us[num[a]]) printf("YES\n");
            else printf("NO\n");
        }

        for(int a=0; a<k; a++) sv[a].clear();
        ot.clear();
    }
}