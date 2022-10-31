#include <iostream>
#include <vector>

using namespace std;

vector<char> v;
string s;

int main() {
    ios::sync_with_stdio(0);
    cin >> s;
    for(int i = 0; i < s.size(); ++i) {
        if(v.empty() || s[i] != v.back())
            v.push_back(s[i]);
        else
            v.pop_back();
    }
    if(v.empty()) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}