#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MAXN = 1e5 + 10;
const int SQ = 300;

int n, a[MAXN];
int q, tl[MAXN], tr[MAXN], sec[MAXN];

int cnt[MAXN], how_many[MAXN];
int nxt[MAXN], prv[MAXN];
void add(int x) {
    int cur = cnt[x];
    bool cur_empties = how_many[cur] == 1;
    bool next_exists = how_many[cur+1];
    if (!next_exists) {
        if (~nxt[cur])
            prv[nxt[cur]] = cur + 1;
        nxt[cur + 1] = nxt[cur], nxt[cur] = cur + 1, prv[cur + 1] = cur;
    }
    if (cur_empties)
        prv[cur + 1] = prv[cur], nxt[prv[cur]] = cur + 1;
    how_many[cnt[x]]--;
    cnt[x]++;
    how_many[cnt[x]]++;
    /*cout << prv[0] << "   " << prv[1] << "   " << prv[2] << "    " << prv[3] << "  " << prv[4] << endl;
    cout << nxt[0] << "   " << nxt[1] << "   " << nxt[2] << "    " << nxt[3] << "  " << nxt[4] << endl;
    cout << endl;*/
}

void remove(int x) {
    int cur = cnt[x];
    bool cur_empties = how_many[cur] == 1;
    bool prv_exists = how_many[cur-1];
    if (!prv_exists)
        nxt[cur-1] = cur, prv[cur-1] = prv[cur], nxt[prv[cur]] = cur - 1, prv[cur] = cur-1;
    if (cur_empties) {
        nxt[cur-1] = nxt[cur];
        if (~nxt[cur])
            prv[nxt[cur]] = cur-1;
    }
    how_many[cnt[x]]--;
    cnt[x]--;
    how_many[cnt[x]]++;
}

int ans[MAXN];
int get_ans() {
    int sz = 0, cur = 0;
    deque<pii> mn, sc;
    while (cur != -1) {
        if (cur)
            mn.push_back({cur, how_many[cur]});
        cur = nxt[cur];
    }

    int res = 0;
    while (mn.size() || sc.size()) {
        if (mn.empty() || (sc.size() && mn.front().F >= sc.front().F)) {
            mn.push_front(sc.front());
            sc.pop_front();
        }

        auto first = mn.front();
        mn.pop_front();
        if (first.S > 1) {
            res += first.F * (first.S & (first.S^1));
            sc.push_back({first.F<<1, first.S>>1});
            if (first.S&1)
                mn.push_front({first.F, 1});
        } else {
            if (mn.empty() && sc.empty()) break;
            
            if (mn.empty() || (sc.size() && mn.front().F >= sc.front().F)) {
                mn.push_front(sc.front());
                sc.pop_front();
            }

            auto second = mn.front();
            mn.pop_front();
            if (second.S > 1)
                mn.push_front({second.F, second.S - 1});
            res += second.F + first.F;
            sc.push_back({second.F + first.F, 1});
        }
    }
    return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> q;
    for (int i = 0; i < q; i++) cin >> tl[i] >> tr[i], tl[i]--;
    iota(sec, sec + q, 0);
    sort(sec, sec + q, [](int q1, int q2) {
            if (tl[q1] / SQ != tl[q2] / SQ)
                return tl[q1] / SQ < tl[q2] / SQ;
            return tr[q1] < tr[q2];
            });

    how_many[0] = MAXN;
    nxt[0] = prv[0] = -1;
    int l = 0, r = 0;
    for (int i = 0; i < q; i++) {
        int curq = sec[i];
        while (r < tr[curq]) add(a[r++]);
        while (l > tl[curq]) add(a[--l]);
        while (r > tr[curq]) remove(a[--r]);
        while (l < tl[curq]) remove(a[l++]);
        ans[curq] = get_ans();
    }
    
    for (int i = 0; i < q; i++)
        cout << ans[i] << "\n";
	return 0;
}