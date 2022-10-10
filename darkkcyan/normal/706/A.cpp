#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#define cin fin
#define cout fout
ifstream cin("inp.txt");
ofstream cout("out.txt");
#endif

#define long long long
#define pii pair<int, int>
#define pll pair<long, long>

#define ve vector
#define vi ve<int>
#define vl ve<long>

#define sz(v) ((int) v.size())
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define first xx
#define second yy
#define mp make_pair
#define pb push_back

#define f0(i, a, b) for (i = a; i < b; ++i)
#define f1(i, a, b) for (i = a; i <= b; ++i)



int main() {
       ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    int n;
    cin >> a >> b >> n;

    float ans = 1000000000000;
    for (int i = 0; i < n; ++i) {
        int x, y, v;
        cin >> x >> y >> v;
        #define sqr(x) (x) * (x)
        long dis = sqr(x - a) + sqr(y - b);
        ans = min(ans, (float) sqrt(dis) / v);
    }
    cout << setprecision(7) << ans;
}