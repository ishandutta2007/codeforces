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
        bool ok=0;
        for(int i=0;i<n-1;i++) ok|=(a[i]!=a[i+1]);
        if(ok) cout << "1\n";
        else cout << n << "\n";
    }
    return 0;
}