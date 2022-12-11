#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

bool pcmp(pair<int, int> a, pair<int, int> b)
{
    if ((a.second - a.first) != (b.second - b.first))
        return ((a.second - a.first) < (b.second - b.first));
    else
        return a < b;
}

int main()
{
    int n, i;
    cin >> n;
//    vector<int> x(n), y(n);
    vector<pair<int, int> > pnt(n), srt(n), ans(n);
    vector<int> pos(n, -1);
    for (i = 0; i < n; i++)
    {
        cin >> pnt[i].first;
        cin >> pnt[i].second;
    }
    sort(pnt.begin(), pnt.end(), pcmp);
//    for (i = 0; i < n; i++)
//    {
//        cout << pnt[i].first << ' ';
//        cout << pnt[i].second << endl;
//    }
    for (i = 0; i < n; i++)
    {
        cin >> srt[i].first;
        srt[i].second = i;
    }
    sort(srt.begin(), srt.end());
    vector<tuple<int, int, int> > fpos(n);
    for (i = 0; i < n; i++)
    {
        if (srt[i].first != (pnt[i].second - pnt[i].first)) {cout << "NO\n"; return 0;}
        fpos[i] = make_tuple(pnt[i].first, pnt[i].second, srt[i].second);
    }
    sort(fpos.begin(), fpos.end());
    int lx, ly, ms, x, y, v;
    tie(lx, ly, ms) = fpos[0];
    pos[0] = ms;
    ans[ms] = {lx, ly};
    for (i = 1; i < n; i++)
    {
        tie(x, y, v) = fpos[i];
        if (x > lx)
            ms = -1;
        if (ms > v || pos[y] > v) {cout << "NO\n"; return 0;}
        pos[y] = max(pos[y], v);
        ms = max(ms, pos[y]);
        ans[v] = {x, y};
    }
    cout << "YES\n";
    for (i = 0; i < n; i++)
    {
        cout << ans[i].first << ' ' << ans[i].second << endl;
    }
    return 0;
}