#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    unordered_map<string, int> m;
    
    for(int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        
        if(m.find(s) == m.end()) {
            cout << "OK\n";
            m[s] = 0;
        } else {
            ++m[s];
            cout << s << m[s] << "\n";
        }
        
    }
    
}