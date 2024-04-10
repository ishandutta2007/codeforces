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
        int n,k;
        cin >> n >> k;
        vector<int> h(n+1,0);
        for(int i=1;i<=n;i++) cin >> h[i];
        int res=0;
        while(k--)
        {
            res=0;
            for(int i=1;i<n;i++)
            {
                if(h[i]<h[i+1])
                {
                    res=i;
                    h[i]++;
                    break;
                }
            }
            if(res==0)
            {
                res=-1;
                break;
            }
        }
        cout << res << "\n";
    }
    return 0;
}