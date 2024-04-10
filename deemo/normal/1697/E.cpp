#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 998244353;
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

const int MAXN = 100 + 5;

int n;
pii p[MAXN];
vector<int> adj[MAXN], cl[MAXN];
int cands[6];

int dist(int i, int j) {
    return abs(p[i].F-p[j].F) + abs(p[i].S-p[j].S);
}

bool done[MAXN];
int ch[MAXN][MAXN], ss[MAXN];
void solve() {
    ss[0] = 1;
    for (int i = 1; i < MAXN; i++)
        ss[i] = 1ll*ss[i-1]*i % MOD;
    for (int i = 0; i < MAXN; i++) {
        ch[i][0] = 1;
        for (int j = 1; j <= i; j++)
            ch[i][j] = (ch[i-1][j] + ch[i-1][j-1]) % MOD;
    }

    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i].F >> p[i].S;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i^j) {
                if (cl[i].empty() || dist(i, j) == dist(i, cl[i][0]))
                    cl[i].push_back(j);
                else if (dist(i, j) < dist(i, cl[i][0]))
                    cl[i] = vector<int> {j};
            }

    for (int i = 0; i < n; i++)
        done[i] |= cl[i].size() > 3;

    for (int i = 0; i < n; i++)
        sort(cl[i].begin(), cl[i].end());

    for (int i = 0; i < n; i++)
        if (!done[i]) {
            done[i] = true;
            if (cl[i].size() == 1) {
                int other = cl[i][0];
                if (!done[other] && cl[other].size() == 1 && cl[other][0] == i) {
                    done[i] = done[other] = true;
                    cands[2]++;
                }
            } else if (cl[i].size() == 2) {
                int o1 = cl[i][0], o2 = cl[i][1];
                if (!done[o1] && !done[o2] && cl[o1].size() == 2 && cl[o2].size() == 2 &&
                        (cl[o1][0] == i && cl[o1][1] == o2 || cl[o1][0] == o2 && cl[o1][1] == i)
                        && 
                        (cl[o2][0] == i && cl[o2][1] == o1 || cl[o2][0] == o1 && cl[o2][1] == i)) {
                    done[i] = done[o1] = done[o2] = true;
                    cands[3]++;
                }
            } else {
                bool failed = false;
                for (int j = 0; j < 3; j++)
                    failed |= done[cl[i][j]] || cl[cl[i][j]].size() != 3;
                if (failed) continue;

                for (int j = 0; j < 3; j++) {
                    vector<int> temp {i};
                    for (int w = 0; w < 3; w++)
                        if (w != j)
                            temp.push_back(cl[i][w]);
                    sort(temp.begin(), temp.end());
                    failed |= temp != cl[cl[i][j]];
                }
                if (!failed) {
                    cands[4]++;
                    done[i] = done[cl[i][0]] = done[cl[i][1]] = done[cl[i][2]] = true;
                }
            }
        }

    int ans = 0;
    for (int t2 = 0; t2 <= cands[2]; t2++)
        for (int t3 = 0; t3 <= cands[3]; t3++) 
            for (int t4 = 0; t4 <= cands[4]; t4++) {
                int groups = t2 + t3 + t4 + (n-2*t2-3*t3-4*t4);
                ans = (ans + 1ll*ch[n][groups] * ss[groups]%MOD * ch[cands[2]][t2] % MOD * ch[cands[3]][t3] % MOD * ch[cands[4]][t4]) % MOD;
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