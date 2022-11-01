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
        int px,py;
        cin >> px >> py;
        string s;
        cin >> s;
        int l=0,r=0,u=0,d=0;
        for(char c:s)
        {
            if(c=='U') u++;
            else if(c=='D') d--;
            else if(c=='L') l--;
            else if(c=='R') r++;
        }
        if(l<=px&&px<=r&&d<=py&&py<=u) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}