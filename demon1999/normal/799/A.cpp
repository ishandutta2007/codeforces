#include <iostream>
#include <bits/stdc++.h>
 
 
using namespace std;
 
#define re return
#define mp make_pair
#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) int(a.size())
#define fi first
#define se second
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int ma = 6 * 1000000;

int n, t, k, d;

int get_int() {
    char c = getchar();
    int ans = 0 ;
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') {
        ans = 10 * ans + c - '0';
        c = getchar();
    }
    re ans;
}

 
int main() {
    iostream::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k >> t >> d;
    int tm1 = ((n + t - 1) / t) * k;
    int tm2 = tm1;
    for (int k1 = 1; k1 <= 1000; k1++) {
        tm2 = min(tm2, max(k1 * k, ((n + t - 1) / t - k1) * k + d));
    } 
    if (tm2 < tm1)
        cout << "YES\n";
    else
        cout << "NO\n";
    re 0;
}