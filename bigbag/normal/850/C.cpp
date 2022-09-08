#include <unordered_map>
#include <ctime>
#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 40011, inf = 1011111111;

char used[max_n];
vector<int> p;

void get_all_p() {
    for (int i = 2; i < max_n; ++i) {
        if (used[i] == 0 && i < 40000) {
            p.push_back(i);
            for (int j = i * i; j < max_n; j += i) {
                used[j] = 1;
            }
        }
    }
}

int next_prime(int x) {
    while (used[x] == 1) {
        ++x;
    }
    return x;
}

int n, a[max_n], last, f[55];
vector<int> all_p;
map<pair<long long, long long>, int> res;
//map<long long, int> res;
int p1, p2;

long long get_hash1(const vector<char> &v) {
    long long res = 0, pw = 1;
    for (int i = 0; i < v.size(); ++i) {
        res += pw * (v[i] + 1);
        pw *= p1;
    }
    return res;
}

long long get_hash2(const vector<char> &v) {
    long long res = 0, pw = 1;
    for (int i = 0; i < v.size(); ++i) {
        res += pw * (v[i] + 1);
        pw *= p2;
    }
    return res;
}

int solve(vector<char> v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    pair<long long, long long> h = make_pair(get_hash1(v), get_hash2(v));
    if (res.count(h)) {
        return res[h];
    }
    vector<char> g;
    for (int i = 1; i <= v.back(); ++i) {
        vector<char> to = v;
        for (int j = to.size() - 1; j >= 0 && to[j] >= i; --j) {
            to[j] -= i;
        }
        g.push_back(solve(to));
    }
    ++last;
    for (int i = 0; i < g.size(); ++i) {
        f[g[i]] = last;
    }
    for (int i = 0; ; ++i) {
        if (f[i] < last) {
            return res[h] = i;
        }
    }
}

int main() {
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_p();
    p1 = next_prime(300 + rand() % 300);
    p2 = next_prime(300 + rand() % 300);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        int x = a[i];
        for (int j = 0; p[j] * p[j] <= x; ++j) {
            if (x % p[j] == 0) {
                all_p.push_back(p[j]);
                while (x % p[j] == 0) {
                    x /= p[j];
                }
            }
        }
        if (x > 1) {
            all_p.push_back(x);
        }
    }
    sort(all_p.begin(), all_p.end());
    all_p.erase(unique(all_p.begin(), all_p.end()), all_p.end());
    int ans = 0;
    for (int i = 0; i < all_p.size(); ++i) {
        vector<char> v;
        for (int j = 0; j < n; ++j) {
            int cnt = 0, x = a[j];
            while (x % all_p[i] == 0) {
                x /= all_p[i];
                ++cnt;
            }
            v.push_back(cnt);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        ans ^= solve(v);
    }
    if (ans == 0) {
        printf("Arpa\n");
    } else {
        printf("Mojtaba\n");
    }
    return 0;
}