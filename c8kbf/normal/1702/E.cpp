//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
#include <iostream>

#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <deque>
#include <string>
#include <queue>
#include <stack>
#include <bitset>

#include <algorithm>
#include <math.h>
#include <time.h>
#include <random>

using namespace std;

using ll = long long; 
using pii = pair<int, int>; 
using pll = pair<ll, ll>; 
using pli = pair<ll, int>; 
using vi = vector<int>;
using vll = vector<ll>; 
using vpii = vector<pair<int, int>>; 
using vpll = vector<pair<ll, ll>>;

#define v1(x) vector<x>
#define v2(x) vector<vector<x>>
#define v3(x) vector<vector<vector<x>>>

#define pb push_back
#define fi first
#define se second

#define FOR(i, x, y) for(int i = x; i < y; i++)
#define F0R(i, x) for(int i = 0; i < x; i++)

const int BIG32 = 1000000000;
const ll BIG64 = 1000000000000000000;
const int MAX32 = 2147483647;
const ll MAX64 = 9223372036854775807; 

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline vi rv() {
    vi res;
    int t; cin >> t;
    for(; t--; ) {
        int a; cin >> a; res.push_back(a);
    } return res;
}

inline void NOW(); 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    
    bool GEISHBAY = false;
    string filename = "haircut";
    //GEISHBAY = true; 
    if(GEISHBAY == true) {
        freopen((filename+".in").c_str(), "r", stdin);
        freopen((filename+".out").c_str(), "w", stdout);
    }

    bool YABHSIEG = false;
    YABHSIEG = true;
    if(YABHSIEG == true) {
        int AHCNG; cin >> AHCNG; 
        for(; AHCNG--;) {
            NOW();
        }
    } else {
        NOW();
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool visited[200005];
vi nums[200005];
inline void NOW() {
    int n; cin >> n;
    vpii arr;
    bool ok = false;
    for(int i = 0; i <= n+1; ++i) nums[i].clear();
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b; arr.pb({a, b});
        if(a == b) {ok = true; } 
        nums[a].pb(b); nums[b].pb(a);
    }
    if(ok == true) {cout << "NO" << endl; return; }

    for(int i = 1; i <= n; i++) {
        if(nums[i].size() > 2) {
            cout << "NO" << endl; return;
        }
    }

     for(int i = 0; i <= n+1; i++) visited[i] = false;
    for(int i = 1; i <= n; i++) {
        if(visited[i] == true) continue;
        int cnt = 0;
        stack<int> s;
        s.push(i); 
        while(!s.empty()) {
            int curr = s.top(); s.pop(); cnt++;
            visited[curr] = true;
            for(auto next : nums[curr]) {
                if(!visited[next]) {
                    s.push(next);
                }
            }
        }
        if(cnt % 2 == 0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;

}