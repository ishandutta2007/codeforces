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

#define maxn ((long) 1e5 + 5)
int n, inp[maxn], k, cap[maxn];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int i, f, g;

    cin >> n >> k;
    long sum = 0;
    f1 (i, 1, n) {
        cin >> inp[i];
        sum += inp[i];
    }

    long ans = inp[n] * inp[1];
    f1(i, 1, n - 1) {
        ans += inp[i] * inp[i + 1];
    }
    inp[0] = inp[n];
    inp[n + 1] = inp[1];

    clog << ans << endl;

    f1 (i, 1, k) {
        cin >> cap[i];
        ans += inp[cap[i]] * (sum - inp[cap[i]] - inp[cap[i] + 1] - inp[cap[i] - 1]);
        sum -= inp[cap[i]];
        inp[cap[i]] = 0;
        if (cap[i] == 1) inp[n + 1] = 0;
        if (cap[i] == n) inp[0] = 0;
        clog << ans << ' ' << sum << endl;
    }


    cout << ans;


    return 0;
}