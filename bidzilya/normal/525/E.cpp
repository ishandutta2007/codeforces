#include <bits/stdc++.h>
using namespace std;

const int kMaxFact = 19;

vector<long long> fact(kMaxFact);
int n, k;
long long S;
vector<int> a;

void Calc(int v, const vector<int>& a, int n,
          vector<map<long long, long long> >& res,
          int cur_k, long long cur_S)
{
    if (v == n) {
        ++res[cur_k][cur_S];
    } else {
        if (a[v] < kMaxFact) {
            Calc(v + 1, a, n, res, cur_k + 1, cur_S + fact[a[v]]);
        }
        Calc(v + 1, a, n, res, cur_k, cur_S + a[v]);
        Calc(v + 1, a, n, res, cur_k, cur_S);
    }
}

vector<map<long long, long long> > Solve(const vector<int>& a)
{
    vector<map<long long, long long> > res(a.size() + 1);
    Calc(0, a, a.size(), res, 0, 0);
    return res;
}

long long Solve()
{
    vector<int> l, r;
    for (int i = 0; i < n; i += 2) {
        l.push_back(a[i]);
        if (i + 1 < n) {
            r.push_back(a[i + 1]);
        }
    }
    vector<map<long long, long long> > h1, h2;
    h1 = Solve(l);
    h2 = Solve(r);
    long long ans = 0;
    for (int k1 = 0; k1 <= (int) l.size() && k1 <= k; ++k1) {
        for (int k2 = 0; k2 + k1 <= k && k2 <= (int) r.size(); ++k2) {
            for (map<long long, long long>::iterator itr = h1[k1].begin(); itr != h1[k1].end(); ++itr) {
                ans += (1LL * (*itr).second * h2[k2][S - (*itr).first]);
            }
        }
    }
    return ans;
}

int main()
{
    /*
    freopen("input.txt", "w", stdout);
    cout << 25 << " " << 25 << " " << 100 << endl;
    for (int i = 0; i < 25; ++i) {
        cout << 1 << " ";
    }
    cout << endl;
    return 0;
    */
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i < kMaxFact; ++i) {
        fact[i] = fact[i - 1] * i;
    }

    cin >> n >> k >> S;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << Solve() << endl;

    return 0;
}