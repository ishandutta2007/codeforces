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

const int max_n = 111, max_q = 555, inf = 111111111;

int str_to_int(string s) {
    int x = 0;
    for (int i = 0; i < s.length(); ++i) {
        x = x * 10 + s[i] - '0';
    }
    return x;
}

int k, n, m, q, cnt[max_n], f2[max_n][max_n];
string s[max_n], f1[max_n][max_n], art[max_q], sss[max_n];
int num[max_q];
map<string, int> used[max_n];
vector<string> ans[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> k >> n >> m >> q;
    for (int i = 0; i < n; ++i) {
        cin >> sss[i];
    }
    for (int i = 0; i < m; ++i) {
        string ss;
        cin >> ss;
        s[i] += ss;
        cnt[i] = 0;
        s[i].erase(s[i].length() - 1, 1);
        while (true) {
            cin >> f1[i][cnt[i]] >> f2[i][cnt[i]];
            ++cnt[i];
            char c;
            cin >> c;
            if (c != ',') {
                s[i + 1] += c;
                break;
            }
        }
    }
    if (m == 0) {
        for (int i = 0; i < q; ++i) {
            cin >> num[i] >> art[i];
        }
    } else {
        char c = '1';
        num[0] = s[m][0] - '0';
        //cout << "&" << c << endl;
        while (c >= '0' && c <= '9') {
            cin >> c;
            if (c >= '0' && c <= '9') {
                num[0] = num[0] * 10 + c - '0';
            }
        }
        //cout << "#" << c << endl;
        cin >> art[1];
        art[0] += c;
        if (art[1][0] >= '0' && art[1][0] <= '9') {
            num[1] = str_to_int(art[1]);
            if (q > 1) {
                cin >> art[1];
            }
            for (int i = 2; i < q; ++i) {
                cin >> num[i] >> art[i];
            }
        } else {
            art[0] += art[1];
            for (int i = 1; i < q; ++i) {
                cin >> num[i] >> art[i];
            }
        }
    }
    /*cout << endl;
    for (int i = 0; i < m; ++i) {
        cout << i << " - " << s[i] << ' ' << cnt[i] << " : ";
        for (int j = 0; j < cnt[i]; ++j) {
            cout << f1[i][j] << ' ' << f2[i][j] << "; ";
        }
        cout << endl;
    }
    for (int i = 0; i < q; ++i) {
        cout << num[i] << ' ' << art[i] << endl;
    }*/
    for (int i = 0; i < q; ++i) {
        ++used[num[i]][art[i]];
        for (int j = 0; j < m; ++j) {
            int f = 0;
            for (int w = 0; w < cnt[j]; ++w) {
                if (used[num[i]][f1[j][w]] < f2[j][w]) {
                    f = 1;
                    break;
                }
            }
            if (f == 0) {
                ans[num[i]].push_back(s[j]);
                for (int w = 0; w < cnt[j]; ++w) {
                    used[num[i]][f1[j][w]] -= f2[j][w];
                }
                break;
            }
        }
    }
    for (int i = 1; i <= k; ++i) {
        vector<pair<string, int> > Ans;
        for (int j = 0; j < n; ++j) {
            if (used[i][sss[j]] != 0) {
                Ans.push_back(make_pair(sss[j], used[i][sss[j]]));
            }
        }
        sort(ans[i].begin(), ans[i].end());
        for (int j = 0; j < ans[i].size(); ++j) {
            int CNT = 1;
            while (j + 1 < ans[i].size() && ans[i][j] == ans[i][j + 1]) {
                ++j;
                ++CNT;
            }
            Ans.push_back(make_pair(ans[i][j], CNT));
        }
        sort(Ans.begin(), Ans.end());
        cout << Ans.size() << endl;
        for (int j = 0; j < Ans.size(); ++j) {
            cout << Ans[j].first << ' ' << Ans[j].second << endl;
        }
    }
    return 0;
}