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
        string a,b;
        cin >> a >> b;
        a="$"+a;
        b="$"+b;
        int c=0;
        bool ok=1;
        for(int i=1;i<=n;i++)
        {
            c+=(a[i]=='1');
            bool mv=0;
            mv|=(i==n&&a[i]!=b[i]);
            mv|=(i<n&&(a[i]==b[i])!=(a[i+1]==b[i+1]));
            if(mv) ok&=((i%2)==0&&c==i/2);
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}