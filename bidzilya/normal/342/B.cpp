#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    int s, f;
    cin >> n >> m >> s >> f;
    --s;
    --f;
    
    int dx;
    char cdx;
    if (s < f) {
        dx = +1;
        cdx = 'R';
    } else {
        dx = -1;
        cdx = 'L';
    }
    
    vector<int> t(m), l(m), r(m);
    for (int i = 0; i < m; ++i) {
        cin >> t[i] >> l[i] >> r[i];
        --l[i];
        --r[i];
    }
    
    string ans;
    for (int cur = 1, ptr = 0; s != f;) {
        if (ptr < m && cur == t[ptr]) {
            if ((s >= l[ptr] && s <= r[ptr]) || 
                    (s + dx >= l[ptr] && s + dx <= r[ptr])) {
                ans.push_back('X');
            } else {
                s += dx;
                ans.push_back(cdx);
            }
            ++ptr;
        } else {
            s += dx;
            ans.push_back(cdx);
        }
        ++cur;
    }
    
    cout << ans << endl;
    
    return 0;
}