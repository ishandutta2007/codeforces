/**
 *  created: 17/07/2021, 18:24:13
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;
}

const int max_c = 222;

int t, cnt[max_c];
string s;

string solve() {
    memset(cnt, 0, sizeof(cnt));
    for (char c : s) {
        ++cnt[c];
    }
    for (char c = 'a'; c <= 'z'; ++c) {
        if (cnt[c] == 1) {
            string ans;
            ans += c;
            --cnt[c];
            for (char c2 = 'a'; c2 <= 'z'; ++c2) {
                for (int i = 0; i < cnt[c2]; ++i) {
                    ans += c2;
                }
            }
            return ans;
        }
        if (cnt[c] == s.size()) {
            return s;
        }
    }
    string ans, our, other1, other2;
    for (char c = 'a'; c <= 'z'; ++c) {
        if (cnt[c]) {
            our = string(cnt[c], c);
            for (char c2 = c + 1; c2 <= 'z'; ++c2) {
                if (cnt[c2]) {
                    other1 = string(cnt[c2], c2);
                    for (char c3 = c2 + 1; c3 <= 'z'; ++c3) {
                        if (cnt[c3]) {
                            for (int i = 0; i < cnt[c3]; ++i) {
                                other2 += c3;
                            }
                        }
                    }
                    break;
                }
            }
            reverse(other2.begin(), other2.end());
            break;
        }
    }
    assert(our.size() >= 2 && other1.size() >= 1);
    string other = other2 + other1;
    if (our.size() - 2 <= other1.size() + other2.size()) {
        ans += our.back();
        our.pop_back();
        ans += our.back();
        our.pop_back();
        ans += other.back();
        other.pop_back();
        while (!our.empty()) {
            ans += our.back();
            our.pop_back();
            if (!other.empty()) {
                ans += other.back();
                other.pop_back();
            }
        }
        while (!other.empty()) {
            ans += other.back();
            other.pop_back();
        }
        return ans;
    }
    if (other2.empty()) {
        ans += our.back();
        our.pop_back();
        ans += other;
        ans += our;
        return ans;
    } else {
        ans += our.back();
        our.pop_back();
        ans += other1.back();
        other1.pop_back();
        ans += our;
        our.clear();
        ans += other2.back();
        other2.pop_back();
    }
    ans += our;
    ans += other1;
    reverse(other2.begin(), other2.end());
    ans += other2;
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &t);
        s = read();
        string ans = solve();
        puts(ans.c_str());
    }
    return 0;
}