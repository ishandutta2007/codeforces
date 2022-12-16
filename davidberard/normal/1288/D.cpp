#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int N = 300300;

unordered_set<int> members[256];
int group[N];

int a[N][8];
int n, m;

struct element {
    int val, x, y;
    element() {}
    element(int a, int b, int c) :val(a), x(b), y(c) {}
    bool operator< (const element& o) const {
        return val < o.val;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    vector<element> elements;
    for (int i=1; i<=n; ++i) {
        for (int j=0; j<m; ++j) {
            cin >> a[i][j];
            elements.emplace_back(a[i][j], i, j);
        }
        members[0].insert(i);
    }
    sort(elements.begin(), elements.end());
    element ans(-1, -1, -1);
    for (int i=0; i<elements.size(); ++i) {
        int z=i;
        while (elements.size() > z && elements[z].val == elements[i].val) ++z;
        for (int j=i; j<z; ++j) {
            int val = elements[j].val;
            int x = elements[j].x;
            ////cerr << "x = " << x << endl;
            //int y = elements[z].y;
            int spec = 0;
            for (int k=0; k<m; ++k) {
                if (a[x][k] < val) {
                    spec |= (1<<k);
                }
            }
            int other = 0;
            for (int k=0; k<256; ++k) {
                if (k&spec) continue;
                if (members[k].size()) {
                    other = *members[k].begin();
                }
            }
            if (other) {
                ans = max(ans, element(val, x, other));
            }

        }
        for (int j=i; j<z; ++j) {
            int x = elements[j].x;
            int cur = group[x];
            int nxt = cur^(1<<elements[j].y);
            //cerr << " MOVING " << x << " FROM " << bitset<8>(cur) << " TO " << bitset<8>(nxt) << endl;
            assert (!(cur&(1<<elements[j].y)));
            members[cur].erase(x);
            members[nxt].insert(x);
            group[x] = nxt;
        }
        i = z-1;
    }
    ////cerr << " VAL WAS " << ans.val << endl;
    cout << ans.x << " " << ans.y << endl;
    return 0;
}