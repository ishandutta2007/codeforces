#include <iostream>

using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    int m = s.size();
    int n = t.size();
    int i = 0, j = 0;
    while (j < m && i < n) {
        if (t[i] == s[j]) j++;
        i++;
    }
    int l = i - 1;
    i = n - 1, j = m - 1;
    while (j >= 0 && i >= 0) {
        if (t[i] == s[j]) j--;
        i--;
    }
    int r = i + 1;
    if (r >= l) cout << r - l << endl;
    else cout << 0 << endl;

    return 0;
}