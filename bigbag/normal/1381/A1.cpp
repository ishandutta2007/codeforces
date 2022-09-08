#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;
}

int t, n, a[max_n], b[max_n];
string s1, s2;
vector<int> ans;

bool rev, x;
int l, r;

int get_elem() {
    if (rev) {
        return a[r] ^ x;
    }
    return a[l] ^ x;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        s1 = read();
        s2 = read();
        for (int i = 0; i < n; ++i) {
            a[i] = s1[i] - '0';
            b[i] = s2[i] - '0';
        }
        ans.clear();
        rev = 0;
        l = 0;
        r = n - 1;
        x = 0;
        for (int i = n - 1; i >= 0; --i) {
            //cout << i << " " << l << " " << r << ": " << rev << endl;
            if (get_elem() == b[i]) {
                if (!i) {
                    break;
                }
                if (rev) {
                    a[r] ^= 1;
                } else {
                    a[l] ^= 1;
                }
                ans.push_back(1);
                if (!i) {
                    break;
                }
            }
            ans.push_back(i + 1);
            if (!rev) {
                ++l;
            } else {
                --r;
            }
            rev ^= 1;
            x ^= 1;
        }
        printf("%d ", ans.size());
        for (int x : ans) {
            printf("%d ", x);
        }
        puts("");
    }
    return 0;
}