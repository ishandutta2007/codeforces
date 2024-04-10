#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

namespace std {

template <typename T>
auto operator+(vector<T> a, const vector<T>& b) {
    a.insert(end(a), begin(b), end(b));
    return a;
}

} // namespace std

int QUERY(const vector<int>& nums) {
    int S = nums.size();
    cout << "? " << S;
    for (int i = 0; i < S; i++) {
        cout << ' ' << nums[i];
    }
    cout << endl;
    string ans;
    cin >> ans;
    return ans == "YES";
}

int QUERY(vector<int> L, const vector<int>& R) {
    L.insert(end(L), begin(R), end(R));
    return QUERY(L);
}

void ANSWER(int n) {
    cout << "! " << n << endl;
    string ans;
    cin >> ans;
    if (ans == ":)") {
        exit(0);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;

    vector<int> opt;
    for (int i = 1; i <= N; i++) {
        opt.push_back(i);
    }

    while (opt.size() >= 4u) {
        int S = opt.size();
        int M0 = 0;
        int M1 = (1 * S + 0) / 4;
        int M2 = (2 * S + 0) / 4;
        int M3 = (3 * S + 0) / 4;
        int M4 = S;

        vector<int> A(begin(opt) + M0, begin(opt) + M1);
        vector<int> B(begin(opt) + M1, begin(opt) + M2);
        vector<int> C(begin(opt) + M2, begin(opt) + M3);
        vector<int> D(begin(opt) + M3, begin(opt) + M4);

        if (QUERY(A, B)) {
            if (QUERY(C)) {
                opt = A + B + C;
            } else {
                opt = A + B + D;
            }
        } else {
            if (QUERY(A)) {
                opt = A + C + D;
            } else {
                opt = B + C + D;
            }
        }
    }

    debug(opt);
    int S = opt.size();
    if (S == 1) {
        ANSWER(opt[0]);
    } else if (S == 2) {
        ANSWER(opt[0]);
        ANSWER(opt[1]);
    } else {
        int x = opt[0];
        int y = opt[1];
        int z = opt[2];
        if (QUERY({x}) || QUERY({x})) {
            ANSWER(x);
            ANSWER(QUERY({y}) ? y : z);
        } else {
            ANSWER(y);
            ANSWER(z);
        }
    }

    return 0;
}