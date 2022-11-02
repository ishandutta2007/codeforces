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
        vector<int> x(m);
        for(int i=0;i<m;i++) cin >> x[i];
        sort(x.begin(),x.end(),greater<int>());
        int now=0;
        int res=0;
        for(int y:x)
        {
            if(now<y)
            {
                res++;
                now+=(n-y);
            }
        }
        cout << res << "\n";
    }
    return 0;
}