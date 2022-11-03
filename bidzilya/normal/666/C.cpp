#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MOD = 1e9 + 7;

inline void ModSum(int& x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
    if (x < 0) {
        x += MOD;
    }
}

inline void ModMul(int& x, int y) {
    x = (1LL * x * y) % MOD;
}

inline int GetModMul(int x, int y) {
    ModMul(x, y);
    return x;
}

inline int GetBinaryPow(int x, int pw) {
    int r = 1;
    while (pw > 0) {
        if (pw & 1) {
            ModMul(r, x);
        }
        ModMul(x, x);
        pw >>= 1;
    }
    return r;
}

inline int GetInv(int x) {
    return GetBinaryPow(x, MOD - 2);
}

const int MAX_N = 1e5 + 100;
const int C = 26;

const int INV_C = GetModMul(C, GetInv(C - 1));

vector<int> fact;
vector<int> invFact;
vector<int> cPow;
vector<int> cInvPow;

const int B = 500;

vector<vector<int>> prec;

void BuildInfo() {
    fact.resize(MAX_N);
    fact[0] = 1;
    for (int i = 1; i < MAX_N; ++i) {
        fact[i] = fact[i - 1];
        ModMul(fact[i], i);
    }
    invFact.resize(MAX_N);
    for (int i = 0; i < MAX_N; ++i) {
        invFact[i] = GetInv(fact[i]);
    }
    cPow.resize(MAX_N);
    cInvPow.resize(MAX_N);
    cPow[0] = 1;
    cInvPow[0] = 1;
    for (int i = 1; i < MAX_N; ++i) {
        cPow[i] = cPow[i - 1];
        cInvPow[i] = cInvPow[i - 1];
        ModMul(cPow[i], C - 1);
        ModMul(cInvPow[i], INV_C);
    }

    prec.assign(B, vector<int>(MAX_N, 0));
    prec[0][0] = 1;
    for (int i = 1; i < MAX_N; ++i) {
        prec[0][i] = prec[0][i - 1];
        ModMul(prec[0][i], C);
    }
    for (int l = 1; l < B; ++l) {
        int sum = prec[l - 1][0];
        for (int i = 1; i < MAX_N; ++i) {
            prec[l][i] = sum;
            ModMul(sum, C - 1);
            ModSum(sum, prec[l - 1][i]);
        }
    }
}

inline int GetC(int n, int k) {
    if (k > n) {
        return 0;
    }
    int r = fact[n];
    ModMul(r, invFact[k]);
    ModMul(r, invFact[n - k]);
    return r;
}

vector<int> qns;

inline int GetFSlow(int l, int n) {
    if (n < l) {
        return 0;
    }
    int r = 0;
    for (int i = 0; i <= n - l; ++i) {
        ModSum(r, GetModMul(GetC(n - i - 1, l - 1), cInvPow[i]));
    }
    ModMul(r, cPow[n - l]);
    return r;
}

void ProcessQueries(int l) {
    if (l < B) {
        for (int n : qns) {
            cout << prec[l][n] << '\n';
        }
    } else {
        vector<int> f(MAX_N, 0);

        for (int i = l; i < MAX_N; ++i) {
            f[i] = GetC(i - 1, l - 1);
            ModMul(f[i], cPow[i - l]);
        }

        vector<pair<int, int>> temp(qns.size());
        for (int i = 0; i < (int) qns.size(); ++i) {
            temp[i].first = qns[i];
            temp[i].second = i;
        }

        sort(temp.begin(), temp.end());

        vector<int> result(qns.size());

        int sum = f[l];

        int lastN = l;
        for (const pair<int, int>& p : temp) {
            const int n = p.first;
            const int qid = p.second;
            if (n < l) {
                result[qid] = 0;
            } else {
                while (lastN != n) {
                    ++lastN;
                    ModMul(sum, C);
                    ModSum(sum, f[lastN]);
                }
                result[qid] = sum;
            }
        }

        for (int i = 0; i < (int) qns.size(); ++i) {
            cout << result[i] << '\n';
        }
    }
    qns.clear();
}

int main() {
    BuildInfo();

    /*
    for (int l = 1; l <= 10; ++l) {
        for (int n = 1; n <= 10; ++n) {
            cout << GetF(l, n) << " ";
        }
        cout << endl;
    }
    return 0;
    freopen("input2.txt", "r", stdin);
    */

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;

    string s;
    cin >> s;

    for (; m; --m) {
        int tp;
        cin >> tp;

        if (tp == 1) {
            ProcessQueries(s.length());

            cin >> s;
        } else {
            int n;
            cin >> n;

            qns.push_back(n);
        }
    }
    ProcessQueries(s.length());

    cout.flush();

    return 0;
}