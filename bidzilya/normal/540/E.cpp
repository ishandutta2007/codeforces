#include <bits/stdc++.h>
using namespace std;

const int kMaxA = 1e9;

long long GetAmountOfInversions(vector<int>& a, int l, int r)
{
    if (l == r) {
        return 0;
    }
    int m = (l + r) >> 1;
    long long ans = GetAmountOfInversions(a, l, m) +
                    GetAmountOfInversions(a, m + 1, r);
    vector<int> temp;
    temp.reserve(r - l + 1);
    for (int i1 = l, i2 = m + 1; i1 <= m || i2 <= r; ) {
        if (i1 <= m && i2 <= r) {
            if (a[i1] < a[i2]) {
                temp.push_back(a[i1]);
                ++i1;
            } else {
                temp.push_back(a[i2]);
                ++i2;
                ans += (m - i1 + 1);
            }
        } else if (i1 <= m) {
            temp.push_back(a[i1]);
            ++i1;
        } else {
            temp.push_back(a[i2]);
            ++i2;
        }
    }
    for (int i = l; i <= r; ++i) {
        a[i] = temp[i - l];
    }
    return ans;
}

long long GetAmountOfInversions(vector<int> a)
{
    return GetAmountOfInversions(a, 0, a.size() - 1);
}

void SortAndRemainUnique(vector<int>& a)
{
    if (a.empty()) {
        return;
    }
    sort(a.begin(), a.end());
    int c = 1;
    for (int i = 1; i < (int) a.size(); ++i) {
        if (a[i] != a[c - 1]) {
            a[c] = a[i];
            ++c;
        } 
    }
    a.resize(c);
}

struct SegmentTree
{
    SegmentTree* lf;
    SegmentTree* rg;
    int val;
    
    SegmentTree() :
        lf(nullptr),
        rg(nullptr),
        val(0)
    {
    }
};

void Check(SegmentTree* t)
{
    if (t->lf == nullptr) {
        t->lf = new SegmentTree();
    }
    if (t->rg == nullptr) {
        t->rg = new SegmentTree();
    }
}

int Get(SegmentTree* t, int tl, int tr, int l, int r)
{
    if (tl == l && tr == r) {
        return t->val;
    } else {
        int tm = (tl + tr) >> 1;
        Check(t);
        if (r <= tm) {
            return Get(t->lf, tl, tm, l, r);
        } else if (l > tm) {
            return Get(t->rg, tm + 1, tr, l, r);
        } else {
            return Get(t->lf, tl, tm, l, tm) +
                   Get(t->rg, tm + 1, tr, tm + 1, r); 
        }
    }
}

void Set(SegmentTree* t, int tl, int tr, int pos)
{
    if (tl == tr) {
        t->val = 1;
    } else {
        int tm = (tl + tr) >> 1;
        Check(t);
        if (pos <= tm) {
            Set(t->lf, tl, tm, pos);
        } else {
            Set(t->rg, tm + 1, tr, pos);
        }
        t->val = t->lf->val + t->rg->val;
    }
}

long long GetAmountOfOccurrences(vector<pair<int, int> > qs, const vector<int>& poss)
{
    SegmentTree* st = new SegmentTree();
    for (auto x: poss) {
        Set(st, 0, kMaxA - 1, x);
    }
    long long ans = 0;
    for (auto x: qs) {
        ans += Get(st, 0, kMaxA - 1, x.first, x.second);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> poss;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        --a[i];
        --b[i];
        poss.push_back(a[i]);
        poss.push_back(b[i]);
    }
    SortAndRemainUnique(poss);
    map<int, int> mp;
    for (int i = 0; i < (int) poss.size(); ++i) {
        mp[poss[i]] = i;
    }
    int m = poss.size();
    vector<int> vals(m);
    for (int i = 0; i < m; ++i) {
        vals[i] = poss[i];
    }
    for (int i = 0; i < n; ++i) {
        int ca = mp[a[i]];
        int cb = mp[b[i]];
        swap(vals[ca], vals[cb]);
    }
    vector<pair<int, int> > qs;
    long long ans = GetAmountOfInversions(vals);
    for (int i = 0; i < (int) vals.size(); ++i) {
        int x = vals[i];
        int p = poss[i];
        int cl = 0;
        int cr = p - 1;
        if (cl <= cr) {
            cl = max(cl, x + 1);
            if (cl <= cr) {
                ans += (cr - cl + 1);
                qs.push_back(make_pair(cl, cr));
            }
        }
        cl = p + 1;
        cr = kMaxA - 1;
        if (cl <= cr) {
            cr = min(cr, x - 1);
            if (cl <= cr) {
                ans += (cr - cl + 1);
                qs.push_back(make_pair(cl, cr));
            }
        }
    }
    ans -= GetAmountOfOccurrences(qs, poss);
    cout << ans << endl;

    return 0;
}