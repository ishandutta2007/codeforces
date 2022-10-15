#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main()
{
        ios::sync_with_stdio(0); cin.tie(0);
       // freopen ("input","r",stdin);
        int tt;
        cin>>tt;
        while (tt--)
        {
                int n,k;
                string s;
                cin>>n>>k>>s;
                int t=0;
                for (int i=0;i<n;i++)
                        t+=(s[i]=='W');
                k=min(k,n-t);
                t=t+k;
                int sol=t;
                for (int i=1;i<n;i++)
                        sol+=(s[i-1]=='W'&&s[i]=='W');
                vector<pair<char,int>> b;
                for (int i=0;i<n;i++)
                {
                        if (b.empty()||b.back().first!=s[i])
                                b.push_back({s[i],0});
                        b.back().second++;
                }
                if ((int)b.size()==1&&b[0].first=='L')
                {
                        sol+=max(0,t-1);
                        cout<<sol<<"\n";
                        continue;
                }
                vector<int> lens;
                int sz=(int)b.size();
                for (int i=1;i<sz-1;i++)
                {
                        if (b[i].first=='L')
                        {
                                lens.push_back(b[i].second);
                        }
                }
                vector<int> ex;
                for (int i=0;i<sz;i++)
                        if (b[i].first=='L'&&(i==0||i==sz-1))
                                ex.push_back(b[i].second);
                sol+=k;
                sort(lens.begin(),lens.end());
                for (auto &l : lens)
                {
                        int t=min(l,k);
                        k-=t;
                        l-=t;
                        if (l==0)
                                sol++;
                }
                cout<<sol<<"\n";
        }
}