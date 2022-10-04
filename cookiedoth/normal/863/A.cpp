#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

string s;

int main()
{
    int n;
    cin >> s;
    n = s.length();
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] != '0')
            break;
        s.pop_back();
    }
    string s1 = s;
    reverse(s.begin(), s.end());
    if (s == s1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}