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
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        int l=1,r=n;
        while(l<=r)
        {
            cout << a[l++] << " ";
            if(l<=r) cout << a[r--] << " ";
        }
        cout << "\n";
    }
    return 0;
}