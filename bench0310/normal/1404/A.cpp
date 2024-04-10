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
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        s="$"+s;
        bool ok=1;
        for(int i=1;i<=k;i++)
        {
            char now='?';
            for(int j=i;j<=n;j+=k)
            {
                if(s[j]!='?')
                {
                    if(now!='?'&&now!=s[j]) ok=0;
                    else now=s[j];
                }
            }
            if(now!='?')
            {
                for(int j=i;j<=n;j+=k) s[j]=now;
            }
        }
        array<int,2> c={0,0};
        for(int i=1;i<=k;i++) if(s[i]!='?') c[s[i]-'0']++;
        if(max(c[0],c[1])>k/2) ok=0;
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}