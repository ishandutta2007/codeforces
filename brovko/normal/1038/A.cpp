#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, k, b[128];
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    cin >> s;
    for(int i=0;i<n;i++)
        b[s[i]-'A']++;
    int Min=1e9;
    for(int i=0;i<k;i++)
        Min=min(Min, b[i]);
    cout << Min*k;
}