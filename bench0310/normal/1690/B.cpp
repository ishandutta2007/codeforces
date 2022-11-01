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
        vector<int> tmp(n+1,0);
        for(int i=1;i<=n;i++) cin >> tmp[i];
        int e=-1,m=0;
        bool ok=1;
        for(int i=1;i<=n;i++)
        {
            int a=tmp[i];
            int b;
            cin >> b;
            ok&=(a>=b);
            if(b>0)
            {
                if(e==-1) e=(a-b);
                else ok&=(e==(a-b));
            }
            else m=max(m,a);
        }
        if(ok&&(e==-1||e>=m)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}