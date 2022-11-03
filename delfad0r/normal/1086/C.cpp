#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cstring>
#include <cmath>
#include <complex>
#include <cstdio>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector> 
#include <tuple>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> II;
typedef pair<int, LL> ILL;
typedef pair<LL, int> LLI;
typedef pair<LL, LL> LLLL;

template<typename S, typename T>
ostream& operator << (ostream& out, const pair<S, T>& p) {
    return out << "{" << p.first << ", " << p.second << "}";
}

template<typename I>
class iter_type {
    public:
    const I b, e;
    iter_type(I b, I e) : b(b), e(e) { }
};

template<typename I>
iter_type<I> iter(I b, I e) {
    return iter_type<I>(b, e);
}

template<typename T>
auto iter(T& v) -> iter_type<decltype(begin(v))> {
    return iter_type<decltype(begin(v))>(begin(v), end(v));
}

template<typename I>
ostream& operator << (ostream& out, const iter_type<I>& x) {
    out << "[";
    for(I it = x.b; it != x.e; ++it) {
        out << *it;
        if(next(it) != x.e) {
            out << ", ";
        }
    }
    return out << "]";
}

template<typename I>
istream& operator >> (istream& in, const iter_type<I>& x) {
    for(I it = x.b; it != x.e; ++it) {
        in >> *it;
    }
    return in;
}

template<typename T>
ostream& operator << (ostream& out, const vector<T>& v) {
    return out << iter(v);
}
template<typename T>
istream& operator >> (istream& in, vector<T>& v) {
    return in >> iter(v);
}
template<typename T>
ostream& operator << (ostream& out, const set<T>& v) {
    return out << iter(v);
}
template<typename S, typename T>
ostream& operator << (ostream& out, const map<S, T>& v) {
    return out << iter(v);
}
template<typename T>
ostream& operator << (ostream& out, const unordered_set<T>& v) {
    return out << iter(v);
}
template<typename S, typename T>
ostream& operator << (ostream& out, const unordered_map<S, T>& v) {
    return out << iter(v);
}


//////////////////////
// HAPPY CODING  :) //
//////////////////////

int ans[300];
bool used[2300];
string a, b, s;
int K;

bool find_sol(int i = 0, bool freedom = false) {
    if(i == int(s.size())) {
        return true;
    }
    int& l = ans[s[i]];
    if(l != -1) {
        if(freedom) {
            return find_sol(i + 1, true);
        }
        if(l == a[i]) {
            return find_sol(i + 1, false);
        } else if(l < a[i]) {
            return false;
        } else {
            return find_sol(i + 1, true);
        }
    } else if(not freedom) {
        for(int u = a[i]; u < 'a' + K; ++u) {
            if(not used[u]) {
                used[u] = true;
                l = u;
                break;
            }
        }
        bool f;
        if(l == -1) {
            return false;
        } else if(l > a[i]) {
            f = find_sol(i + 1, true);
        } else {
            f = find_sol(i + 1, false);
        }
        if(f) {
            return true;
        }
        used[l] = false;
        for(int u = l + 1; u < 'a' + K; ++u) {
            if(not used[u]) {
                used[u] = true;
                l = u;
                return find_sol(i, true);
            }
        }
        l = -1;
        return false;
    } else {
        for(int u = 'a'; u < 'a' + K; ++u) {
            if(not used[u]) {
                used[u] = true;
                l = u;
                break;
            }
        }
        if(find_sol(i + 1, true)) {
            return true;
        }
        used[l] = false;
        l = -1;
        return false;
    }
}

void solve() {
    cin >> K >> s >> a >> b;
    memset(ans, -1, sizeof(ans));
    memset(used, 0, sizeof(used));
    find_sol();
    for(char& c : s) {
        c = ans[c];
    }
    //cerr << s << endl;
    if(s <= b) {
        cout << "YES\n";
        for(int i = 0; i < K; ++i) {
            if(ans[i + 'a'] == -1) {
                for(int u = 'a'; u < 'a' + K; ++u) {
                    if(not used[u]) {
                        used[u] = true;
                        ans[i + 'a'] = u;
                        break;
                    }
                }
            }
            cout << char(ans[i + 'a']);
        }
        cout << "\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // remove in interactive problems
    #ifdef DEBUG
    freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //
    
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    
    
    return 0;
}