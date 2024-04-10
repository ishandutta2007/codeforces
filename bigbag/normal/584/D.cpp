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

const int max_n = 1, inf = 1111111111;

const int max_p = 1111111;

int used[max_p];
vector<int> pw;

bool is_prime(int x) {
    if (x <= 1) {
        return false;
    }
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

void get_all_primes() {
    used[0] = 1;
    used[1] = 1;
    for (int i = 2; i < max_p; ++i) {
        if (used[i] == 0) {
            pw.push_back(i);
            if ((long long) i * i < (long long) max_p) {
                for (int j = i * i; j < max_p; j += i) {
                    used[j] = 1;
                }
            }
        }
    }
}

int n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_primes();
    cin >> n;
    if (is_prime(n)) {
        cout << 1 << endl;
        cout << n << endl;
        return 0;
    }
    for (int i = 4; ; ++i) {
        for (int j = 0; pw[j] <= i; ++j) {
            if (used[i - pw[j]] == 0) {
                if (i == n) {
                    cout << 2 << endl;
                    cout << pw[j] << " " << i - pw[j] << endl;
                    return 0;
                }
                if (is_prime(n - i)) {
                    cout << 3 << endl;
                    cout << pw[j] << " " << i - pw[j] << " " << n - i << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}