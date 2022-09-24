//test
#include <bits/stdc++.h>
using namespace std;

using s32 = int;
using u32 = unsigned int;
using s64 = long long;
using u64 = unsigned long long;

//#define DEBUG
//#define MULTITEST

//================//
//=====ASSERT=====//
//================//

#if defined(_WIN32)

#include <yvals.h>

// assert    DEBUG_MODE
#define ERROR_REPORT(condition, message) _STL_VERIFY((condition), message)

#else

#include <iostream>

#define ERROR_REPORT(condition, message)\
if(!(condition)){\
	std::cerr << "error:" << "\nmessage: " << (message) << "\nline: " << __LINE__ << "\nfile: " << __FILE__ << std::endl;\
	exit(EXIT_FAILURE);\
}

#endif

#ifdef DEBUG

#define ASSERT(condition, message) ERROR_REPORT(condition, message)

#else

#define ASSERT(condition, message) (condition)

#endif

//=================//
//======SOLVE======//
//=================//

#include <random>
mt19937_64 rnd(42);

// O(n)
vector<int> merge(vector<int>&A, vector<int>&B) {
    vector<int> res;
    for (int i = 0, j = 0; i < A.size() && j < B.size(); ) {
        if (A[i] < B[j]) {
            i++;
        }
        else if (A[i] > B[j]) {
            j++;
        }
        else { // A[i] == B[j]
            res.push_back(A[i]);
            i++;
            j++;
        }
    }
    return res;
}

void solve(istream& cin) {
    int n, m, p;
    cin >> n >> m >> p;

    vector<string> A(n+1);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<vector<int>> z(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == '1') {
                z[j].push_back(i);
            }
        }
    }

    map<u64, vector<int>> dp;
    for (int i = 0; i < n; i++) {
        dp[0].push_back(i);
    }

    for (int len = 0; len < m; len++) {
        map<u64, vector<int>> ndp;

        for (auto& it : dp) {
            for (int bit = 0; bit < m; bit++) {
                u64 msk = it.first | (1ULL << bit);

                if (msk != it.first) {

                    auto uni = merge(it.second, z[bit]);

                    if (uni.size() >= (n + 1) / 2) {
                        
                        if (ndp.size() <= 10 && ndp.count(msk) == 0) {
                            ndp[msk] = move(uni);
                        }
                    }
                }
            }
        }

        if (ndp.empty()) {
            break;
        }
        dp = move(ndp);
    }

    string res(m, '0');
    if (!dp.empty()) {
        u64 msk = dp.begin()->first;

        res.clear();
        while (msk > 0) {
            res.push_back((msk & 1) + '0');

            msk >>= 1;
        }
        res.resize(m, '0');
    }

    cout << res << "\n";
}


int main() {
#ifdef DEBUG
    ifstream cin("input.txt");
#endif
    ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);

    int t = 1;
#ifdef MULTITEST
    cin >> t;
#endif
    while (t--) {
        solve(cin);
    }

    return 0;
}