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
        vector<array<int,2>> v; //c,0-double,1-up,2-down
        map<int,vector<int>> z;
        for(int i=0;i<m;i++)
        {
            int r,c;
            cin >> r >> c;
            z[c].push_back(r);
        }
        for(auto [c,x]:z)
        {
            int a=x[0];
            if(x.size()==1) v.push_back({c,a});
            else v.push_back({c,0});
        }
        sort(v.begin(),v.end());
        int sz=v.size();
        bool ok=[&]()->bool
        {
            int l=0;
            while(l<sz)
            {
                if(v[l][1]==0)
                {
                    l++;
                    continue;
                }
                if(l+1==sz||v[l+1][1]==0) return 0;
                if(((v[l+1][0]-v[l][0])&1)==(v[l][1]!=v[l+1][1])) return 0;
                l+=2;
            }
            return 1;
        }();
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}