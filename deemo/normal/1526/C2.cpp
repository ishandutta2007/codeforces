#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MAXN = 2e5 + 10;

int n, a[MAXN];
ll fen[MAXN];

void add(int v, int val) {
    for (; v < MAXN; v += v&-v)
        fen[v] += val;
}

ll get(int v) {
    ll res = 0;
    for (; v; v-=v&-v)
        res += fen[v];
    return res;
}

int sec[MAXN];
set<pii> st;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    iota(sec, sec + n, 0);
    sort(sec, sec + n, [](int x, int y) {
            return a[x] > a[y];
            });

    int ans = 0;
    for (int i = 0; i < n; i++){
        int v = sec[i];
        ll sm = get(v+1);
        if (sm + a[v] < 0) continue;

        if (a[v] > 0) {
            st.insert({v, a[v]});
            add(v+1, a[v]);
        } else if (a[v] < 0) {
            int req = -a[v];
            while (req > 0) {
                auto it = st.upper_bound({v+1, -1});
                it--;
                auto x = *it;
                st.erase(it);
                int g = min(x.S, req);
                req -= g;
                x.S -= g;
                add(x.F+1, -g);
                if (x.S)
                    st.insert(x);
            }
        }
        ans++;
    }
    cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	//cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}