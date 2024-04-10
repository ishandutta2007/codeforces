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
        int r=n;
        while(a[r]==a[n]) r--;
        int c=0;
        while(r>=1)
        {
            c++;
            r-=(n-r);
            while(r>=1&&a[r]==a[n]) r--;
        }
        cout << c << "\n";
    }
    return 0;
}