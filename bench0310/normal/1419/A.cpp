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
        string s;
        cin >> s;
        s="$"+s;
        bool odd=0;
        bool even=0;
        for(int i=1;i<=n;i++)
        {
            if((i&1)&&((s[i]-'0')&1)) odd=1;
            if((i&1)==0&&((s[i]-'0')&1)==0) even=1;
        }
        if(n&1) cout << "21"[odd] << "\n";
        else cout << "12"[even] << "\n";
    }
    return 0;
}