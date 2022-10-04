#include <bits/stdc++.h>

using namespace std;

int n, bd = 0;
string s;

int main()
{
    cin >> n;
    cin >> s;
    for (int i = 0; i<n; ++i) {
        if (s[i] == '<') bd++;
        else break;
    }
    for (int i = n-1; i>=0; --i) {
        if (s[i] == '>') bd++;
        else break;
    }
    cout << bd;
    return 0;
}