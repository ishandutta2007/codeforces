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
        string n;
        cin >> n;
        int r=0;
        for(char c:n) r=max(r,c-'0');
        cout << r << "\n";
    }
    return 0;
}