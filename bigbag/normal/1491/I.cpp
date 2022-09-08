/**
 *  created: 05/04/2021, 13:22:49
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 6066, inf = 1000111222;

template<typename T>
ostream& operator << (ostream &os, const vector<T> &v) {
    os << "[";
    for (int i = 0; i < v.size(); ++i) {
        if (i) {
            os << " ";
        }
        os << v[i];
    }
    os << "]";
    return os;
}

struct Animal {
    int a[3], wins, id;

    int get_strength() const {
        return a[wins];
    }
};

ostream& operator << (ostream &os, const Animal &a) {
    os << a.id;
    return os;
}

pair<int, long long> solve_triv(vector<Animal> a) {
    const int n = a.size();
    int pos = 0;
    long long ans = 0;
    while (ans < 3LL * n * n * n) {
        ++ans;
        int nxt = (pos + 1) % n;
        if (a[pos].get_strength() < a[nxt].get_strength()) {
            a[pos].wins = 0;
            a[nxt].wins = 1;
        } else {
            ++a[pos].wins;
            if (a[pos].wins == 3) {
                return {a[pos].id, ans};
            }
            swap(a[pos], a[nxt]);
        }
        pos = nxt;
    }
    return {-1, -1};
}

bool red[max_n];
int closest_not_red[max_n], num_before[max_n];

pair<int, long long> solve(vector<Animal> a) {
    const int n = a.size();
    int pos = 0;
    long long ans = 0;
    while (ans < 2 * n || a[pos].wins != 1) {
        ++ans;
        int nxt = (pos + 1) % n;
        if (a[pos].get_strength() < a[nxt].get_strength()) {
            a[pos].wins = 0;
            a[nxt].wins = 1;
        } else {
            ++a[pos].wins;
            if (a[pos].wins == 3) {
                return {a[pos].id, ans};
            }
            swap(a[pos], a[nxt]);
        }
        pos = nxt;
    }
    while (true) {
        rotate(a.begin(), a.begin() + pos, a.end());
        pos = 0;
        int tot_red = 0, first_red = -1;
        for (int i = 0; i < n; ++i) {
            red[i] = a[i].a[0] < a[(i + n - 1) % n].a[1];
            tot_red += red[i];
            if (first_red == -1 && red[i]) {
                first_red = i;
            }
        }
        assert(!red[pos] && a[pos].wins == 1);
        for (int i = 0; i < n; ++i) {
            assert(!red[i] || !red[(i + 1) % n]);
        }
        if (!tot_red) {
            break;
        }
        if (0) {
            for (int i = pos; i < pos + n; ++i) {
                cout << "(" << a[i % n].id << ", wins = " << a[i % n].wins << " " << "NR"[red[i % n]] << ") ";
            }
            cout << endl;
            break;
        }
        int full_circles = inf, last_red = inf;
        for (int i = n - 1; i >= 0; --i) {
            if (!red[i]) {
                int nxt_red = last_red;
                if (nxt_red == inf) {
                    nxt_red = first_red;
                }
                int nxt = (i + 1) % n;
                if (red[nxt]) {
                    nxt = (nxt + 1) % n;
                }
                if (a[i].a[2] > a[nxt].a[0]) {
                    int circles = nxt_red - i;
                    if (circles < 0) {
                        circles += n;
                    }
                    --circles;
                    full_circles = min(full_circles, circles);
                }
            } else {
                last_red = i;
            }
        }
        vector<pair<int, int>> v;
        int tot_not_red = 0;
        for (int i = 0; i < n; ++i) {
            if (red[i]) {
                closest_not_red[i] = inf;
                auto it = lower_bound(v.begin(), v.end(), make_pair(a[i].a[0], inf));
                if (it != v.begin()) {
                    --it;
                    closest_not_red[i] = 1;
                    int circles = max(0, tot_not_red - it->second - 1);
                    full_circles = min(full_circles, circles);
                }
            } else {
                ++tot_not_red;
                while (!v.empty() && v.back().first > a[i].a[1]) {
                    v.pop_back();
                }
                v.push_back({a[i].a[1], tot_not_red});
            }
        }
        v.clear();
        int tot_not_red_left = tot_not_red;
        tot_not_red = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (red[i]) {
                if (closest_not_red[i] == inf) {
                    auto it = lower_bound(v.rbegin(), v.rend(), make_pair(a[i].a[0], inf));
                    if (it != v.rbegin()) {
                        --it;
                        int circles = max(0, tot_not_red_left + it->second - 1);
                        full_circles = min(full_circles, circles);
                    }
                }
            } else {
                ++tot_not_red;
                if (v.empty() || v.back().first > a[i].a[1]) {
                    v.push_back({a[i].a[1], tot_not_red});
                }
                --tot_not_red_left;
            }
        }
        if (full_circles == inf) {
            break;
        }
        ans += full_circles * (n - 1);
        const int M = n - tot_red;
        for (int i = 0; i < M; ++i) {
            num_before[i] = -1;
        }
        tot_not_red = 0;
        for (int i = 0; i < n; ++i) {
            if (red[i]) {
                int num = ((tot_not_red - full_circles) % M + M) % M;
                //cout << "%% " << i << " " << tot_not_red << " " << num << endl;
                assert(num_before[num] == -1);
                num_before[num] = i;
            } else {
                ++tot_not_red;
            }
        }
        vector<Animal> na;
        na.reserve(n);
        tot_not_red = 0;
        int add = 0;
        for (int i = 0; i < n; ++i) {
            if (!red[i]) {
                if (num_before[tot_not_red] != -1) {
                    na.push_back(a[num_before[tot_not_red]]);
                }
                if (tot_not_red == M - full_circles) {
                    pos = na.size();
                    add = num_before[tot_not_red] != -1;
                }
                na.push_back(a[i]);
                ++tot_not_red;

            }
        }
        if (!full_circles) {
            add = 0;
        }
        assert(na.size() == n);
        for (int i = 0; i < n; ++i) {
            na[i].wins = 0;
            if (i == pos) {
                na[i].wins = 1 + add;
            }
        }
        //cout << a << " -> " << na << " " << full_circles << endl;
        a.swap(na);
        //cout << "#" << ans << " " << pos << endl;

        long long need_ans = ans + 2 * n + 2;
        while (ans < need_ans || a[pos].wins != 1) {
            ++ans;
            int nxt = (pos + 1) % n;
            if (a[pos].get_strength() < a[nxt].get_strength()) {
                a[pos].wins = 0;
                a[nxt].wins = 1;
            } else {
                ++a[pos].wins;
                if (a[pos].wins == 3) {
                    return {a[pos].id, ans};
                }
                swap(a[pos], a[nxt]);
            }
            pos = nxt;
        }
    }
    return {-1, -1};
}

int n;
Animal a[max_n];

const int seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937 generator(seed * 0);

int rnd() {
    return generator() >> 1;
}

int rnd(int r) {
    return rnd() % r;
}

int rnd(int l, int r) {
    return l + rnd(r - l + 1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    if (0) {
        for (int test = 0; ; ++test) {
            n = rnd(4, 500);
            vector<int> v;
            for (int i = 0; i < 3 * n; ++i) {
                v.push_back(i);
            }
            shuffle(v.begin(), v.end(), generator);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < 3; ++j) {
                    a[i].a[j] = v.back();
                    v.pop_back();
                }
                sort(a[i].a, a[i].a + 3);
                swap(a[i].a[0], a[i].a[1]);
                if (rnd(2)) {
                    swap(a[i].a[0], a[i].a[2]);
                }
                a[i].id = i;
            }
            auto p1 = solve_triv({a, a + n});
            auto p2 = solve({a, a + n});
            if (p1 != p2) {
                cout << "OK: " << p1.first << " " << p1.second << endl;
                cout << "WA: " << p2.first << " " << p2.second << endl;
                cout << n << endl;
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        cout << a[i].a[j] << " ";
                    }
                    cout << endl;
                }
                return 1;
            }
            if (test % 1000 == 0) cout << "+ " << test << "\n";
        }
    }
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            scanf("%d", &a[i].a[j]);
        }
        a[i].id = i;
    }
    //auto ans = solve_triv({a, a + n});
    auto ans = solve({a, a + n});
    printf("%d %lld\n", ans.first, ans.second);
    return 0;
}