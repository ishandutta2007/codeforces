#include <bits/stdc++.h>

using namespace std;

#ifdef db 
#define de(msg) cerr << "line " << __LINE__ << " => " << msg << '\n'
#else
#define de(msg)
#define at operator[]
#endif

#define dev(var) de(#var << ' ' << var)
#define _ << ' ' <<

#define fi first
#define se second
#define mp make_pair
#define ll long long 
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front

#define pii pair<int, int>
#define pilll pair<int, ll>
#define pllll pair<ll, ll>

#define ve vector
#define vi ve<int>
#define vll ve<ll>

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ap(a, b, p) {a = (p).fi; b = (p).se;}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int i, f, k;  // count variable
    
    int n;
    string s;

    cin >> n >> ws >> s;

    if (n > ('z' - 'a' + 1)) return (cout << -1), 0;
    
    int ar['z' + 1] = {0};
    for (i = 0; i < n; ++i) {
        ++ar[s[i]];
    }

    int ans = 0;
    for (i = 'a'; i <= 'z'; ++i) {
        if (ar[i] == 0) continue;
        ans += ar[i] - 1;
    }

    cout << ans;

    return 0;
}