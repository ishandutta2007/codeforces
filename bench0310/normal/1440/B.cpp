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
        vector<int> a(n*k,0);
        for(int i=0;i<n*k;i++) cin >> a[i];
        int l=(n+1)/2;
        int r=n-l;
        l--;
        r++;
        ll res=0;
        for(int i=0;i<k;i++) res+=a[n*k-1-r+1-i*r];
        cout << res << "\n";
    }
    return 0;
}