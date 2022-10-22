#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 1e9 + 7;//XXX
const int C = 26;//XXX

void add(int &x, int y){
	x += y;
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
}

int fix(int x){
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
	return x;
}

int pw(int a, int b){
	int ret = 1;
	while (b){
		if (b & 1)
			ret = 1ll*ret*a%MOD;
		b >>= 1;
		a = 1ll*a*a%MOD;
	}
	return ret;
}

const int MAXN = 2e5 + 10;
const int XX = 100;

int n, a[MAXN];

int cnt2[MAXN], cp[MAXN][XX];
int check(int l, int r) {
    pii mx {-1, -1};
    for (int i = 0; i < XX; i++) {
        int temp = cp[r][i] - cp[l][i];
        if (mx.S < temp)
            mx.S = temp;
        if (mx.S > mx.F)
            swap(mx.F, mx.S);
    }
    return mx.F == mx.S;
}

int lst[XX][MAXN * 2];
int dd[XX];
int go(int k) {
    memset(dd, 0, sizeof(dd));
    for (int i = 0; i < XX; i++) {
        fill(lst[i] + max(0, MAXN - cnt2[k] - cnt2[i]), lst[i] + min(2*MAXN, MAXN + cnt2[k] + cnt2[i]), -1);
        lst[i][MAXN] = n;
    }
    int res = 0;
    for (int i = n-1; i; i--) {
        if (a[i] == k) {
            for (int j = 0; j < XX; j++) {
                dd[j]++;
                if (lst[j][MAXN - dd[j]] == -1)
                    lst[j][MAXN - dd[j]] = i;
            }
        } else {
            dd[a[i]]--;
            if (lst[a[i]][MAXN - dd[a[i]]] == -1)
                lst[a[i]][MAXN - dd[a[i]]] = i;
        }

        if (a[i-1] == k) {
            int firstBad = 1e9;
            int lastGood = i;
            for (int j = 0; j < XX; j++) {
                if (j == k) continue;
                int pos = lst[j][MAXN - dd[j]];
                assert (pos != -1);
                if (pos == n || a[pos] == k)
                    lastGood = max(lastGood, pos);
                else
                    firstBad = min(firstBad, pos);
            }
            if (firstBad <= n+3) {
                if (res < firstBad - i && check(i, firstBad))
                    res = max(res, firstBad - i);
            } else if (lastGood != i) {
                if (res < lastGood -i && check(i, lastGood))
                    res = max(res, lastGood - i);
            }
        }
    }
    return res;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i], a[i]--;
        for (int j = 0; j < XX; j++)
            cp[i+1][j] = cp[i][j];
        cp[i+1][a[i]]++;
    }
    int ans = 0;
    for (int l = 0; l < n; l++)
        if (check(l, n)) {
            ans = n-l;
            break;
        }
    for (int r = n - 1; r; r--)
        if (check(0, r)) {
            ans = max(ans, r);
            break;
        }
    check(0, n);
    memcpy(cnt2, cp[n], sizeof(cnt2));
    for (int i = 0; i < min(n, XX); i++)
        ans = max(ans, go(i));
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