#include <bits/stdc++.h>
#ifdef LOCAL
#include "../../../../code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

template <typename Fun>
class y_combinator_result {
    Fun fun_;

  public:
    template <typename T>
    explicit y_combinator_result(T&& fun) : fun_(std::forward<T>(fun)) {}

    template <typename... Args>
    decltype(auto) operator()(Args&&... args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template <typename Fun>
auto y_combinator(Fun&& fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

bool ordered(int a, int b, int c) { return a <= b && b <= c; }

template <typename T, typename... Rs>
struct multiset_rollback : multiset<T, Rs...> {
    using base_t = multiset<T, Rs...>;

    enum Operation { INSERT, ERASE };
    vector<pair<Operation, T>> history;

    template <typename... Args>
    explicit multiset_rollback(Args&&... args) : base_t(forward<Args>(args)...) {}

    int time() const { return history.size(); }

    void rollback(int t) {
        int i = time();
        while (i-- > t) {
            const auto& [op, value] = history.back();
            if (op == INSERT) {
                base_t::erase(base_t::find(value));
            } else if (op == ERASE) {
                base_t::insert(value);
            }
            history.pop_back();
        }
    }

    void insert(const T& value) {
        history.emplace_back(INSERT, value);
        base_t::insert(value);
    }

    void erase(const T& value) {
        if (auto it = base_t::find(value); it != base_t::end()) {
            history.emplace_back(ERASE, value);
            base_t::erase(it);
        }
    }

    void clear() {
        for (const auto& value : *this) {
            history.emplace_back(ERASE, value);
        }
        base_t::clear();
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    struct Query {
        int k, al, ar, bl, br;
    };
    vector<Query> updates(N);
    for (auto& [k, al, ar, bl, br] : updates) {
        cin >> k >> al >> bl >> ar >> br;
    }

    multiset_rollback<pair<int, int>> ifkleft, ifkright;
    ifkleft.insert({0, -1}), ifkright.insert({0, -1});
    vector<array<int, 2>> times(N);

    for (int last = 0, i = 0; i < N; last = updates[i++].k) {
        auto [k, al, ar, bl, br] = updates[i];
        bool pre_L_empty = ifkleft.empty();
        bool pre_R_empty = ifkright.empty();

        if (ordered(al, k, bl)) {
            if (!pre_R_empty && ordered(ar, last, br)) {
                ifkleft.insert({last, i - 1});
            }
            while (!ifkleft.empty() && ifkleft.begin()->first < ar) {
                ifkleft.erase(*ifkleft.begin());
            }
            while (!ifkleft.empty() && ifkleft.rbegin()->first > br) {
                ifkleft.erase(*ifkleft.rbegin());
            }
        } else {
            ifkleft.clear();
        }
        if (ordered(ar, k, br)) {
            if (!pre_L_empty && ordered(al, last, bl)) {
                ifkright.insert({last, i - 1});
            }
            while (!ifkright.empty() && ifkright.begin()->first < al) {
                ifkright.erase(*ifkright.begin());
            }
            while (!ifkright.empty() && ifkright.rbegin()->first > bl) {
                ifkright.erase(*ifkright.rbegin());
            }
        } else {
            ifkright.clear();
        }

        if (ifkleft.empty() && ifkright.empty()) {
            cout << "No\n";
            return 0;
        }

        times[i] = {ifkleft.time(), ifkright.time()};
    }

    vector<int> side(N, -1);
    int cur = ifkleft.empty() ? 1 : 0;
    int i = N - 1;

    while (i >= 0) {
        ifkleft.rollback(times[i][0]);
        ifkright.rollback(times[i][1]);
        debug(i, ifkleft, ifkright);
        if (cur == 0) {
            assert(!ifkleft.empty());
            int j = ifkleft.begin()->second;
            while (i > j) {
                side[i--] = 0;
            }
        } else {
            assert(!ifkright.empty());
            int j = ifkright.begin()->second;
            while (i > j) {
                side[i--] = 1;
            }
        }
        cur = !cur;
    }

    cout << "Yes\n";
    for (int j = 0; j < N; j++) {
        cout << side[j] << " \n"[j + 1 == N];
    }

    return 0;
}