#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, k;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n >> k >> s;
    if(k==0)
    {
        cout << s;
        return 0;
    }
    
    if(n==1)
    {
        cout << 0;
        return 0;
    }

    if(s[0]!='1')
        k--;
    s[0]='1';
    for(int i=1;i<n;i++)
        if(k)
    {
        if(s[i]!='0')
            k--;
        s[i]='0';
    }
    cout << s;
}