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

const int max_p = 1111111;

int used[max_p];

void get_all_primes() {
    for (int i = 2; i < max_p; ++i) {
        if (used[i] == 0) {
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
    cin >> n;
    get_all_primes();
    for (int m = 1; m <= 1000; ++m) {
        if (used[n * m + 1]) {
            cout << m << endl;
            return 0;
        }
    }
    return 0;
}