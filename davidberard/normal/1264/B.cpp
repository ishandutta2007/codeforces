#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

int ans[20];
int rem;

bool solve(int have[4], int need[4], int seq[20], int nxt) {
    bool seen = 0;
    for (int i=0; i<4; ++i) {
        if (have[i] < need[i]) {
            seen = 1;
            have[i]++;
            seq[nxt] = i;
            bool res = solve(have, need, seq, nxt+1);
            if (res) return true;
            have[i]--;
        }
    }
    if (!seen) {
        for (int i=0; i<nxt-1; ++i) {
            if (abs(seq[i] - seq[i+1]) != 1) return false;
        }
        for (int i=0; i<nxt; ++i) {
            ans[i] = seq[i];
        }
        rem = nxt;
        return true;
    }
    return false;
}

int big[5][5];
int init[4];
int need[4];
int have[4];

vector<int> ord[6];

void setup() {
    ord[0] = vector<int>({0, 1, 2});
    ord[1] = vector<int>({0, 2, 1});
    ord[2] = vector<int>({1, 0, 2});
    ord[3] = vector<int>({1, 2, 0});
    ord[4] = vector<int>({2, 0, 1});
    ord[5] = vector<int>({2, 1, 0});
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setup();
    cin >> init[0] >> init[1] >>  init[2] >> init[3];
    for (int q=0; q<6; ++q) {
        for (int i=0; i<4; ++i) {
            need[i] = init[i];
        }
        memset(big, 0, sizeof(int)*25);
        memset(have, 0, sizeof(int)*4);
        for (int j=0; j<3; ++j) {
            int i = ord[q][j];
            cerr << "-> " << i << endl;
            big[i][i+1] += max(min(need[i], need[i+1])-1, 0);
            need[i] -= big[i][i+1];
            need[i+1] -= big[i][i+1];
        }
        bool should_skip = false;
        for (int i=0; i<4; ++i) {
            cerr << "! " << need[i] << endl;
            if (need[i] > 3) {
                should_skip = true;
            }
        }
        if (should_skip) continue;
        cerr << " gonna run " << endl;
        int seq[20];
        memset(seq, 0, 20*sizeof(int));

        bool res = solve(have, need, seq, 0);
        if (res == false) {
            continue;
        }

        cout << "YES\n";
        for (int i=0; i<rem; ++i) {
            cout << seq[i] << " ";
            int j = seq[i];
            int k = j+1;
            while (big[j][k]) {
                cout << k << " " << j << " ";
                --big[j][k];
            }
        }
        cout << endl;
        return 0;
    }

    cout << "NO\n";

    return 0;
}