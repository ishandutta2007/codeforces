#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n; n *= 2;
    string a, b; cin >> a >> b;

    vector<tuple<int, int, int>> score(n);
    for (int i = 0; i < n; ++i) {
        score[i] = make_tuple((int)(a[i]) + (int)(b[i]), a[i], b[i]);
    }

    sort(score.rbegin(), score.rend());
    int fst = 0, snd = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) fst += get<1>(score[i]);
        else snd += get<2>(score[i]);
    }

    if (fst < snd) cout << "Second" << endl;
    else if (fst > snd) cout << "First" << endl;
    else cout << "Draw" << endl;

    return 0;
}