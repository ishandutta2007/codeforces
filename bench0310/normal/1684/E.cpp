#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n,k;
        cin >> n >> k;
        vector<int> a(n+1,0);
        map<int,int> c;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            c[a[i]]++;
        }
        vector<int> opt;
        for(auto [x,cnt]:c) opt.push_back(cnt);
        ranges::sort(opt);
        opt.erase(unique(opt.begin(),opt.end()),opt.end());
        vector<int> now(n+1,0);
        int res=n;
        int e=0;
        for(int i=0;i<n;i++) e+=(!c.contains(i));
        for(auto [x,cnt]:c) if(x>n) now[cnt]++;
        for(int mex=n;mex>=0;mex--)        
        {
            if(c.contains(mex)) now[c[mex]]++;
            int r=0;
            int t=k;
            for(int sz:opt)
            {
                int cnt=min(t/sz,now[sz]);
                t-=(cnt*sz);
                r+=cnt;
            }
            if(k>=e) res=min(res,(int(c.size())+e-r)-mex);
            e-=(!c.contains(mex-1));
        }
        cout << res << "\n";
    }
    return 0;
}