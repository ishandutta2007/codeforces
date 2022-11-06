//https://codeforces.com/contest/1056/problem/G
#include <iostream>
#include <fstream>
#include <iomanip>
#include <bits/stdc++.h>
#include <chrono>
#include <random>
#include<ext/rope>

using __gnu_cxx::rope;
using std::cerr;
using std::deque;
using std::endl;
using std::fill;
using std::ios_base;
using std::istream;
using std::iterator;
using std::make_pair;
using std::map;
using std::max;
using std::min;
using std::numeric_limits;
using std::ostream;
using std::pair;
using std::priority_queue;
using std::set;
using std::sort;
using std::string;
using std::swap;
using std::unordered_map;
using std::vector;
using std::bitset;

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}

namespace dalt
{
};
namespace other
{
};

using namespace dalt;

#define MOD(x, m) ((x) % (m) + (m)) % (m);

int n;

vector<int> mul(const vector<int> &a, const vector<int> &b){
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        ans[i] = a[b[i]];
    }
    return ans;
}

vector<int> power(const vector<int> &x, ll exp)
{
    if(exp == 0){
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = i;
        }
        return ans;
    }

    vector<int> ans = power(x, exp / 2);
    ans = mul(ans, ans);
    if(exp % 2 == 1){
        ans = mul(ans, x);
    }
    return ans;
}

void debug(rope<int> *ptr)
{
    for(int i = 0; i < n; i++){
        cerr << (*ptr)[i] << ",";
    }
    cerr << endl;
}

void solve(istream &in, ostream &out)
{
    int m;
    int s;
    ll t;
    in >> n >> m >> s >> t;
    s--;
    while(t % n != 0){
        if(s < m){
            s = MOD(s + t, n);
        }else{
            s = MOD(s - t, n);
        }
        t--;
    }

    vector<rope<int> *> dp(n + 1);
    dp[0] = new rope<int>();
    for(int i = 0; i < n; i++){
        dp[0]->push_back(i);
    }

    //debug(dp[0]);
    for(int i = 1; i <= n; i++){
        dp[i] = new rope<int>();
        {
            int l = MOD(0 + i, n);
            int r = MOD(m - 1 + i, n);
            if(l <= r){
                *dp[i] += dp[i - 1]->substr(l, r - l + 1);
            }
            else{
                *dp[i] += dp[i - 1]->substr(l, n - 1 - l + 1);
                *dp[i] += dp[i - 1]->substr(0, r - 0 + 1);
            }
        }
        {
            int l = MOD(m - i, n);
            int r = MOD(n - 1 - i, n);
            if(l <= r){
                *dp[i] += dp[i - 1]->substr(l, r - l + 1);
            }
            else{
                *dp[i] += dp[i - 1]->substr(l, n - 1 - l + 1);
                *dp[i] += dp[i - 1]->substr(0, r - 0 + 1);
            }
        }
       // debug(dp[i]);
    }

    vector<int> x(n);
    for(int i = 0; i < n; i++){
        x[i] = (*dp[n])[i];
    }
    
    vector<int> ans = power(x, t / n);
    int index = ans[s] + 1;
    out << index << endl;
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout << std::setiosflags(std::ios::fixed);
    std::cout << std::setprecision(15);

    solve(std::cin, std::cout);

    return 0;
}