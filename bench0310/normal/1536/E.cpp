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
        int n,m;
        cin >> n >> m;
        int c=0;
        for(int i=0;i<n;i++)
        {
            string s;
            cin >> s;
            for(int j=0;j<m;j++) c+=(s[j]=='#');
        }
        const int mod=1000000007;
        int res=1;
        for(int i=0;i<c;i++) res=(2*res)%mod;
        if(c==n*m) res=(res-1+mod)%mod;
        cout << res << "\n";
    }
    return 0;
}