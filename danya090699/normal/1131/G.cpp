#include <bits/stdc++.h>
using namespace std;
const long long inf=1e18;
const int sz=1e7+10;
int h[sz], l[sz], r[sz];
long long pri[sz], dp[sz];
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    vector <pair <int, int> > bl[n];
    for(int a=0; a<n; a++)
    {
        int q;
        scanf("%d", &q);
        bl[a].resize(q);
        for(int b=0; b<q; b++) scanf("%d", &bl[a][b].first);
        for(int b=0; b<q; b++) scanf("%d", &bl[a][b].second);
    }
    int q, yk=0;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int i, mul;
        scanf("%d%d", &i, &mul);
        i--;
        for(int b=0; b<bl[i].size(); b++)
        {
            h[yk]=bl[i][b].first, pri[yk]=1ll*bl[i][b].second*mul, yk++;
        }
    }
    vector <int> st;
    st.push_back(-1);
    for(int a=0; a<m; a++)
    {
        int p=upper_bound(st.begin(), st.end(), a-h[a])-st.begin();
        if(p==st.size()) l[a]=a;
        else if(st[p]==-1) l[a]=0;
        else l[a]=l[st[p]];
        while(st.back()!=-1 and l[st.back()]>l[a]) st.pop_back();
        st.push_back(a);
    }
    st.clear();
    st.push_back(m);
    for(int a=m-1; a>=0; a--)
    {
        int p=upper_bound(st.begin(), st.end(), a+h[a], greater <int>())-st.begin();
        if(p==st.size()) r[a]=a;
        else if(st[p]==m) r[a]=m-1;
        else r[a]=r[st[p]];
        while(st.back()!=m and r[st.back()]<r[a]) st.pop_back();
        st.push_back(a);
    }
    for(int a=1; a<=m; a++) dp[a]=inf;
    dp[0]=0;
    st.clear();
    st.push_back(0);
    for(int a=1; a<=m; a++)
    {
        dp[r[a-1]+1]=min(dp[r[a-1]+1], dp[a-1]+pri[a-1]);

        int p=lower_bound(st.begin(), st.end(), l[a-1])-st.begin();
        dp[a]=min(dp[a], dp[st[p]]+pri[a-1]);

        while(dp[st.back()]>dp[a]) st.pop_back();
        st.push_back(a);
    }
    cout<<dp[m];
}