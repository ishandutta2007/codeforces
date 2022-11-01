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
        ll k;
        cin >> n >> k;
        ll sum;
        cin >> sum;
        ll res=0;
        for(int i=1;i<n;i++)
        {
            ll p;
            cin >> p;
            ll c=max(0ll,(100*p+k-1)/k-sum);
            sum+=c;
            res+=c;
            sum+=p;
        }
        cout << res << "\n";
    }
    return 0;
}