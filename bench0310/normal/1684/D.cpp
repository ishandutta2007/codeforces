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
        vector<int> v(n,0);
        ll res=0;
        for(int i=0;i<n;i++)
        {
            int a;
            cin >> a;
            res+=a;
            v[i]=(a-(n-i-1));
        }
        ranges::sort(v,greater<>());
        for(int i=0;i<k;i++) res-=v[i];
        res-=(ll(k)*(k-1)/2);
        cout << res << "\n";
    }
    return 0;
}