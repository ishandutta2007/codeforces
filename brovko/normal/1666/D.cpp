#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string s, t;
        cin >> s >> t;
//cout << "sdg" << endl;
        vector<int> cnt(26, 0);
//        cout << "sdg" << endl;
        for(char c : t)
            cnt[c - 'A']++;
//        cout << "sdg" << endl;

        string s1 = "";
        for(int j = s.size() - 1; j >= 0; j--) {
//            cout << j <<
            if(cnt[s[j] - 'A'] > 0) {
                s1 += s[j];
                cnt[s[j] - 'A']--;
            }
        }

        reverse(s1.begin(), s1.end());
//        cout << s1 << endl;

        cout << (s1 == t ? "YES\n" : "NO\n");
    }
}