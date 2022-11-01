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
        string tmp=s;
        ranges::reverse(tmp);
        cout << (k>0?(1+(s!=tmp)):1) << "\n";
    }
    return 0;
}