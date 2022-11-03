#include <bits/stdc++.h>
using namespace std;

bool IsPalindrome(const string& s)
{
    string t(s.begin(), s.end());
    reverse(t.begin(), t.end());
    return s == t;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.length();
    
    if (n % k != 0) {
        cout << "NO" << endl;
        return 0;
    }
    
    int len = n / k;
    for (int i = 0; i < k; ++i) {
        if (!IsPalindrome(s.substr(i * len, len))) {
            cout << "NO" << endl;
            return 0;
        }
    }
    
    cout << "YES" << endl;
    
    
    return 0;
}