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
        int x=0;
        int p=1;
        if(n&1)
        {
            p++;
            x=a[1];
        }
        bool ok=1;
        for(;p+1<=n;p+=2)
        {
            int b=a[p];
            int c=a[p+1];
            if(b>c) swap(b,c);
            ok&=(x<=b);
            x=c;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}