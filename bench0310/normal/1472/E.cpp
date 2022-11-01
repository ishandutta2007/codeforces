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
        vector<array<int,3>> v;
        for(int i=1;i<=n;i++)
        {
            int a,b;
            cin >> a >> b;
            v.push_back({a,b,i});
            v.push_back({b,a,i});
        }
        sort(v.begin(),v.end());
        map<int,int> m;
        int idx=0;
        vector<int> res(n+1,0);
        for(auto [a,b,i]:v)
        {
            while(idx<2*n&&v[idx][0]<a)
            {
                m[v[idx][1]]=v[idx][2];
                idx++;
            }
            if(res[i]!=0) continue;
            auto it=m.lower_bound(b);
            if(it==m.begin()) res[i]=-1;
            else
            {
                it--;
                res[i]=(it->second);
            }
        }
        for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
    }
    return 0;
}