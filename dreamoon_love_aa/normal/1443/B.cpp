#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
const int SIZE = 1e6;
char s[SIZE];
int len[SIZE], v[SIZE], m;
void solve() {
    int a, b;
    scanf("%d%d", &a, &b);
    scanf("%s", s);
    int n = strlen(s);
    m = 0;
    for(int i = 0, j; i < n; i = j) {
        for(j = i; j < n && s[j] == s[i]; j++);
        // [i, j)
        len[m] = j - i;
        v[m] = s[i] - '0';
        m++;
    }
    int one_seg_cnt = 0;
    vector<int> d;
    for(int i = 0 ; i < m; i++) {
        if(v[i] == 1) {
            one_seg_cnt++;
        } else {
            if(i != 0 && i + 1 < m) {
                d.push_back(len[i]);
            }
        }
    }
    sort(d.begin(), d.end());
    long long an = 1e18;
    int len_sum = 0;
    for(int i = 0; i <= (int)d.size(); i++) {
        an = min(an, (long long)(one_seg_cnt - i) * a + len_sum * b);
        if(i < (int)d.size()) {
            len_sum += d[i];
        }
    }
    printf("%lld\n", an);
}
int main() {
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++) {
        solve();
    }
    return 0;
}