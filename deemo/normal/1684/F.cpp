#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MAXN = 2e5 + 10;

int n, a[MAXN], m, tl[MAXN], tr[MAXN], sec[MAXN];
int mn[MAXN];

#define prev lakjsdf
#define next j8f9
int prev[MAXN], next[MAXN];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> tl[i] >> tr[i], tl[i]--;
    iota(sec, sec + m, 0);
    sort(sec, sec + m, [](int q1, int q2) {
            return tr[q1] < tr[q2];
            });
    mn[m] = 1e9;
    for (int i = m-1; ~i; i--)
        mn[i] = min(mn[i+1], tl[sec[i]]);

    map<int, int> lst;
    memset(prev, -1, sizeof(prev));
    memset(next, -1, sizeof(next));
    for (int i = 0; i < n; i++) {
        int prv = lst.count(a[i])? lst[a[i]]: -1;
        lst[a[i]] = i;
        
        int pos = upper_bound(sec, sec + m, i, [](int i, int q) {
                return tr[q] > i;
                }) - sec;
        if (mn[pos] <= prv) {
            prev[i] = prv;
            next[prv] = i;
        }
    }

    vector<pair<int, pii>> gec;
    int stop = n-1;
    int ans = 1e9;
    set<int> st;
    for (int i = 0; i < n; i++)
        if (prev[i] == -1 && next[i] != -1) {
            stop = min(stop, next[i]);
            int cur = next[i];
            while (~next[cur])
                cur = next[cur];

            int pos = upper_bound(sec, sec + m, cur, [](int cur, int q) {
                    return tr[q] > cur;
                    }) - sec;
            if (mn[pos] <= i)
                gec.push_back({i, {prev[cur], cur}});
            st.insert(prev[cur]);
        }
    
    if (st.empty())
        ans = 0;
    else {
        sort(gec.begin(), gec.end());
        reverse(gec.begin(), gec.end());
        for (int i = 0; i <= stop; i++) {
            ans = min(ans, *st.rbegin() - i + 1);
            while (gec.size() && gec.back().first == i)
                st.erase(gec.back().S.F), st.insert(gec.back().S.S), gec.pop_back();
        }
    }
    cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}