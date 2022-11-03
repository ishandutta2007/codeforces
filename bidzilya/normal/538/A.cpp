#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    
    if (s.length() <= 10) {
        cout << "NO" << endl;
        return 0;
    }
    
    int c = s.length() - 10;
    
    for (int i = 0; i + c - 1 < (int) s.length(); ++i) {
        string s1 = s.substr(0, i);
        string s2 = s.substr(i + c);
        
        if (s1 + s2 == "CODEFORCES") {
            cout << "YES" << endl;
            return 0;
        }
    }
    
    cout << "NO" << endl;
    
    return 0;
}