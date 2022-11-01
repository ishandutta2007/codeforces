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
        for(int &x:a) cin >> x;
        ranges::sort(a);
        cout << ll(a[n-1])+a[n-2]-a[0]-a[1] << "\n";
    }
    return 0;
}