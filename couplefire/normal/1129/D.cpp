#include <bits/stdc++.h>
using namespace std;

const int B = 300;
const int mod = 998244353;
const int N = 1e5+10 + B;
int n, k, arr[N];
int memo[N];

int which(int i) {
    return i/B;
}

void mod_add(int &a, int b) {
    a = (a+1LL*b)%mod;
}

struct bucket {
    int ID;
    int offset = 0;
    int cnt[B];
    int prefix[B];
    void rebuild() {
        int mn = cnt[0];
        for(int i = 0; i < B; ++i) {
            mn = min(mn, cnt[i]);
        }
        offset += mn;
        for(int i = 0; i < B; ++i) {
            prefix[i] = 0;
        }
        for(int i = 0; i < B; ++i) {
            cnt[i] -= mn;
            assert(0 <= cnt[i] && cnt[i] < B);
            mod_add(prefix[cnt[i]], memo[i+ID*B]);
        }
        for(int i = 1; i < B; ++i) {
            mod_add(prefix[i], prefix[i-1]);
        }
    }
}buckets[N/B+3];

void add(int L, int R, int diff) {
    for(int i = L; i <= R && which(i) == which(L); ++i) {
        buckets[which(i)].cnt[i-i/B*B] += diff;
    }
    buckets[which(L)].rebuild();
    if(which(L) == which(R)) return;
    for(int i = which(L)+1; i < which(R); ++i) {
        buckets[i].offset += diff;
    }
    for(int i = R; i >= 0 && which(i) == which(R); --i) {
        buckets[which(i)].cnt[i-i/B*B] += diff;
    }
    buckets[which(R)].rebuild();
}

int query(int R) {
    if(R < 0) return 0;
    int sum = 0;
    for(int i = 0; i <= which(R); ++i) {
        int tgt = k - buckets[i].offset;
        tgt = min(tgt, B-1);
        if(tgt < 0) continue;
        mod_add(sum, buckets[i].prefix[tgt]);
    }
    assert(0 <= sum && sum < mod);
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    vector<vector<int>> pos(n+1);
    for(int i = 0; i <= which(n); ++i) {
        buckets[i].ID = i;
    }
    for(int i = 0; i <= n; ++i) {
        pos[i].push_back(-1);
    }
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    memo[0] = 1;
    buckets[which(0)].rebuild();
    for(int i = 0; i < n; ++i) {
        int currS = pos[arr[i]].size();
        if(currS >= 2) {
            int L = pos[arr[i]][currS-2]+1;
            int R = pos[arr[i]].back();
            add(L, R, -1);
        }
        add(pos[arr[i]].back()+1, i, 1);
        memo[i+1] = query(i);
        pos[arr[i]].push_back(i);
        buckets[which(i+1)].rebuild();
    }
    cout << memo[n];
}