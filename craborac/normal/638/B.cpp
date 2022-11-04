#include <bits/stdc++.h>

using namespace std;

int n;
string s[100];
int nex[26];
int pre[26];
int cnt[26];
vector<int> ans;

int main() {
    cin >> n;
    for (int i = 0; i < 26; i++) {
        nex[i] = -1;
        pre[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < s[i].size(); j++) {
            cnt[s[i][j] - 'a']++;
        }
        for (int j = 0; j < s[i].size() - 1; j++) {
            nex[s[i][j] - 'a'] = (int) (s[i][j + 1] - 'a');
        }
        for (int j = 1; j < s[i].size(); j++) {
            pre[s[i][j] - 'a'] = (int) (s[i][j - 1] - 'a');
        }
    }
    for (int i = 0; i < 26; i++) {
        if (nex[i] == -1) {
            int x = i;
            if (cnt[x] != 0) {
                ans.push_back(x);
            }
            while (pre[x] != -1) {
                x = pre[x];
                ans.push_back(x);
            }
        }
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << (char) (ans[i] + 'a');
    }
    cout << "\n";
}