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

const int MAXN = 6e5 + 10;
const int S = 450;

int n, m;
int x[MAXN], y[MAXN];
int ans[MAXN], sm[MAXN], sm2[MAXN];
vector<int> vec[MAXN];
vector<int> gec[MAXN];
bool matters[MAXN];
int in[MAXN];

int ss[MAXN];
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        if (x[i] < m)
            matters[i] = true;
    }
   
    for (int i = 0; i < m; i++) {
        int a, k; cin >> a >> k, k--;
        vec[k].push_back(i);
    }

    for (int i = 0; i < n; i++)
        if (vec[i].size() & 1)
            vec[i].push_back(m);

    for (int i = 0; i < n; i++)
        if (matters[i]) {
            if (x[i] + y[i] >= S) {
                for (int j = 0; j < vec[i].size(); j += 2) {
                    int l = vec[i][j], r = vec[i][j+1];
                    int jump = x[i] + y[i];
                    for (int w = l + x[i]; w < r; w += jump)
                        sm[w]++, sm[min(r, w + y[i])]--;
                }
            }
            else
                gec[x[i] + y[i]].push_back(i);
        }

    for (int jump = 1; jump < S; jump++) {
        memset(sm2, 0, sizeof(sm2));
        for (int i: gec[jump]) {
            for (int j = 0; j < vec[i].size(); j += 2) {
                int l = vec[i][j], r = vec[i][j+1];
                if (l + jump >= r)
                    sm[min(r, l + x[i])] += 1, sm[r] -= 1;
                else {
                    sm2[l + x[i]] += 1;
                    sm2[l + jump] -= 1;
                    int dif = r - l;
                    if (dif % jump > x[i]) {
                        sm2[r] -= 1;
                        sm2[r + (jump - dif % jump)] += 1;
                        int nxt = r + (jump - dif % jump) + x[i];
                        sm2[nxt] -= 1;
                        sm2[nxt + y[i] - (jump - dif % jump)] += 1;
                    } else {
                        int nxt = r - dif % jump;
                        sm2[nxt + x[i]] -= 1;
                        sm2[nxt + jump] += 1;
                    }
                }
            }
        }

        memset(ss, 0, sizeof(ss));
        int rs = 0;
        for (int i = 0; i < m; i++) {
            rs += sm2[i];
            ss[i] = rs;
            if (i >= jump)
                ss[i] += ss[i - jump];
            ans[i] += ss[i];
        }
    }

    int s = 0;
    for (int i = 0; i < m; i++) {
        s += sm[i];
        cout << ans[i] + s << "\n";
    }
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