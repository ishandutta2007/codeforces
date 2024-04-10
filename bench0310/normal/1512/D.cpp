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
        vector<int> b(n+2,0);
        for(int i=0;i<n+2;i++) cin >> b[i];
        sort(b.begin(),b.end());
        ll sum=0;
        for(int a:b) sum+=a;
        vector<int> res=[&]()->vector<int>
        {
            for(int i=n;i<n+2;i++)
            {
                int s=b[i];
                for(int j=0;j<n+2;j++)
                {
                    if(j!=i&&sum-s-b[j]==s)
                    {
                        vector<int> a;
                        for(int k=0;k<n+2;k++) if(k!=i&&k!=j) a.push_back(b[k]);
                        return a;
                    }
                }
            }
            return {};
        }();
        if(!res.empty()) for(int i=0;i<n;i++) cout << res[i] << " \n"[i==n-1];
        else cout << "-1\n";
    }
    return 0;
}