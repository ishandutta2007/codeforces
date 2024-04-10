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
        int x=0,y=0;
        for(int i=0;i<n;i++)
        {
            int b;
            cin >> b;
            x=max(x,min(a[i],b));
            y=max(y,max(a[i],b));
        }
        cout << x*y << "\n";
    }
    return 0;
}