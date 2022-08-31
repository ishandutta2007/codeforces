#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int level[1000001], counter = -1, ans = 0;

int code (char x) {
    if (x == '<') {
        return 1;
    } else if (x == '{') {
        return 2;
    } else if (x == '[') {
        return 3;
    } else if (x == '(') {
        return 4;
    } else if (x == '>') {
        return 5;
    } else if (x == '}') {
        return 6;
    } else if (x == ']') {
        return 7;
    } else if (x == ')') {
        return 8;
    }
    return 0;
}

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        int t = code(s[i]);
        if (t <= 4) {
            counter++;
            level[counter] = t;
        } else {
            if (counter == -1) {
                cout << "Impossible";
                return 0;
            } else if (t-level[counter] != 4) {
                ans++;
            }
            counter--;
        }
    }
    if (counter != -1) {
        cout << "Impossible";
        return 0;
    }
    cout << ans;
}