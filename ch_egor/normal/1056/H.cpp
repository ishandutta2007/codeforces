#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <bitset>
#include <chrono>
#include <random>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int ll;
typedef long double ld;

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 300 * 1000 + 228;
const int MAGIC = 430;

const int ML_ = 990;
char mem_[ML_ * 1024 * 1024];
size_t _ptr = 0, _magic = 21323400;
void* operator new(size_t cnt) {
    if (_ptr + cnt < sizeof mem_) {
        _ptr += cnt; return mem_ + _ptr - cnt;
    } else {
        _ptr = cnt + _magic; return mem_ + _magic;
    }
}
void operator delete(void *) {}

ll Q = -1;

bool is_prime(ll x) {
    if (x == 1) {
        return false;
    }
    if (x == 2) {
        return true;
    }
    if (x % 2 == 0) {
        return false;
    }

    for (ll i = 3; i * i <= x; i += 2) {
        if (x % i == 0) {
            return false;
        }
    }

    return true;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// YA EBAL VAS PIDORI
void gen_fuck(ll &q) {
    ll st = 1000 * 1000 * 1000;
    ll to_add = 1000 * 1000 * 100;

    q = st + rng() % to_add;
    while (!is_prime(q)) {
        q = st + rng() % to_add;
    }
}

int n, q;
bool is_bg[MAX_N];
vector<int> arr[MAX_N];
bool used_now[MAX_N];
int ptr[MAX_N];
vector<ll> harr[MAX_N];
vector<pair<int, ll>> eba[MAX_N];
ll pw[MAX_N];

static inline __attribute__((always_inline)) ll get(int x, int l, int r) {
    return harr[x][r + 1] - harr[x][l] * pw[r - l + 1];
}

int hui() {
    scanf("%d%d", &n, &q);

    for (int i = 0; i < q; ++i) {
        arr[i].clear();
        harr[i].clear();
    }
    for (int i = 0; i < n; ++i) {
        eba[i].clear();
    }

    for (int i = 0; i < q; ++i) {
        int len;
        scanf("%d", &len);
        arr[i].resize(len);
        harr[i].resize(len + 1);
        for (int j = 0; j < len; ++j) {
            scanf("%d", &arr[i][j]);
            --arr[i][j];
        }
        harr[i][0] = 0;
        for (int j = 1; j <= len; ++j) {
            harr[i][j] = harr[i][j - 1] * Q + arr[i][j - 1];
        }

        is_bg[i] = (len >= MAGIC);
    }

    for (int i = 0; i < q; ++i) {
        if (!is_bg[i]) {
            for (int fr = 0; fr < (int)arr[i].size(); ++fr) {
                for (int sc = fr + 1; sc < (int)arr[i].size(); ++sc) {
                    eba[arr[i][fr]].push_back({arr[i][sc], get(i, fr, sc)});
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        sort(eba[i].begin(), eba[i].end());
        for (int j = 1; j < (int)eba[i].size(); ++j) {
            if (eba[i][j].first == eba[i][j - 1].first && eba[i][j].second != eba[i][j - 1].second) {
                printf("Human\n");
                return 0;
            }
        }
    }

    for (int i = 0; i < q; ++i) {
        if (is_bg[i]) {
            for (int j = 0; j < (int)arr[i].size(); ++j) {
                used_now[arr[i][j]] = true;
                ptr[arr[i][j]] = j;
            }

            for (int j = 0; j < q; ++j) {
                if (i == j) {
                    continue;
                }
                int bg_ptr = -1;
                int sl_bg_ptr = -1;
                for (int p = 0; p < (int)arr[j].size(); ++p) {
                    if (used_now[arr[j][p]]) {
                        if (bg_ptr == -1 || ptr[arr[j][p]] < bg_ptr) {
                            bg_ptr = ptr[arr[j][p]];
                            sl_bg_ptr = p;
                        }

                        int now = ptr[arr[j][p]];
                        if (get(i, bg_ptr, now) != get(j, sl_bg_ptr, p)) {
                            printf("Human\n");
                            return 0;
                        }
                    }
                }
            }

            for (int j = 0; j < (int)arr[i].size(); ++j) {
                used_now[arr[i][j]] = false;
            }
        }
    }

    printf("Robot\n");

    return 0;
}

int main() {
#ifdef CH_EGOR
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
#endif

    gen_fuck(Q);
    pw[0] = 1;
    for (int i = 1; i < MAX_N; ++i) {
        pw[i] = pw[i - 1] * Q;
    }

    int t;
    scanf("%d", &t);

    while (t--) {
        hui();
    }

    return 0;
}