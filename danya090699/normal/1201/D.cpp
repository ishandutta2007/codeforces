#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=2e5+10, inf=1e9;
set <int> st;
pair <int, int> f(int i)
{
    auto it=st.upper_bound(i);
    if(it==st.end())
    {
        it--;
        return make_pair(*it, *it);
    }
    else
    {
        if(it==st.begin()) return make_pair(*it, *it);
        else
        {
            int l, r=(*it);
            it--, l=(*it);
            return make_pair(l, r);
        }
    }
}
map <int, int> dp[sz];
void go(int r, int c, int va)
{
    if(dp[r].find(c)==dp[r].end()) dp[r][c]=va;
    else dp[r][c]=min(dp[r][c], va);
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, k, q, n2=0;
    cin>>n>>m>>k>>q;
    int l[n], r[n];
    for(int a=0; a<n; a++) l[a]=inf, r[a]=-inf;
    for(int a=0; a<k; a++)
    {
        int rr, c;
        scanf("%lld%lld", &rr, &c);
        rr--, c--;
        l[rr]=min(l[rr], c), r[rr]=max(r[rr], c);
        n2=max(n2, rr);
    }

    for(int a=0; a<q; a++)
    {
        int p;
        scanf("%lld", &p);
        p--, st.insert(p);
    }

    dp[0][0]=0;
    for(int a=0; a+1<=n2; a++)
    {
        for(auto it=dp[a].begin(); it!=dp[a].end(); it++)
        {
            int p=(*it).first, va=(*it).second;
            if(l[a]==inf)
            {
                if(st.find(p)==st.end())
                {
                    pair <int, int> x=f(p);
                    int p1=x.first, add1=abs(p-p1);
                    go(a+1, p1, va+1+add1);
                    int p2=x.second, add2=abs(p-p2);
                    go(a+1, p2, va+1+add2);
                }
                else dp[a+1][p]=va+1;
            }
            else
            {
                int nva=va+abs(p-l[a])+(r[a]-l[a])+1;
                pair <int, int> x=f(r[a]);
                int p1=x.first, add1=abs(r[a]-p1);
                go(a+1, p1, nva+add1);
                int p2=x.second, add2=abs(r[a]-p2);
                go(a+1, p2, nva+add2);

                nva=va+abs(p-r[a])+(r[a]-l[a])+1;
                x=f(l[a]);
                p1=x.first, add1=abs(l[a]-p1);
                go(a+1, p1, nva+add1);
                p2=x.second, add2=abs(l[a]-p2);
                go(a+1, p2, nva+add2);
            }
        }
    }
    int an=1e18;
    for(auto it=dp[n2].begin(); it!=dp[n2].end(); it++)
    {
        int p=(*it).first, va=(*it).second;
        an=min(an, va+min(abs(l[n2]-p), abs(r[n2]-p))+(r[n2]-l[n2]));
    }
    cout<<an;
}