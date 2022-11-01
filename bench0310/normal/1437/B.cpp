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
        int c=0;
        for(int i=0;i<n-1;i++) c+=(s[i]==s[i+1]);
        cout << (c+1)/2 << "\n";
    }
    return 0;
}