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

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            string name = "";
            while (i < s.length() && s[i] >= 'A' && s[i] <= 'Z') {
                name += s[i];
                ++i;
            }
            if (s[i] == ':') {
                int cnt = 1;
                string last_name = "";
                for (int j = i + 1; j < s.length() && cnt > 0; ++j) {
                    if (s[j] >= 'A' && s[j] <= 'Z') {
                        last_name += s[j];
                    }
                    if (s[j] == ':') {
                        ++cnt;
                        if (name == last_name) {
                            ++ans;
                        }
                        last_name = "";
                    }
                    if (s[j] == '.') {
                        --cnt;
                        if (name == last_name) {
                            ++ans;
                        }
                        last_name = "";
                        if (s[j + 1] == ',') {
                            ++cnt;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}