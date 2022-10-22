#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MAXN = 2e5 + 10;
const int S = 2700;
const int SQ = 330;

int n, q, a[MAXN];
int cnt[3][MAXN];
int sec[MAXN], sz;
#define up assafdlkjf
int updates[MAXN];
int upp[MAXN];
int ans[MAXN];
int before[MAXN];
int changes[MAXN], ch;
int aa[MAXN], bb[MAXN], cc[MAXN];

void conv(int &x){x = lower_bound(sec, sec + sz, x) - sec;}

void add_freq(int ind, int type) {
    if (type == 1) {
        if (!cnt[1][ind])
            cnt[2][ind/SQ]++;
        cnt[1][ind]++;
    } else {
        cnt[1][ind]--;
        if (!cnt[1][ind])
            cnt[2][ind/SQ]--;
    }
}

void add(int ind, int type) {
    int val = a[ind];
    add_freq(cnt[0][val], -1);
    cnt[0][val] += type;
    add_freq(cnt[0][val], 1);
}

int l, r;
void apply(int time, int type) {
    int who = changes[time];
    int ind = bb[who];
    int val = type == 1 ? cc[who] : before[who];
    //cout << who << " hi " << endl;
    //cout << val << " " << ind << endl;
    if (l <= ind && ind < r)
        add(ind, -1);
    a[ind] = val;
    if (l <= ind && ind < r)
        add(ind, 1);
}

int get_ans() {
    int block = 0;
    while (cnt[2][block] == SQ) block++;
    int i = block*SQ;
    while (cnt[1][i]) i++;
    return i;
}

int ta[MAXN];
void solve() {
    cnt[1][0] = (int)1e9;
    cnt[2][0] = 1;
    memset(ans, -1, sizeof(ans));
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i], sec[sz++] = a[i];
    for (int i = 0; i < q; i++) {
        cin >> aa[i] >> bb[i] >> cc[i];
        if (aa[i] == 2)
            sec[sz++] = cc[i];
        bb[i]--;
    }
    sort(sec, sec + sz);
    sz = unique(sec, sec + sz) - sec;
    for (int i = 0; i < n; i++) conv(a[i]);
    for (int i = 0; i < q; i++)
        if (aa[i] == 2)
            conv(cc[i]);
    memcpy(ta, a, sizeof(a));
    int temp = 0;
    sz = 0;
    for (int i = 0; i < q; i++)
        if (aa[i] == 2) {
            temp++;
            changes[ch++] = i;
            before[i] = a[bb[i]];
            a[bb[i]] = cc[i];
        }
        else {
            upp[i] = temp;
            updates[sz++] = i;
        }
    memcpy(a, ta, sizeof(a));

    sort(updates, updates + sz, [](int q1, int q2) {
            if (bb[q1] / S != bb[q2] / S)
                return bb[q1]/S < bb[q2]/S;
            return make_pair(cc[q1]/S, upp[q1]) < make_pair(cc[q2]/S, upp[q2]);
            });

    l = 0, r = 0;
    int time = 0;
    for (int i = 0; i < sz; i++) {
        int who = updates[i];
        while (l < bb[who]) add(l++, -1);
        while (l > bb[who]) add(--l, 1);
        while (r < cc[who]) add(r++, 1);
        while (r > cc[who]) add(--r, -1);
        while (time < upp[who]) apply(time++, 1);
        while (time > upp[who]) apply(--time, -1);
        ans[who] = get_ans();
        /*cout << l << "   " << r << "   " << time << endl;
        for (int i = 0; i < 10; i++)
            cout << cnt[0][i] << " ";
        cout << endl;*/
    }

    for (int i = 0; i < q; i++)
        if (ans[i] != -1)
            cout << ans[i] << "\n";
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