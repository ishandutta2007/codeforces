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

const int max_n = 111111;

void get_z_function(string s, int z[]) {
    z[0] = 0;
    int l = 0, r = 0;
    for (int i = 1; i < s.length(); ++i) {
        z[i] = 0;
        if (i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }
        while (i + z[i] < s.length() && s[i + z[i]] == s[z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            r = i + z[i] - 1;
            l = i;
        }
    }
}

string s;
int z[max_n];
vector<int> ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    get_z_function(s, z);
    for (int i = s.length() - 1; i >= 0; --i) {
        if (i + z[i] == s.length()) {
            ans.push_back(z[i]);
        }
    }
    /*for (int i = 0; i < s.length(); ++i) {
        cout << z[i] << ' ';
    }
    cout << endl;*/
    sort(z, z + s.length());
    printf("%d\n", ans.size() + 1);
    for (int i = 0; i < ans.size(); ++i) {
        int len = ans[i];
        int l = -1, r = s.length() - 1;
        while (r > l + 1) {
            int mid = (l + r) / 2;
            if (z[mid] < ans[i]) {
                l = mid;
            } else {
                r = mid;
            }
        }
        printf("%d %d\n", ans[i], s.length() - r + 1);
    }
    printf("%d 1", s.length());
    return 0;
}