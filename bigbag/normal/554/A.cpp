#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

string s;
set<string> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    for (char c = 'a'; c <= 'z'; ++c) {
        string s2 = "";
        s2 += c;
        s2 += s;
        q.insert(s2);
    }
    for (int i = 0; i < s.length(); ++i) {
        for (char c = 'a'; c <= 'z'; ++c) {
            string s2 = s.substr(0, i + 1);
            s2 += c;
            s2 += s.substr(i + 1);
            q.insert(s2);
        }
    }
    cout << q.size() << endl;
    return 0;
}