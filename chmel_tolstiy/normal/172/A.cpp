#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    map<string, int> m[100];
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j <= s.length(); j++)
            m[j][s.substr(0, j)]++;
    }
    int res = 0;
    while (m[res].begin()->second == n) res++;
    
    cout << res - 1 << endl;
    return 0;
}