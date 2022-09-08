/**
 *  created: 29/08/2021, 18:08:04
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 10111, inf = 1000111222;
const bool debug = 0;

vector<int> hid{1, 6, 4, 2, 3, 5, 4};
int n, k, a[max_n];

int get_OR(int i, int j) {
    cout << "or " << i + 1 << " " << j + 1 << endl;
    if (debug) {
        return hid[i] | hid[j];
    }
    int x;
    cin >> x;
    return x;
}

int get_AND(int i, int j) {
    cout << "and " << i + 1 << " " << j + 1 << endl;
    if (debug) {
        return hid[i] & hid[j];
    }
    int x;
    cin >> x;
    return x;
}

bool get_bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

int restore(int x, int OR, int AND) {
    int res = 0;
    for (int i = 0; i < 30; ++i) {
        if (get_bit(AND, i)) {
            res += 1 << i;
        } else if (!get_bit(OR, i)) {
        } else if (!get_bit(x, i)) {
            res += 1 << i;
        }
    }
    return res;
}

void restore3() {
    int OR[3][3], AND[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = i + 1; j < 3; ++j) {
            OR[i][j] = OR[j][i] = get_OR(i, j);
            AND[i][j] = AND[j][i] = get_AND(i, j);
        }
    }
    for (int i = 0; i < 30; ++i) {
        if (get_bit(AND[0][1], i)) {
            a[0] += 1 << i;
            a[1] += 1 << i;
            continue;
        }
        if (!get_bit(OR[0][1], i)) {
            continue;
        }
        if (!get_bit(OR[0][2], i)) {
            a[1] += 1 << i;
        } else if (!get_bit(OR[1][2], i)) {
            a[0] += 1 << i;
        } else if (get_bit(AND[0][2], i)) {
            a[0] += 1 << i;
        } else if (get_bit(AND[1][2], i)) {
            a[1] += 1 << i;
        } else {
            exit(228);
        }
    }
    a[2] = restore(a[0], OR[0][2], AND[0][2]);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    if (debug) {
        n = hid.size();
        k = 1;
    } else {
        cin >> n >> k;
    }
    restore3();
    for (int i = 3; i < n; ++i) {
        a[i] = restore(a[0], get_OR(0, i), get_AND(0, i));
    }
    sort(a, a + n);
    cout << "finish " << a[k - 1] << endl;
    return 0;
}