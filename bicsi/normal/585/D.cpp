#include <bits/stdc++.h>

using namespace std;

int A[30], B[30], C[30];

void afis(int i) {
    if(i == 0) {
        cout<<"MW\n";
    } else if(i == 1) {
        cout<<"LW\n";
    } else {
        cout<<"LM\n";
    }
}

unordered_map<int64_t, pair<int, int>> S1, S2;
void getAll(int b, int e, unordered_map<int64_t, pair<int, int>> &S, int64_t sgn) {
    int mx = 1; for(int i=0; i<(e-b); i++) mx *= 3;

    for(int i=0; i<mx; i++) {
        int sa = 0, sb = 0, sc = 0;

        int use = i;
        for(int j=0; j<e-b; j++) {

            if(use % 3 != 0) sa += A[b+j];
            if(use % 3 != 1) sb += B[b+j];
            if(use % 3 != 2) sc += C[b+j];

            use /= 3;
        }

        int64_t to_find = (sgn*(sb-sa)) * 1298311 + (sgn*(sc-sa));
        if(S.find(to_find) == S.end() || S[to_find].first < sa) {
            S[to_find] = {sa, i};
        }
    }
}

int main() {
    int n;
    cin>>n;

    int mx = 1;
    for(int i=0; i<n; i++) {
        cin>>A[i]>>B[i]>>C[i];
        mx *= 3;
    }

    int mid = n/2;
    getAll(0, mid, S1, 1);
    getAll(mid, n, S2, -1);

    int c1 = 0, c2 = 0, best = -2e9;

    for(auto p : S1) {
        auto it = S2.find(p.first);
        if(it != S2.end()) {
            if(best < p.second.first + it->second.first) {
                best = p.second.first + it->second.first;
                c1 = p.second.second;
                c2 = it->second.second;
            }
        }
    }

    if(best == -2e9) {
        cout<<"Impossible\n";
    } else {
        for(int i=0; i<mid; i++) {
            afis(c1 % 3); c1 /= 3;
        }
        for(int i=mid; i<n; i++) {
            afis(c2 % 3); c2 /= 3;
        }
    }

    return 0;
}