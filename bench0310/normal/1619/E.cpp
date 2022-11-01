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
        vector<int> c(n+1,0);
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            c[a]++;
        }
        vector<ll> b(n+1,-1);
        b[0]=0;
        vector<int> v;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=c[i-1];j++) v.push_back(i-1);
            if(v.empty()) break;
            b[i]=b[i-1]+(i-1-v.back());
            v.pop_back();
        }
        for(int i=0;i<=n;i++)
        {
            ll res=(b[i]!=-1?b[i]+c[i]:-1);
            cout << res << " \n"[i==n];
        }
    }
    return 0;
}