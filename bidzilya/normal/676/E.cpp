#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

const string YES = "Yes";
const string NO = "No";

const int INF = 5e8;

bool IsPrime(int x) {
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

inline void ModSum(int& x, int y, int mod) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
    if (x < 0) {
        x += mod;
    }
}

inline void ModMul(int& x, int y, int mod) {
    x = (1LL * x * y) % mod;
}

int main() {
    srand(13512);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int f = 0;
    vector<int> a(n + 1);
    vector<bool> b(n + 1, false);
    for (int i = 0; i <= n; ++i) {
        string s;
        cin >> s;
        if (s != "?") {
            a[i] = stoi(s);
            b[i] = true;
            f += 1;
        } else {
            b[i] = false;
        }
    }

    bool human = (f & 1);

    if (k == 0) {
        if (b[0]) {
            if (a[0] == 0) {
                cout << YES << endl;
            } else {
                cout << NO << endl;
            }
        } else {
            if (human) {
                cout << YES << endl;
            } else {
                cout << NO << endl;
            }
        }
    } else {
        if (f == (n + 1)) {
            for (int itr = 0; itr < 250; ++itr) {
                int mod = rand() % INF + INF;
                while (!IsPrime(mod)) {
                    ++mod;
                }

                int modK = k % mod;
                if (modK < 0) {
                    modK += mod;
                }

                int sum = 0;
                int pw = 1;
                for (int i = 0; i <= n; ++i) {
                    int cur = a[i] % mod;
                    if (cur < 0) {
                        cur += mod;
                    }
                    ModMul(cur, pw, mod);
                    ModSum(sum, cur, mod);
                    ModMul(pw, modK, mod);
                }

                if (sum != 0) {
                    cout << NO << endl;
                    return 0;
                }
            }
            cout << YES << endl;
        } else {
            if ((n + 1) & 1) {
                cout << NO << endl;
            } else {
                cout << YES << endl;
            }
        }
    }

    return 0;
}