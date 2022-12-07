#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    int ar[n], h[n], dp[n];
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        h[a]=0, dp[a]=1;
    }
    vector <int> st, sv[n];
    for(int a=0; a<n; a++)
    {
        while(st.size() and ar[st.back()]<ar[a])
        {
            int ne=st.back();
            dp[a]=max(dp[a], dp[ne]+1);
            sv[a].push_back(ne);
            st.pop_back();
        }
        st.push_back(a);
    }
    for(int a=n-1; a>=0; a--)
    {
        for(int b=0; b<sv[a].size(); b++) h[sv[a][b]]=h[a]+1;
    }
    deque <int> ma, ql, qr;
    int rg=0, p=-1;
    for(int a=0; a+k<=n; a++)
    {
        while(rg<a+k)
        {
            while(ma.size() and ar[ma.back()]<ar[rg]) ma.pop_back();
            ma.push_back(rg);

            while(qr.size() and dp[qr.back()]<dp[rg]) qr.pop_back();
            qr.push_back(rg);

            rg++;
        }
        if(ma.front()<a) ma.pop_front();

        while(p<ma.front())
        {
            p++;
            while(ql.size() and h[ql.back()]<h[p]) ql.pop_back();
            ql.push_back(p);

            if(qr.size() and qr.front()==p) qr.pop_front();
        }
        if(ql.front()<a) ql.pop_front();

        int an=h[ql.front()]-h[ma.front()]+1;
        if(qr.size()) an=max(an, dp[qr.front()]);
        printf("%d ", an);
    }
}