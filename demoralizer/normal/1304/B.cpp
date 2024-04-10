// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#ifdef on_linux
#include <sys/resource.h>
#endif

using namespace std;
using namespace __gnu_pbds;

#ifdef dobby_is_a_free_elf
#define TRACE
#endif
#ifdef TRACE
    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1) {
        cout << name << " : " << arg1 << std::endl;
        //use cerr if u want to display at the bottom
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args) {
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
    }
#else
    #define trace(...) 0;
#endif

template<typename T1, typename T2> std::istream& operator>>(std::istream& in, pair<T1, T2> &a) {
    in >> a.first >> a.second;
    return in;
}
template<typename T1, typename T2> std::ostream& operator<<(std::ostream& out, pair<T1, T2> &a) {
    out << a.first << " " << a.second;
    return out;
}

template<typename T, typename U> static inline void amin(T &x, U y) {
    if (y < x)
        x = y;
}
template<typename T, typename U> static inline void amax(T &x, U y) {
    if (x < y)
        x = y;
}

template <typename T> T allmin(T t) {return t;}
template<typename T, typename... Args> T allmin(T t, Args... args) {return min(t, allmin(args...));}

template <typename T> T allmax(T t) {return t;}
template<typename T, typename... Args> T allmax(T t, Args... args) {return max(t, allmax(args...));}

#define min allmin
#define max allmax

#define all(x)                  (x).begin(), (x).end()
#define chrng(i,x,y)            (i >= x && i <= y)
#define fi                      first
#define GCD(x,y)                (__gcd((x), (y)))
#define int                     long long
#define lbd                     lower_bound
#define LCM(x,y)                (((x)/__gcd((x), (y)))*(y)) 
#define mem0(x)                 memset(x, 0, sizeof (x))
#define mem1(x)                 memset(x, -1, sizeof (x))
#define mp                      make_pair
#define pb                      push_back
#define pf                      push_front
#define pob                     pop_back
#define pof                     pop_front
#define rep(i,begin,end)        for(__typeof(end) i=(begin)-((begin)>(end));i!=(end)-((begin)>(end));i+=1-2*((begin)>(end)))
#define sc                      second
#define sleep(x)                std::this_thread::sleep_for(std::chrono::milliseconds(x))
#define sz(x)                   (int)((x).size())
#define ubd                     upper_bound

struct ConfigIO {
    ConfigIO() {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios_base::sync_with_stdio(false);   // using both C and C++ streams will now mix up the outputs (also inputs)
    }
} cnf_io;

// struct config_rand {
//    config_rand() {
//        srand(chrono::duration_cast<chrono::nanoseconds>(
//                chrono::high_resolution_clock::now().time_since_epoch()).count());
//    }
// } cnf_rand;

// int GetRand() {
//     static mt19937_64 gen(chrono::duration_cast<chrono::nanoseconds>(
//                               chrono::high_resolution_clock::now().time_since_epoch()).count());
//     static uniform_int_distribution<int> dis;
//     return dis(gen);
// }

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
// erase,insert same as normal set

template <typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;

inline long long toint(const string &s) {stringstream ss; ss << s; long long x; ss >> x; return x;}
inline string tostring(long long number) {stringstream ss; ss << number; return ss.str();}
inline string tobin(long long x) {return bitset<63>(x).to_string();}

// __builtin_popcount(x) - Returns the number of 1-bits in x.
// __builtin_parity(x) - Returns the parity of x, i.e. the number of 1-bits in x
// modulo 2.
// __builtin_ffs(x) - Returns one plus the index of the least significant 1-bit
// of x, or if x is zero, returns zero.
// __builtin_clz(x) - Returns the number of leading 0-bits in x, starting at the
// most significant bit position. If x is 0, the result is undefined.
// __builtin_ctz(x) - Returns the number of trailing 0-bits in x, starting at
// the least significant bit position. If x is 0, the result is undefined.

// str.substr(pos, len) - The substring that starts at character position pos and 
// spans len characters (or until the end of the string, whichever comes first)

// str.c_str() - Returns a pointer to an array that contains
// a null-terminated sequence of characters (i.e., a C-string)

// size_t pos = str.find(s) - The position of the first character of the first match.
// If no matches were found, the function returns string::npos.

// primes for hashing 937,991,1013,1409,1741
// or use hash<string> hasher; hasher("qwerty");
// or hash<string>{}("qwerty");

/*----------------------Graph Moves----------------------*/
// const int fx[]={+1, -1, +0, +0};
// const int fy[]={+0, +0, +1, -1};
// const int fx[]={+0, +0, +1, -1, -1, +1, -1, +1};  // Kings Move
// const int fy[]={-1, +1, +0, +0, +1, +1, -1, -1};  // Kings Move
// const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
// const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1};  // Knights Move
/*-------------------------------------------------------*/

const long long INF = 1e18;
const long long MOD = 1e9 + 7;
const long long fftmod = 998244353;
const long double PI = 3.14159265358979323846264338;
const long double eps = 1e-12;
const int N = 1e6 + 10;

// big mod and primitive root for NTT:
// #define MOD 2305843009255636993          // a bit larger than 2^61
// #define RT 5

map<string,int> z;

inline void precompute()
{
    
    return;
}

inline void dobbysolver(int testcase)
{
    int n,m;
    cin>>n>>m;
    string pr;
    for (int i = 0; i < n; ++i)
    {
        string s,t;
        cin>>s;
        t=s;
        reverse(all(t));
        if(z.count(t)){
            z[t]++;
        }
        else{
            z[s]=0;
        }
    }
    int b=0,c=0;
    string k;
    for(pair<string, int> x:z){
        if(x.sc)pr+=x.fi;
        else if(k==""){
            k=x.fi;
            string q=k;
            reverse(all(q));
            if(k!=q)k="";
        }
    }
    pr+=k;
    for(auto it=z.rbegin();it!=z.rend();it++){
        if(it->sc){
            k=it->fi;
            reverse(all(k));
            pr+=k;
        }
    }

    cout<<sz(pr)<<"\n"<<pr;
    return;
}

int32_t main() {
#ifdef on_linux
    rlimit cpu_time {.rlim_cur = 2, .rlim_max = RLIM_INFINITY};
    setrlimit(RLIMIT_CPU, &cpu_time);
    /*
    struct rlimit {
        rlim_t rlim_cur;  // Soft limit
        rlim_t rlim_max;  // Hard limit (ceiling for rlim_cur)
    };
    */
#endif
    precompute();
    int TESTS = 1;
    //cin >> TESTS;
    for (int i = 1; i <= TESTS; ++i) {dobbysolver(i); if (i != TESTS) cout << '\n';}
    return 0;
}