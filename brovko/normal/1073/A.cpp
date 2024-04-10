#include <bits/stdc++.h>
#define int long long
#define y1 uwiegewiug

using namespace std;

int n;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    for(int i=0;i<n-1;i++)
        if(s[i]!=s[i+1])
    {
        cout << "YES\n" << s[i] << s[i+1];
        return 0;
    }
    cout << "NO";
}