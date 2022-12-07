#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10, sz2=1e3, bl=300, mod=998244353, inf=1e9;
int n, k, dp[sz], va[sz], add[sz2], pt[sz2];
vector <int> st[sz], sq[sz2];
vector <pair <int, int> > pref[sz2];
int sum(int x, int y)
{
    int re=x+y;
    if(re>=mod) re-=mod;
    return re;
}
bool comp(int a, int b){return va[a]<va[b];}
void build(int i)
{
    pref[i].clear();
    pref[i].push_back({-inf, 0});
    int yk=0;
    pt[i]=0;
    while(yk<sq[i].size())
    {
        int su=0, cu=va[sq[i][yk]];
        if(cu<=k) pt[i]++;
        while(yk<sq[i].size())
        {
            if(va[sq[i][yk]]==cu) su=sum(su, dp[sq[i][yk]]), yk++;
            else break;
        }
        int pr=pref[i].back().second;
        pref[i].push_back({cu, sum(pr, su)});
    }
}
void cha(int l, int r, int d)
{
    for(int i=0; sq[i].size(); i++)
    {
        int lg=i*bl, rg=lg+sq[i].size()-1;
        if(!(l>rg or r<lg))
        {
            if(l<=lg and r>=rg)
            {
                add[i]+=d;
                if(d<0)
                {
                    if(pref[i].size()>pt[i]+1 and pref[i][pt[i]+1].first+add[i]<=k) pt[i]++;
                }
                else
                {
                    if(pref[i][pt[i]].first+add[i]>k) pt[i]--;
                }
            }
            else
            {
                vector <int> sp, sp2;
                for(int a=0; a<sq[i].size(); a++)
                {
                    int p=sq[i][a];
                    va[p]+=add[i];
                    if(p>=l and p<=r) va[p]+=d, sp.push_back(p);
                    else sp2.push_back(p);
                }
                add[i]=0;
                merge(sp.begin(), sp.end(), sp2.begin(), sp2.end(), sq[i].begin(), comp);
                build(i);
            }
        }
    }
}
void ins(int i, int p)
{
    va[p]-=add[i];
    sq[i].insert(sq[i].begin(), p);
    for(int a=0; a<sq[i].size(); a++)
    {
        int p=sq[i][a];
        va[p]+=add[i];
    }

    add[i]=0, build(i);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>k;
    for(int a=1; a<=n; a++) st[a].push_back(-1);
    dp[0]=1;
    ins(0, 0);
    for(int a=1; a<=n; a++)
    {
        int x;
        scanf("%d", &x);
        cha(st[x].back()+1, a-1, 1);
        if(st[x].size()>1)
        {
            cha(st[x][st[x].size()-2]+1, st[x].back(), -1);
        }
        st[x].push_back(a-1);

        for(int i=0; sq[i].size(); i++) dp[a]=sum(dp[a], pref[i][pt[i]].second);
        ins(a/bl, a);
    }
    cout<<dp[n];
}