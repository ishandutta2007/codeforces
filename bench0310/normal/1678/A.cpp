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
        int c=0;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            if(a[i]>0) c++;
        }
        ranges::sort(a);
        bool e=0;
        for(int i=1;i<n;i++) e|=(a[i]==a[i+1]);
        if(c<n) cout << c << "\n";
        else cout << c+(e==0) << "\n";
    }
    return 0;
}