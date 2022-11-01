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
        string s;
        cin >> n >> s;
        for(int i=0;i<2*n-1;i+=2) cout << s[i];
        cout << "\n";
    }
    return 0;
}