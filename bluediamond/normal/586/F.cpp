#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

using namespace std;

struct triple {
        int a;
        int b;
        int c;
};

struct triplet {
        int first;
        int second;
        int third;
};

vector <triple> our;
vector <triplet> res;

inline void bkt(int poz, triplet a) {
        if (poz == (int) our.size()) {
                res.push_back(a);
        } else {
                bkt(poz + 1, {a.first + our[poz].a, a.second + our[poz].a, a.third + our[poz].a}); /// bag a
                bkt(poz + 1, {a.first - our[poz].b, a.second, a.third + our[poz].b}); /// bag b
                bkt(poz + 1, {a.first, a.second - our[poz]. c, a.third + our[poz].c}); /// bag c
        }
}

inline vector <triplet> solve(vector <triple> v) {
        res.clear();
        our = v;
        bkt(0, {0, 0, 0});
        return res;
}

triplet limak;
bool gasit;

bool operator != (triplet a, triplet b) {
        return (a.first != b.first || a.second != b.second || a.third != b.third);
}

string ntt_kek="LMW";
inline void print(int nr) {
        for (int i = 0; i < 3; i++) {
                if (i != nr) {
                        cout << ntt_kek[i];
                }
        }
        cout << "\n";
}

vector <int> ccciq;

inline void bkt2(int poz, triplet a) {
        if (gasit == 1) {
                return;
        }
        if (poz == (int) our.size()) {
                if (a != limak) {
                        return;
                }
                for (auto &it : ccciq) {
                     ///   cout << it;
                        print(it);
                }
                gasit = 1;
                return;
        } else {
                ccciq.push_back(0);
                bkt2(poz + 1, {a.first + our[poz].a, a.second + our[poz].a, a.third + our[poz].a}); /// bag a
                ccciq.pop_back();
                if (gasit == 1) {
                        return;
                }
                ccciq.push_back(1);
                bkt2(poz + 1, {a.first - our[poz].b, a.second, a.third + our[poz].b}); /// bag b
                ccciq.pop_back();
                if (gasit == 1) {
                        return;
                }
                ccciq.push_back(2);
                bkt2(poz + 1, {a.first, a.second - our[poz]. c, a.third + our[poz].c}); /// bag c
                ccciq.pop_back();
                if (gasit == 1) {
                        return;
                }
        }
}

inline void cauta(vector <triple> a, triplet b) {
        gasit = 0;
        our = a;
        limak = b;
        bkt2(0, {0, 0, 0});
}

bool operator < (triplet a, triplet b) {
        if (a.first != b.first) {
                return a.first < b.first;
        }
        if (a.second != b.second) {
                return a.second < b.second;
        }
        if (a.third != b.third) {
                return a.third > b.third;
        }
        return 0;
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int n;
        cin >> n;
        vector <vector <triple>> a(2);
        int jum = n / 2;
        for (int i = 0; i < jum; i++) {
                triple x;
                cin >> x.a >> x.b >> x.c;
                a[0].push_back(x);
        }
        for (int i = jum; i < n; i++) {
                triple x;
                cin >> x.a >> x.b >> x.c;
                a[1].push_back(x);
        }
        int suma = 0, sumb = 0, sumc = 0;
        for (int i = 0; i < 2; i++) {
                for (auto &x : a[i]) {
                        suma += x.a;
                        sumb += x.b;
                        sumc += x.c;
                }
        }
        vector <triplet> x = solve(a[0]);
        vector <triplet> y = solve(a[1]);
        int dif1 = suma - sumb;
        int dif2 = suma - sumc;
        sort(x.begin(), x.end()), sort(y.begin(), y.end());
        int poz = y.size() - 1;
        int minimum = (1 << 30);
        for (auto &it : x) {
                pair <int, int> caut = {dif1 - it.first, dif2 - it.second};
                while (poz >= 0) {
                        pair <int, int> cur = {y[poz].first, y[poz].second};
                        if (caut < cur) {
                                poz--;
                        } else {
                                break;
                        }
                }
                if (poz >= 0) {
                        pair <int, int> cur = {y[poz].first, y[poz].second};
                        if (cur == caut) {
                                minimum = min(minimum, it.third + y[poz].third);
                        }
                }
        }
        poz = y.size() - 1;
        for (auto &it : x) {
                pair <int, int> caut = {dif1 - it.first, dif2 - it.second};
                while (poz >= 0) {
                        pair <int, int> cur = {y[poz].first, y[poz].second};
                        if (caut < cur) {
                                poz--;
                        } else {
                                break;
                        }
                }
                if (poz >= 0) {
                        pair <int, int> cur = {y[poz].first, y[poz].second};
                        if (cur == caut && it.third + y[poz].third == minimum) {
                                cauta(a[0], it);
                                cauta(a[1], y[poz]);
                                return 0;
                        }
                }
        }
        cout << "Impossible\n";
}