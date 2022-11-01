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
        int zero=0;
        vector<int> v;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            if(a==0) zero++;
            else v.push_back(a);
        }
        for(int o=1;o<=n-1;o++)
        {
            int nzero=max(0,zero-1);
            vector<int> u;
            if(zero>=1&&!v.empty()) u.push_back(v[0]);
            for(int i=0;i+1<(int)v.size();i++)
            {
                if(v[i+1]-v[i]==0) nzero++;
                else u.push_back(v[i+1]-v[i]);
            }
            zero=nzero;
            v=u;
            ranges::sort(v);
        }
        cout << (zero==1?0:v[0]) << "\n";
    }
    return 0;
}