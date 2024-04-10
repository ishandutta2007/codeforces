#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<int> opt[m+1];
        vector<int> occ[n+1];
        for(int i=1;i<=m;i++)
        {
            int k;
            cin >> k;
            for(int j=0;j<k;j++)
            {
                int a;
                cin >> a;
                opt[i].push_back(a);
                occ[a].push_back(i);
            }
        }
        int lim=(m+1)/2;
        int big=0;
        for(int i=1;i<=n;i++) if((int)occ[i].size()>lim) big=i;
        vector<int> res=[&]()->vector<int>
        {
            vector<int> x(m+1,0);
            if(big==0)
            {
                for(int i=1;i<=m;i++) x[i]=opt[i][0];
                return x;
            }
            vector<int> v;
            for(int o:occ[big]) if(opt[o].size()==1) v.push_back(o);
            if((int)v.size()>lim) return {};
            int cnt=0;
            for(int a:v)
            {
                x[a]=big;
                cnt++;
            }
            for(int o:occ[big])
            {
                if(cnt<lim&&x[o]==0)
                {
                    x[o]=big;
                    cnt++;
                }
            }
            for(int i=1;i<=m;i++)
            {
                if(x[i]==0)
                {
                    x[i]=opt[i][0];
                    if(opt[i][0]==big) x[i]=opt[i][1];
                }
            }
            return x;
        }();
        if(!res.empty())
        {
            cout << "YES\n";
            for(int i=1;i<=m;i++) cout << res[i] << " \n"[i==m];
        }
        else cout << "NO\n";
    }
    return 0;
}