#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n;
string s;

int d(char x, char y)
{
    int p=(y+26-x)%26;
    return min(p, 26-p);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    int Min=1e9;
    for(int i=3;i<n;i++)
        Min=min(Min, d(s[i-3], 'A')+d(s[i-2], 'C')+d(s[i-1], 'T')+d(s[i], 'G'));
    cout << Min;
}