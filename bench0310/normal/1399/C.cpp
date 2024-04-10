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
        int res=0;
        for(int sum=2;sum<=2*n;sum++)
        {
            multiset<int> s(a.begin(),a.end());
            int now=0;
            while(!s.empty())
            {
                int b=(*s.begin());
                s.erase(s.begin());
                if(s.find(sum-b)!=s.end())
                {
                    now++;
                    s.erase(s.find(sum-b));
                }
            }
            res=max(res,now);
        }
        cout << res << "\n";
    }
    return 0;
}