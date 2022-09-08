/**
 *  created: 27/07/2021, 15:22:15
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 44, inf = 1000111222;
const int max_k = 12;

int n, k, a[max_n], b[max_k][max_n];
vector<int> ids[max_k];

void check(int pos) {
    if (pos == k) {
        if (!is_sorted(a, a + n) || (n > 1 && *min_element(a, a + n) == 0)) {
            puts("REJECTED");
            exit(0);
        }
        return;
    }
    int c_ones = 0, c_twos = 0, c_zeros = 0;
    for (int i : ids[pos]) {
        b[pos][i] = a[i];
        c_zeros += a[i] == 0;
        c_ones += a[i] == 1;
        c_twos += a[i] == 2;
    }
    for (int cnt = 0; cnt <= c_zeros; ++cnt) {
        for (int i = 0; i < cnt + c_ones; ++i) {
            a[ids[pos][i]] = 1;
        }
        for (int i = cnt + c_ones; i < ids[pos].size(); ++i) {
            a[ids[pos][i]] = 2;
        }
        check(pos + 1);
    }
    for (int i : ids[pos]) {
        a[i] = b[pos][i];
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int cnt;
        cin >> cnt;
        ids[i].resize(cnt);
        for (int &id : ids[i]) {
            scanf("%d", &id);
            --id;
        }
    }
    check(0);
    puts("ACCEPTED");
    return 0;
}