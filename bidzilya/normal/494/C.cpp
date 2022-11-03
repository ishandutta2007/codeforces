#include <bits/stdc++.h>
using namespace std;

struct Rec
{
    int l, r;
    double p;

    Rec()
    {
    }

    Rec(int l, int r, double p) :
        l(l),
        r(r),
        p(p)
    {
    }
};

istream& operator >> (istream& input_stream, Rec& rec)
{
    input_stream >> rec.l >> rec.r;
    --rec.l;
    --rec.r;
    input_stream >> rec.p;
    return input_stream;
}

int n, q;
vector<int> a;

vector<Rec> recs;

vector<vector<int> > g;

bool RecComparator(const Rec& lhs, const Rec& rhs)
{
    return lhs.l < rhs.l ||
           (lhs.l == rhs.l && lhs.r > rhs.r);
}

vector<int> mx;

void CalcMx(int v)
{
    for (int i = 0; i < (int) g[v].size(); ++i) {
        CalcMx(g[v][i]);
    }

    if (g[v].empty()) {
        for (int i = recs[v].l; i <= recs[v].r; ++i) {
            mx[v] = max(mx[v], a[i]);
        }
    } else {
        int first_id = g[v][0];
        for (int i = recs[v].l; i < recs[first_id].l; ++i) {
            mx[v] = max(mx[v], a[i]);
        }
        for (int i = 1; i < (int) g[v].size(); ++i) {
            int cur_id = g[v][i];
            int prev_id = g[v][i - 1];
            for (int j = recs[prev_id].r + 1; j < recs[cur_id].l; ++j) {
                mx[v] = max(mx[v], a[j]);
            }
        }
        for (int i = 0; i < (int) g[v].size(); ++i) {
            mx[v] = max(mx[v], mx[g[v][i]]);
        }
        int last_id = g[v].back();
        for (int i = recs[last_id].r + 1; i <= recs[v].r; ++i) {
            mx[v] = max(mx[v], a[i]);
        }
    }
}

const int kMax = 5001;

double pt[kMax][2 * kMax + 1];
double temp[2 * kMax + 1];

vector<bool> good;

int gl_mx;

void CalcPt(int v)
{
    if (mx[v] < gl_mx - q) {
        good[v] = true;
        return;
    }
    for (int i = 0; i < (int) g[v].size(); ++i) {
        CalcPt(g[v][i]);
    }
    for (int i = 0; i <= 2 * q; ++i) {
        temp[i] = 1.0;
    }
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int u = g[v][i];

        if (!good[u]) {
            for (int j = 0; j <= 2 * q; ++j) {
                temp[j] *= pt[u][j];
            }
        }
    }
    int j_min = q - (gl_mx - mx[v]);
    for (int j = 0; j < j_min; ++j) {
        pt[v][j] = 0.0;
    }
    for (int j = j_min; j <= 2 * q; ++j) {
        pt[v][j] = 0.0;

        if (mx[v] <= gl_mx + j - q) {
            pt[v][j] += temp[j] * (1.0 - recs[v].p);
        }
        if (1 + mx[v] <= gl_mx + j - q) {
            pt[v][j] += temp[j - 1] * recs[v].p;
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);

    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ++q;
    recs.resize(q);
    recs[0] = Rec(0, n - 1, 0.0);
    for (int i = 1; i < q; ++i) {
        cin >> recs[i];
    }

    sort(recs.begin(), recs.end(), RecComparator);

    g.resize(q);
    for (int i = 0; i < q; ++i) {
        int r = recs[i].l - 1;

        for (int j = i + 1; j < q; ++j) {
            if (recs[j].l > r && recs[j].r <= recs[i].r) {
                g[i].push_back(j);
                r = recs[j].r;
            }
        }
    }

    mx.assign(q, 0);
    CalcMx(0);
    gl_mx = mx[0];

    good.assign(q, false);
    CalcPt(0);

    double ans = 0.0;
    for (int i = 0; i <= q; ++i) {
        ans += (gl_mx + i) * (pt[0][q + i] - pt[0][q + i - 1]);
    }

    cout << fixed << setprecision(15);
    cout << ans << endl;

    return 0;
}