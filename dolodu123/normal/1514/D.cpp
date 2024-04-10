#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pli pair<lli,int>
#define X first
#define Y second

const int K = 550, N = 300087;

struct Query {
    int l, r, idx;
    bool operator < (const Query &other) {
        if (l / K == other.l / K) return r < other.r;
        return l / K < other.l / K;
    }
};
int ans = 0, pos[N], nums[N];

void add(int k) {
    nums[pos[k]+1]++;
    nums[pos[k]]--;
    pos[k]++;
    ans = max(ans, pos[k]);
}

void sub(int k) {
    nums[pos[k]]--;
    nums[pos[k] - 1]++;
    if (!nums[ans]) ans--;
    pos[k]--;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector <Query> Q(q);
    vector <int> input(n+1);
    fop (i,0,n) cin >> input[i];
    vector <int> len(q);
    fop (i,0,q) cin >> Q[i].l >> Q[i].r, Q[i].l--, Q[i].r--, Q[i].idx = i, len[i] = Q[i].r - Q[i].l + 1;
    sort(Q.begin(), Q.end());
    int l = 0, r = -1;
    fop (i,0,N) nums[i] = pos[i] = 0;
    vector <int> anss(q);
    fop (i,0,q) {
        while (r < Q[i].r) {
            r++;
            add(input[r]);
        }
        while (r > Q[i].r) {
            sub(input[r]);
            r--;
        }
        while (l > Q[i].l) {
            l--;
            add(input[l]);
        }
        while (l < Q[i].l) {
            sub(input[l]);
            l++;
        }
        anss[Q[i].idx] = ans;
    }
    fop (i,0,q) {
        /*
         * res, len
         * 2 * (res - x) - 1 <= len - x
         * x >= 2 * res - 1 - len
         */
        cout << max(2 * anss[i] - 1 - len[i], 0) + 1 << '\n';
    }
}