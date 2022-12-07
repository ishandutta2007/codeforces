#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e9, sz=1e6+10;
int fen[2][sz];
void cha(int i, int p, int va)
{
    while(p<sz)
    {
        fen[i][p]+=va, p=p|(p+1);
    }
}
int que(int i, int p)
{
    int re=0;
    while(p>=0)
    {
        re+=fen[i][p], p=(p&(p+1))-1;
    }
    return re;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin>>n>>q;
    int ar[n], l[n], r[n];
    vector <pair <int, int> > st;
    st.push_back({-1, inf});
    for(int a=0; a<n; a++)
    {
        scanf("%lld", &ar[a]);
        while(st.back().second<ar[a]) st.pop_back();
        l[a]=st.back().first+1;
        st.push_back({a, ar[a]});
    }
    st.clear();
    st.push_back({n, inf});
    for(int a=n-1; a>=0; a--)
    {
        while(st.back().second<ar[a]) st.pop_back();
        r[a]=st.back().first-1;
        st.push_back({a, ar[a]});
    }
    int pref[n+1];
    pref[0]=0;
    for(int a=1; a<=n; a++) pref[a]=pref[a-1]+(r[a-1]-l[a-1]+1);

    int zap[q][2], an[q];
    for(int i=0; i<2; i++)
    {
        for(int a=0; a<q; a++) scanf("%lld", &zap[a][i]);
    }
    for(int a=0; a<q; a++)
    {
        zap[a][0]--, zap[a][1]--;
        an[a]=pref[zap[a][1]+1]-pref[zap[a][0]];
    }

    vector <int> del[n], sp[n];
    for(int a=0; a<n; a++) del[l[a]].push_back(a);
    for(int a=0; a<q; a++) sp[zap[a][0]].push_back(a);

    for(int a=n-1; a>=0; a--)
    {
        cha(0, a, 1), cha(1, a, l[a]);
        while(del[a].size())
        {
            int p=del[a].back();
            cha(0, p, -1), cha(1, p, -l[p]);
            del[a].pop_back();
        }
        while(sp[a].size())
        {
            int nu=sp[a].back(), rg=zap[nu][1];
            an[nu]-=que(0, rg)*a-que(1, rg);
            sp[a].pop_back();
        }
    }

    for(int a=0; a<n; a++) del[r[a]].push_back(a);
    for(int a=0; a<q; a++) sp[zap[a][1]].push_back(a);
    for(int a=0; a<sz; a++) fen[0][a]=0, fen[1][a]=0;

    for(int a=0; a<n; a++)
    {
        cha(0, n-1-a, 1), cha(1, n-1-a, r[a]);
        while(del[a].size())
        {
            int p=del[a].back();
            cha(0, n-1-p, -1), cha(1, n-1-p, -r[p]);
            del[a].pop_back();
        }
        while(sp[a].size())
        {
            int nu=sp[a].back(), lg=zap[nu][0];
            an[nu]-=que(1, n-1-lg)-que(0, n-1-lg)*a;
            sp[a].pop_back();
        }
    }

    for(int a=0; a<q; a++) printf("%lld ", an[a]);
}