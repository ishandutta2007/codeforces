#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;

string s, s1;
vector<string> str;

int main()
{
    cin >> s >> s1;
    int n = s.length();
    int m = s1.length();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            str.push_back(s.substr(0, i) + s1.substr(0, j));
        }
    }
    sort(str.begin(), str.end());
    cout << str[0] << endl;
    return 0;
}