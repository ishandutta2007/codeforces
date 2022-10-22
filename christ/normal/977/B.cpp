#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    string s;
    cin >> s;
    map<pair<char, char>, int> mp;
    for (int x = 0; x < n-1; x++)
        mp[{s[x], s[x+1]}]++;
    pair<char, char> mx;
    int ma = INT_MIN;
    for (auto &x : mp)
        if (x.second > ma)
            ma = x.second, mx = x.first;
    printf("%c%c\n", mx.first, mx.second);
}