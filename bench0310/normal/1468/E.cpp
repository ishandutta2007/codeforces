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
        vector<ll> a(4);
        for(int i=0;i<4;i++) cin >> a[i];
        ll res=0;
        do
        {
            res=max(res,min(a[0],a[1])*min(a[2],a[3]));
        }while(next_permutation(a.begin(),a.end()));
        cout << res << "\n";
    }
    return 0;
}