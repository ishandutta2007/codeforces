#define CODEFORCES_TESTCASES

#include <bits/stdc++.h>

using namespace std; 

using LL = long long;
using ULL = unsigned long long;

template<typename...> using _void_t = void;

#define BEGIN int main ()   { io_init();
#define END } 

#ifdef CODEFORCES_TESTCASES
    #define BEGIN void solve ()   {
    #define END }  int main ()   { io_init(); int T; cin >> T; while(T--) { solve(); } } 
#endif

void io_init ()   {
    #ifndef INTERACTIVE
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #endif
} 

#define min ___min_new
template<typename T1, typename T2>
inline constexpr common_type_t<T1, T2> min (const T1& x, const T2& y)   {
    if(x < y) {
        return x;
    }
    return y;
} 
template<typename T>
inline constexpr const T& min (const T& x, const T& y)   {
    if(x < y) {
        return x;
    }
    return y;
} 

template<typename T1, typename T2, typename ...Ts>
inline constexpr auto min (const T1& x1, const T2& x2, const Ts&... xs)   {
    return min(min(x1, x2), xs...);
} 

#define max ___max_new
template<typename T1, typename T2>
inline constexpr common_type_t<T1, T2> max (const T1& x, const T2& y)   {
    if(not(x < y)) {
        return x;
    }
    return y;
} 
template<typename T>
inline constexpr const T& max (const T& x, const T& y)   {
    if(not(x < y)) {
        return x;
    }
    return y;
} 

template<typename T1, typename T2, typename ...Ts>
inline constexpr auto max (const T1& x1, const T2& x2, const Ts&... xs)   {
    return max(max(x1, x2), xs...);
} 


BEGIN

int N;
cin >> N;
vector<int> A (N) ;
int sum = 0;
for (int& a : A)   {
    cin >> a;
    sum += a;
} 
if (sum == 0)   {
    cout << "NO\n";
    return;
} 
sort (A.begin(), A.end()) ;
if (sum > 0)   {
    reverse(A.begin(), A.end());
} 
cout <<  "YES\n" ;
for (auto a : A)   {
    cout << a << " ";
} 
cout <<  "\n" ;


END