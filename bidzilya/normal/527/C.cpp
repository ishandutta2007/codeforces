#include <bits/stdc++.h>
using namespace std;

void Update(set<int>& s, multiset<int>& mx, int x)
{
    set<int>::iterator itr = s.insert(x).first;
    set<int>::iterator lf = itr, rg = itr;
    --lf;
    ++rg;
    mx.erase(mx.find((*rg) - (*lf)));
    mx.insert((*rg) - x);
    mx.insert(x - (*lf));
}

int main()
{
    ios_base::sync_with_stdio(false);

    int w, h, n;
    cin >> w >> h >> n;

    set<int> V, H;
    V.insert(0);
    V.insert(w);
    H.insert(0);
    H.insert(h);
    multiset<int> mxV, mxH;
    mxV.insert(w);
    mxH.insert(h);

    for (int i = 0; i < n; ++i) {
        char tp;
        cin >> tp;
        int x;
        cin >> x;
        if (tp == 'H') {
            Update(H, mxH, x);
        } else {
            Update(V, mxV, x);
        }
        cout << 1LL * (*mxV.rbegin()) * (*mxH.rbegin()) << endl;
    }


    return 0;
}