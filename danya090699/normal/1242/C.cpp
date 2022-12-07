#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int k;
    cin>>k;
    map <int, pair <int, int> > ma;
    pair <int, int> be[1<<k];
    for(int a=0; a<(1<<k); a++) be[a]={-1, -1};
    vector <pair <int, int> > pre[k];
    vector <int> ch[k];
    int tot=0, su[k];
    for(int a=0; a<k; a++)
    {
        int q;
        cin>>q;
        su[a]=0;
        for(int b=0; b<q; b++)
        {
            int x;
            scanf("%lld", &x);
            ch[a].push_back(x);
            ma[x]={a, b};
            su[a]+=x;
        }
        tot+=su[a];
    }
    if(tot%k==0)
    {
        int va=tot/k;
        for(int a=0; a<k; a++)
        {
            for(int b=0; b<ch[a].size(); b++)
            {
                auto it=ma.find(va-(su[a]-ch[a][b]));
                if(it!=ma.end())
                {
                    pre[a].push_back((*it).second);
                }
                else pre[a].push_back({-1, -1});
            }
        }

        for(int a=0; a<k; a++)
        {
            for(int b=0; b<ch[a].size(); b++)
            {
                int v=a, i=b, mask=0;
                //cout<<a<<" "<<b<<"\n";
                while(1)
                {
                    mask+=(1<<v);
                    if(pre[v][i].first==-1)
                    {
                        mask=-1;
                        break;
                    }
                    int nv=pre[v][i].first, ni=pre[v][i].second;

                    if(nv==a and ni==b) break;

                    v=nv, i=ni;

                    if(mask&(1<<v))
                    {
                        mask=-1;
                        break;
                    }
                }
                if(mask!=-1) be[mask]={a, b};
            }
        }
    }
    int dp[1<<k], pr[1<<k];
    for(int a=0; a<(1<<k); a++) dp[a]=0;
    dp[0]=1;
    for(int mask=0; mask<(1<<k); mask++)
    {
        if(dp[mask])
        {
            int lef=(1<<k)-1-mask;
            for(int add=lef; add; add=(add-1)&lef)
            {
                if(be[add].first!=-1) dp[mask+add]=1, pr[mask+add]=add;
            }
        }
    }
    if(dp[(1<<k)-1])
    {
        int mask=(1<<k)-1, an[k][2];
        while(mask)
        {
            int cu=pr[mask];
            int v=be[cu].first, i=be[cu].second;
            for(int a=0; a<__builtin_popcountll(cu); a++)
            {
                int nv=pre[v][i].first, ni=pre[v][i].second;
                an[nv][0]=ch[nv][ni], an[nv][1]=v+1;
                v=nv, i=ni;
            }
            mask-=cu;
        }
        cout<<"Yes\n";
        for(int a=0; a<k; a++) cout<<an[a][0]<<" "<<an[a][1]<<"\n";
    }
    else cout<<"No";
}