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
        vector<ll> s(n+1,0);
        bool ok=1;
        int one=0;
        bool mv=0;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            mv|=(a!=0);
            if(i==1) one=a;
            s[i]=s[i-1]+a;
            ok&=(s[i]>=0);
        }
        ok&=(s[n]==0);
        int c=0;
        for(int i=0;i+1<=n;i++) c+=(s[i]==0&&s[i+1]>0);
        ok&=(c<=1);
        if(mv) ok&=(one>0);
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}