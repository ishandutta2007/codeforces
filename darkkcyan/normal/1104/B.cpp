#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    string s;
    cin >> s;
    string stk;
    bool winner = 1;
    for (auto ch: s) {
        if (stk.size() and stk.back() == ch) {
            stk.pop_back();
            winner = !winner;
        } else stk.push_back(ch);
    }
    cout << (winner ? "No" : "Yes");
    
    return 0;
}