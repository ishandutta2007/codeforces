#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

#include <cassert>
using namespace std;

const string YES = "Yes";
const string NO = "No";

const int LIM = 1e6 + 1;

vector<bool> isPrime;
vector<int> del;
vector<int> nx;

void BuildIsPrime() {
    isPrime.assign(LIM, true);
    isPrime[0] = isPrime[1] = false;
    del.assign(LIM, -1);
    nx.assign(LIM, -1);
    for (int i = 2; i < LIM; ++i) {
        if (isPrime[i]) {
            del[i] = i;
            nx[i] = 1;

            if (1LL * i * i < LIM) {
                for (int j = i * i, x = i; j < LIM; j += i, ++x) {
                    del[j] = i;
                    nx[j] = x;
                    isPrime[j] = false;
                }
            }
        }
    }
}

inline bool IsSolvable(int t, int k) {
    if (t == 0) {
        return false;
    } else {
        return true;
    }
}

int main() {
    /*
    freopen("input2.txt", "w", stdout);
    const int N = 1e6;
    cout << N << " " << N << endl;
    for (int i = 0; i < N; ++i) {
        cout << i + 1 << " ";
    }
    cout << endl;
    return 0;
    freopen("input2.txt", "r", stdin);
    */

    BuildIsPrime();

    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> powers(LIM, 0);
    for (int i = 0; i < n; ++i) {
        int c;
        scanf("%d", &c);

        while (c > 1) {
            int d = del[c];
            int pw = 0;
            while (c % d == 0) {
                c /= d;
                ++pw;
            }

            powers[d] = max(powers[d], pw);
        }
    }

    int t = 1 % k;
    for (int i = 2; i < LIM; ++i) {
        if (isPrime[i]) {
            for (int j = 0; j < powers[i]; ++j) {
                t = (1LL * t * i) % k;
            }
        }
    }

    if (IsSolvable(t, k)) {
        printf("%s\n", NO.c_str());
    } else {
        printf("%s\n", YES.c_str());
    }

    return 0;
}