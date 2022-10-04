#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int n, x, xr, ad, r;
vector<pair<char, int> > p;

int get(int s) {
    for (int i = 0; i < n; ++i) {
        if (p[i].first == '^')
            s ^= p[i].second;
        if (p[i].first == '&')
            s &= p[i].second;
        if (p[i].first == '|')
            s |= p[i].second;
    }
    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c >> x;
        p.push_back({c, x});
    }
    int c1 = get(0), c2 = get(1023);
    ad = 1023;
    for (int i = 0; i < 10; ++i) {
        int bit1 = ((c1 >> i) & 1), bit2 = ((c2 >> i) & 1);
        if ((bit1 == 1) && (bit2 == 1))
            r ^= (1 << i);
        if ((bit1 == 0) && (bit2 == 0))
            ad ^= (1 << i);
        if ((bit1 == 1) && (bit2 == 0))
            xr ^= (1 << i);
    }
    cout << 3 << endl;
    cout << "& " << ad << endl;
    cout << "| " << r << endl;
    cout << "^ " << xr << endl;
    return 0;
}