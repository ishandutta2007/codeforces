#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

inline namespace {

struct Hasher {
    template <typename Container>
    size_t operator()(const Container& vec) const noexcept {
        using std::hash;
        hash<typename Container::value_type> hasher;
        size_t seed = distance(begin(vec), end(vec));
        for (const auto& n : vec) {
            seed ^= hasher(n) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
    template <typename U, typename V>
    size_t operator()(const pair<U, V>& p) const noexcept {
        using std::hash;
        size_t a = hash<U>{}(p.first), b = hash<V>{}(p.second);
        return (a + b) * (a + b + 1) / 2 + b;
    }
    template <typename U>
    size_t operator()(const array<U, 2>& p) const noexcept {
        using std::hash;
        hash<U> hasher;
        size_t a = hasher(p[0]), b = hasher(p[1]);
        return (a + b) * (a + b + 1) / 2 + b;
    }
    template <int i, typename Tuple>
    size_t tuple_compute(const Tuple& tuple) const noexcept {
        if constexpr (i == std::tuple_size_v<Tuple>) {
            return std::tuple_size_v<Tuple>;
        } else {
            using std::hash;
            hash<std::tuple_element_t<i, Tuple>> hasher;
            size_t seed = tuple_compute<i + 1, Tuple>(tuple);
            size_t h = hasher(std::get<i>(tuple));
            return seed ^ (h + 0x9e3779b9 + (seed << 6) + (seed >> 2));
        }
    }
    template <typename... Ts>
    size_t operator()(const tuple<Ts...>& t) const noexcept {
        return tuple_compute<0, tuple<Ts...>>(t);
    }
};

} // namespace

namespace std {

template <typename T, size_t N>
struct hash<array<T, N>> : Hasher {};
template <typename T>
struct hash<vector<T>> : Hasher {};
template <typename U, typename V>
struct hash<pair<U, V>> : Hasher {};
template <typename... Ts>
struct hash<tuple<Ts...>> : Hasher {};

template <typename U, typename V>
string to_string(const pair<U, V>& uv) {
    return '(' + to_string(uv.first) + ',' + to_string(uv.second) + ')';
}
template <typename U, typename V>
ostream& operator<<(ostream& out, const pair<U, V>& v) {
    return out << to_string(v);
}

template <typename T>
string to_string(const array<T, 2>& uv) {
    return '(' + to_string(uv[0]) + ',' + to_string(uv[1]) + ')';
}
template <typename T, size_t N>
ostream& operator<<(ostream& out, const array<T, N>& v) {
    return out << to_string(v);
}

template <typename T, size_t N>
string to_string(const array<T, N>& v) {
    string s;
    for (const auto& el : v)
        s += to_string(el) + " ";
    return s.empty() ? s : (s.pop_back(), s);
}

template <typename T>
string to_string(const vector<T>& v) {
    string s;
    for (const auto& el : v)
        s += to_string(el) + " ";
    return s.empty() ? s : (s.pop_back(), s);
}
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
    return out << to_string(v);
}

template <typename T>
string to_string(const vector<vector<T>>& v) {
    string s;
    for (const auto& el : v)
        s += "[" + to_string(el) + "] ";
    return s.empty() ? s : (s.pop_back(), s);
}
template <typename T>
ostream& operator<<(ostream& out, const vector<vector<T>>& v) {
    return out << to_string(v);
}

template <typename T>
string to_string(const list<T>& v) {
    string s;
    for (const auto& el : v)
        s += to_string(el) + " ";
    return s.empty() ? s : (s.pop_back(), s);
}
template <typename T>
ostream& operator<<(ostream& out, const list<T>& v) {
    return out << to_string(v);
}

template <typename T>
string to_string(const set<T>& v) {
    string s;
    for (const auto& el : v)
        s += to_string(el) + " ";
    return s.empty() ? s : (s.pop_back(), s);
}
template <typename T>
ostream& operator<<(ostream& out, const set<T>& v) {
    return out << to_string(v);
}

template <typename T>
string to_string(const unordered_set<T>& v) {
    string s;
    for (const auto& el : v)
        s += to_string(el) + " ";
    return s.empty() ? s : (s.pop_back(), s);
}
template <typename T>
ostream& operator<<(ostream& out, const unordered_set<T>& v) {
    return out << to_string(v);
}

template <typename K, typename V>
string to_string(const map<K, V>& v) {
    string s;
    for (const auto& el : v)
        s += to_string(el) + " ";
    return s.empty() ? s : (s.pop_back(), s);
}
template <typename K, typename V>
ostream& operator<<(ostream& out, const map<K, V>& v) {
    return out << to_string(v);
}

template <typename K, typename V>
string to_string(const unordered_map<K, V>& v) {
    string s;
    for (const auto& el : v)
        s += to_string(el) + " ";
    return s.empty() ? s : (s.pop_back(), s);
}
template <typename K, typename V>
ostream& operator<<(ostream& out, const unordered_map<K, V>& v) {
    return out << to_string(v);
}

} // namespace std

auto solve() {
    int N, W;
    cin >> N >> W;
    vector<int> w(N);
    for (int i = 0; i < N; i++) {
        cin >> w[i];
    }
    int S = accumulate(begin(w), end(w), 0);
    if (S == W) {
        cout << "NO" << endl;
        return;
    }
    sort(begin(w), end(w));
    int k = 0;
    for (int i = 0; i + 1 < N; i++) {
        if (k + w[i] == W) {
            swap(w[i], w[i + 1]);
        }
        k += w[i];
    }
    cout << "YES\n" << w << endl;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        solve();
    }
    return 0;
}