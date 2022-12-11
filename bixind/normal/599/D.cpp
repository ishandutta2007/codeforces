#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main()
{
    long long x, i, j;
//    __int128_t a;
    cin >> x;
//    vector<long long> sq(1, 1), sq1;
    long long v = 1, nxt = 1, dx, dx1;
    long long vl;
    vector<pair<long long, long long> > ans;
    while (v <= x)
    {
        vl = (nxt * (nxt + 1)) / 2;
        dx = x - v;
        if (dx == 0)
        {
            ans.push_back(make_pair((long long) nxt, (long long) nxt));
        }
        else
        if (dx % vl == 0)
        {
            dx = dx / vl;
            ans.push_back(make_pair((long long) (nxt + dx), (long long) nxt));
            ans.push_back(make_pair((long long) (nxt), (long long) (nxt + dx)));
        }
        nxt++;
        v = v + nxt * nxt;
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto w : ans)
    {
        cout << w.first << ' ' << w.second << endl;
    }
    return 0;
}