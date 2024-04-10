#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
// #include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
// #include <cuchar>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
// #include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#if __cplusplus >= 201402L
#include <shared_mutex>
#endif

#if __cplusplus >= 201703L
#include <any>
#include <charconv>
// #include <execution>
#include <filesystem>
#include <optional>
// #include <memory_resource>
#include <string_view>
#include <variant>
#endif

#if __cplusplus > 201703L
#include <barrier>
#include <bit>
#include <compare>
#include <concepts>
#if __cpp_impl_coroutine
# include <coroutine>
#endif
#include <latch>
#include <numbers>
#include <ranges>
#include <span>
#include <stop_token>
#include <semaphore>
#include <source_location>
#include <syncstream>
#include <version>
#endif

using namespace std;

using ll = long long;
using db = long double;
using str = string;
using pi = pair<int, int>;
#define mp make_pair
#define f first
#define s second

#define tcT template<class T
tcT> using V = vector<T>;
tcT, size_t SZ> using AR = array<T, SZ>;
using vi = V<int>;
using vb = V<bool>;
using vpi = V<pi>;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsz resize
#define pb push_back
#define ft front()
#define bk back()

const int MOD = 1e9+7;
const ll BIG = 1e18;
const db PI = acos((db)-1);
mt19937 rng(0);

tcT> bool ckmin(T& a, const T& b){
    return b < a ? a = b, 1 : 0;
}
tcT> bool ckmax(T& a, const T& b){
    return a < b ? a = b, 1 : 0;
}

const int mx = 100005;
ll A[mx];
ll csum[mx];



int bt[mx];

void upd(int pos, int val){
    for(int i = pos; i < mx; i+=i&-i){
        bt[i]+=val;
    }
}

int sum(int pos){
    int res = 0;
    for(int i = pos; i > 0; i-=i&-i){
        res+=bt[i];
    }
    return res;
}

int query(int L, int R){
    return sum(R)-sum(L-1);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }
    for(int i = 1; i <= N; i++){
        csum[i] = csum[i-1]+A[i];
    }

    bool exists_neg = 0;
    for(int i = 0; i <= N; i++){
        if(csum[i] < 0) exists_neg = true;
    }
    if(exists_neg){
        cout << -1 << "\n";
        exit(0);
    }

    bool last_max = true;
    for(int i = 1; i <= N; i++){
        if(csum[N] < csum[i]){
            last_max = false;
        }
    }
    if(!last_max){
        cout << -1 << "\n";
        exit(0);
    }

    map<ll, int> compress;
    for(int i = 1; i <= N-1; i++){
        compress[csum[i]];
    }
    int cur_compress = 0;
    for(auto& u: compress){
        cur_compress++;
        u.s = cur_compress;
    }
    ll ans = 0;
    for(int i = 1; i <= N-1; i++){
        int val = compress[csum[i]];
        // cout << i << " " << val << "\n";
        ans+=query(val+1, N);
        upd(val, +1);
    }
    cout << ans << "\n";



}