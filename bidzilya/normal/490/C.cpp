#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    string s;
    
    cin >> s;
    
    int n = s.length();
    
    int a, b;
    cin >> a >> b;
        
    vector<int> rema(n);
    vector<int> remb(n);
    
    rema[0] = (s[0] - '0') % a;
    for (int i = 1; i < n; ++i) {
        rema[i] = (rema[i - 1] * 10 + (s[i] - '0')) % a;
    }
    
    vector<int> pw10(n);
    pw10[0] = (1 % b);
    for (int i = 1; i < n; ++i) {
        pw10[i] = (pw10[i - 1] * 10) % b;
    }
    
    remb[n - 1] = (s[n - 1] - '0') % b;
    for (int i = n - 2; i >= 0; --i) {
        remb[i] = (remb[i + 1] + pw10[n - 1 - i] * (s[i] - '0')) % b;
    }
    
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i + 1] != '0' && rema[i] == 0 && remb[i + 1] == 0) {
            cout << "YES" << endl;
            cout << s.substr(0, i + 1) << endl;
            cout << s.substr(i + 1) << endl;
            return 0;
        }
    }
    
    cout << "NO" << endl;
    
    return 0;
}