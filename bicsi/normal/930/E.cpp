#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> ReadAndPurge(int n) {
    vector<pair<int, int>> v, w;
    for (int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        v.emplace_back(a, -b);    
    }

    sort(v.begin(), v.end());
    for (auto x : v) {
        x.second = -x.second;
        while (w.size() && w.back().second >= x.second)
            w.pop_back();
        w.push_back(x);
    }

    for (int i = 1; i < (int)w.size(); ++i) {
        assert(w[i].first > w[i - 1].first);
        assert(w[i].second > w[i - 1].second);
    }
    return w;
}

const int kMod = 1e9 + 7;
struct ModInt {
    long long x;
    ModInt(long long x = 0) : x(x % kMod) {}
    ModInt operator+(const ModInt& oth) { return x + oth.x; }
    ModInt operator-(const ModInt& oth) { return x - oth.x; }
    ModInt operator*(const ModInt& oth) { return x * oth.x; }
    int Get() const { return (x < 0 ? x + kMod : x); }
};


struct FenwickTree {
    vector<ModInt> T;
    FenwickTree(int n) : T(n + 1, 0) {}
    
    void Update(int pos, ModInt val) {
        for (++pos; pos > 0; pos -= (pos & -pos)) {
            T[pos] = T[pos] + val;
        }
    }

    ModInt Query(int pos) {
        ModInt ret = 0;
        for (++pos; pos < (int)T.size(); pos += (pos & -pos)) {
            ret = ret + T[pos];
        }
        return ret;
    }
};

ModInt POW(int e) {
    ModInt b = 2, r = 1;
    while (e) {
        if (e % 2) r = r * b;
        b = b * b;
        e /= 2;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int k, n, m; cin >> k >> n >> m;
    auto need_white = ReadAndPurge(n), need_black = ReadAndPurge(m);
    //cerr << "need_white:" << endl;
    //for (auto x : need_white) cerr << x.first << " " << x.second << endl;
    //cerr << "need_black:" << endl;
    //for (auto x : need_black) cerr << x.first << " " << x.second << endl;
    
    vector<int> special = {1, k + 1};
    for (auto v : {need_black, need_white}) {
        for (auto x : v) {
            special.push_back(x.first);
            special.push_back(x.second + 1);
        }
    }
    sort(special.begin(), special.end());
    special.erase(unique(special.begin(), special.end()), special.end());
    
    vector<pair<int, int>> ranges;
    for (int i = 1; i < (int)special.size(); ++i) {
        ranges.emplace_back(special[i - 1], special[i] - 1);
    }
    n = ranges.size();
    
    //cerr << "ranges:" << endl;
    //for (auto x : ranges) cerr << x.first << " " << x.second << endl;
    
    FenwickTree all_black(n + 1), all_white(n + 1), mixed(n + 1);
    mixed.Update(0, 1);

    
    int white_at = -1, black_at = -1, all_white_at = -1, all_black_at = -1;
    for (int i = 0; i < n; ++i) {
        //cerr << "At: " << i << endl;
       // cerr << ranges[i].first << " " << ranges[i].second << endl;
        ModInt mx, bl, wh;

        // Try mixed
        {
            int len = ranges[i].second - ranges[i].first + 1;
            if (len > 1) {
                ModInt coef = POW(len) - 2;
                ModInt now = all_black.Query(i) + all_white.Query(i) 
                    + mixed.Query(i);
                mx = now * coef;
                //cerr << "mixed[" << i << "] = " << now.Get() << endl;
            }
        }
        // Try white
        {
            while (black_at + 1 < (int)need_black.size()) {
                if (need_black[black_at + 1].second <= ranges[i].second)
                    ++black_at;
                else break;
            }
            while (black_at != -1 && all_black_at < n) {
                all_black_at = max(all_black_at, 0);
                if (ranges[all_black_at].first < need_black[black_at].first)
                    ++all_black_at;
                else break;    
            }
            ModInt now = all_black.Query(all_black_at + 1) + mixed.Query(all_black_at + 1);
            wh = now;
//            cerr << "all_white[" << i << "] = " << now.Get() << endl;
        }
        // Try black
        {
            while (white_at + 1 < (int)need_white.size()) {
                if (need_white[white_at + 1].second <= ranges[i].second)
                    ++white_at;
                else break;;
            }
            while (white_at != -1 && all_white_at < n) {
                all_white_at = max(all_white_at, 0);
                if (ranges[all_white_at].first < need_white[white_at].first)
                    ++all_white_at;
                else break;    
            }
            ModInt now = all_white.Query(all_white_at + 1) + mixed.Query(all_white_at + 1);
            bl = now;
//            cerr << "all_black[" << i << "] = " << now.Get() << endl;
        }

        mixed.Update(i + 1, mx);
        all_black.Update(i + 1, bl);
        all_white.Update(i + 1, wh);
    }

    ModInt ret = all_black.Query(n) + all_white.Query(n) + mixed.Query(n);
    cout << ret.Get() << endl;

    return 0;
}