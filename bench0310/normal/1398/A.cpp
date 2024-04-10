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
        vector<array<int,2>> a(n);
        for(int i=0;i<n;i++)
        {
            cin >> a[i][0];
            a[i][1]=i+1;
        }
        sort(a.begin(),a.end());
        if(a[0][0]+a[1][0]<=a[n-1][0]) cout << a[0][1] << " " << a[1][1] << " " << a[n-1][1] << "\n";
        else cout << "-1\n";
    }
    return 0;
}