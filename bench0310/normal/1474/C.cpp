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
        int n;
        cin >> n;
        vector<array<int,2>> a(2*n);
        int mx=0;
        for(int i=0;i<2*n;i++)
        {
            cin >> a[i][0];
            a[i][1]=i+1;
            mx=max(mx,a[i][0]);
        }
        vector<array<int,2>> res;
        for(int i=0;i<2*n;i++)
        {
            set<array<int,2>> s(a.begin(),a.end());
            int x=a[i][0]+mx;
            vector<array<int,2>> now;
            bool ok=1;
            for(int j=0;j<n;j++)
            {
                auto it=prev(s.end());
                s.erase(it);
                array<int,2> one=(*it);
                it=s.lower_bound({x-one[0],0});
                if(it==s.end()||(*it)[0]!=x-one[0])
                {
                    ok=0;
                    break;
                }
                array<int,2> two=(*it);
                s.erase(it);
                now.push_back({one[1],two[1]});
                x=max(one[0],two[0]);
            }
            if(ok) res=now;
        }
        if(!res.empty())
        {
            cout << "YES\n";
            cout << a[res[0][0]-1][0]+a[res[0][1]-1][0] << "\n";
            for(auto [x,y]:res) cout << a[x-1][0] << " " << a[y-1][0] << "\n";
        }
        else cout << "NO\n";
    }
    return 0;
}