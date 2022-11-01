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
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        bool res=0;
        for(int i=0;i<n;i++)
        {
            int x=a[i];
            vector<int> b;
            for(int j=0;j<n;j++) if(j!=i) b.push_back(a[j]);
            function<void(int,int)> go=[&](int j,int sum)
            {
                if(j==n-1)
                {
                    res|=(x==sum);
                    return;
                }
                go(j+1,sum);
                go(j+1,sum+b[j]);
                go(j+1,sum-b[j]);
            };
            go(0,0);
        }
        if(res) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}