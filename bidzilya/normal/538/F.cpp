#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
vector<pair<int, int> > b;
vector<int> ans;

struct FenwickTree
{
    vector<int> x;
    int n;
    
    void Init(int _n)
    {
        n = _n;
        x.assign(n, 0);
    }
    
    void Change(int pos, int d)
    {
        while (pos < n) {
            x[pos] += d;
            pos = (pos | (pos + 1));
        }
    }
    
    int Get(int pos)
    {
        if (pos >= n) {
            pos = n - 1;
        }
        int r = 0;
        while (pos >= 0) {
            r += x[pos];
            pos = (pos & (pos + 1)) - 1;
        }
        return r;
    }
    
    int Get(int l, int r)
    {
        if (l == 0) {
            return Get(r);
        } else {
            return Get(r) - Get(l - 1);
        }
    }
};

FenwickTree ft;

void UpdateAnswer(int pos)
{
    ++pos;
    // cout << "At pos = " << pos << endl;
    int next_pos = pos + 1;
    int k = 1;
    while (next_pos <= n && k < n) {
        // cout << " Try to get in (" << next_pos << ", " << next_pos + k - 1 << ")" << endl;
        ans[k - 1] += ft.Get(next_pos - 1, next_pos + k - 1 - 1);
        next_pos += (pos - 1);
        ++k;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i].first = a[i];
        b[i].second = i;
    }
    sort(b.begin(), b.end());
    
    ans.assign(n, 0);
    ft.Init(n);
    for (int i = 0; i < n; ++i) {
        ft.Change(i, +1);
    }
    for (int i = n - 1; i >= 0; ) {
        int j = i;
        while (j > 0 && b[j - 1].first == b[i].first) {
            --j;
        }
        for (int t = j; t <= i; ++t) {
            ft.Change(b[t].second, -1);
        }
        for (int t = j; t <= i; ++t) {
            UpdateAnswer(b[t].second);
        }
        i = j - 1;
    }
    
    for (int i = 0; i + 1 < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
  
 
    return 0;
}