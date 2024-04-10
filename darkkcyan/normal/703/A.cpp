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

int n, a, b;
int x, y;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int i, f, g;

    cin >> n;
    x = y = 0;
    f0(i, 0, n) {
        cin >> a >> b;
        if (a > b) ++x;
        if (b > a) ++y;
    }

    if (x > y) cout << "Mishka";
    else if (x < y) cout << "Chris";
    else cout <<  "Friendship is magic!^^";

    return 0;
}