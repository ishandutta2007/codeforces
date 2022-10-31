#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

typedef long long li;
typedef pair<int, int> pt;

template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p) {
    return out << "(" << p.x << ", " << p.y << ")";
}
template<class A> ostream& operator <<(ostream& out, const vector<A> &v) {
    out << "[";
    fore(i, 0, sz(v)) {
        if(i) out << ", ";
        out << v[i];
    }
    return out << "]";
}

const int INF = int(1e9);
const li INF64 = li(1e18);

int n, m;
li l, r;

inline bool read() {
    if(!(cin >> n >> m))
        return false;
    cin >> l >> r;
    return true;
}

const int N = int(2e5) + 555;
vector<int> divs[N];

inline void solve() {
    fore(d, 1, N) {
        for(int pos = d; pos < N; pos += d)
            divs[pos].push_back(d);
    }
    
    li lf = m + 1, rg = m;
    vector<int> cnt(m + 1, 0);
    vector<int> id(m + 1, -1);
    set<int> curDivs;
    
    vector< vector<int> > ans(n + 1);
    
    fore(x1, 1, n + 1) {
        li newlf = (l + x1 - 1) / x1;
        li newrg = r / x1;
        assert(newrg - newlf + 1 >= 0);
        
        while (lf > newlf) {
            lf--;
            for (int d : divs[lf]) {
                if (cnt[d] == 0)
                    curDivs.insert(d);
                cnt[d]++;
                id[d] = (int)lf;
            }
        }
        while (rg > newrg) {
            for (int d : divs[rg]) {
                cnt[d]--;
                if (cnt[d] == 0)
                    curDivs.erase(d);
            }
            rg--;
        }
        
        for (int a : divs[x1]) {
            auto it = curDivs.upper_bound(a);
            if (it == curDivs.end())
                continue;
            
            int b = *it;
            if (x1 / a * 1ll * b <= n) {
                int y1 = id[b];
                
                ans[x1] = {x1, y1, x1 / a * b, y1 / b * a};
            }
        }
    }
    
    fore(i, 1, n + 1) {
        if (ans[i].empty())
            cout << -1 << '\n';
        else {
            cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << " " << ans[i][3] << '\n';
        }
    }
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    int tt = clock();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);
    
    if(read()) {
        solve();
        
#ifdef _DEBUG
        cerr << "TIME = " << clock() - tt << endl;
        tt = clock();
#endif
    }
    return 0;
}