#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define TASK ""
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define for1(i, n) for (int i = 1; i <= (int)n; i++)
#define forq(i, s, t) for (int i = s; i <= (int)t; i++)
#define ford(i, s, t) for (int i = s; i >= (int)t; i--)
#define mk make_pair
#define pk push_back
#define all(v) v.begin(), v.end()
#define TIME clock() * 1.0 / CLOCKS_PER_SEC

const int DEBUG = 0;
const double EPS = 1e-15;
const double PI = acos(-1.0);
const int MAXN = (int)2e5 + 7;
const int INF = (int)1e9 + 7;
const ll LINF = (ll)2e18 + 7;
const int MOD = (int)1e9 + 7;
const ull P = 239017;
const ull MM = (ull)2147482661;

int solve();

int main()
{
    if (DEBUG){
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
	solve();
	return 0;
}

int n, k, q;
set<pii> st;
int t[MAXN], on[MAXN];

int check(int id){
    if (!on[id]) return 0;
    int cur = 1;
    for (auto it = st.rbegin(); it != st.rend(); it++){
        //cout << id << ' ' << it->first << ' ' << it->second << '\n';
        if (cur > k) return 0;
        if (it->second == id) return 1;
        cur++;
    }
    return 0;
}

int solve()
{
    scanf("%d%d%d", &n, &k, &q);
    for1(i, n){
        scanf("%d", t + i);
    }
    while(q--){
        int type, id;
        scanf("%d%d", &type, &id);
        //cout << type << ' '<< id << '\n';
        if (type == 2){
            int ok = check(id);
            printf(ok ? "YES\n" : "NO\n");
        }
        else{
            st.insert(mk(t[id], id));
            on[id] = 1;
        }
    }
	return 0;
}