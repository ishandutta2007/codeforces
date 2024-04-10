#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<vector<int> > gr;

vector<int> deg;

const int N = 512;
int cnt[N];

const int mod = 998244353;
int matrix[N][N+1];

int n;

int bp(int x, int y) {
	if (y==0) return 1;
	if (y==1) return x%mod;

	if (y%2) return ((ll) x * bp(x, y-1)) % mod;
	int t = bp(x, y/2);
	return ((ll) t*t) % mod;
}

class GaussModulo {
    const int mod = 998244353;

public:
    enum GaussSolution {
        ZERO, ONE, MANY
    };

    int n;
    GaussSolution solutions_cnt;
    vector<int> solutions;

    // eqs = A|b
    // A*x = b
    GaussModulo(vector< vector<int> >& eqs) {
        n = (int)eqs.back().size() - 1;
        solutions.resize(n, 0);

        int cur_eq = 0;
        for (int v = 0; v < n; v++) {
            int correct_eq_num = -1;
            for (int eq_num = cur_eq; eq_num < eqs.size(); eq_num++) {
                if (eqs[eq_num][v] != 0) {
                    correct_eq_num = eq_num;
                    break;
                }
            }

            if (correct_eq_num == -1) continue;

            swap(eqs[cur_eq], eqs[correct_eq_num]);

            int rev_val = get_rev(eqs[cur_eq][v]);
            for (int i = v; i < eqs[cur_eq].size(); i++) {
                eqs[cur_eq][i] = mult(eqs[cur_eq][i], rev_val);
            }

            for (int eq_num = cur_eq + 1; eq_num < eqs.size(); eq_num++) {
                int cur_val = eqs[eq_num][v];
                for (int i = v; i < eqs[eq_num].size(); i++) {
                    eqs[eq_num][i] -= mult(eqs[cur_eq][i], cur_val);
                    if (eqs[eq_num][i] < 0) eqs[eq_num][i] += mod;
                }
            }

            cur_eq++;
        }

        for (int i = cur_eq; i < eqs.size(); i++) {
            if (eqs[i].back() != 0) {
                solutions_cnt = ZERO;
                return;
            }
        }

        if (cur_eq < n) {
            solutions_cnt = MANY;
        } else {
            solutions_cnt = ONE;
        }

        for (int v = n - 1; v >= 0; v--) {
            int pos = -1;
            for (int i = 0; i + 1 < eqs[v].size(); ++i) {
                if (eqs[v][i] != 0) {
                    pos = i;
                    break;
                }
            }
            if (pos == -1) continue;
            solutions[pos] = eqs[v].back();

            for (int eq_num = v - 1; eq_num >= 0; eq_num--) {
                eqs[eq_num].back() -= mult(eqs[eq_num][pos], eqs[v].back());
                if (eqs[eq_num].back() < 0) eqs[eq_num].back() += mod;
                eqs[eq_num][pos] = 0;
            }
        }
    }

private:
    int mult(int a, int b){
        return a * (ll)b % mod;
    }
    
    int pow(int a, int n) {
        int res = 1;
        while (n) {
            if (n & 1) res = mult(res, a);
            a = mult(a, a);
            n >>= 1;
        }
        return res;
    }

    int get_rev(int val) {
        return pow(val, mod - 2);
    }
};

void solve_gauss() {

	int W = bp(n + 1, mod-2);

	for (int i = 0; i < N; ++i) {
		matrix[i][i] = -1;
		for (int j = 0; j < N; ++j) {
			int P = ((ll) cnt[j] * W) % mod;
			matrix[i][i^j] += P;

			if (matrix[i][i^j] >= mod) matrix[i][i^j] -= mod;
		}

		if (i == 0) {
			matrix[i][N] = (-W+mod)%mod;
		}

	}

	vector<vector<int> > eqs(N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= N; ++j) eqs[i].pb(matrix[i][j]);
	}

	GaussModulo t(eqs);

	int R = (1 - t.solutions[0] + mod) % mod;

	cout << R << '\n';

}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m;
	cin >> n >> m;

	deg.assign(n, 0);

	gr.assign(n, {});
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--, v--;

		gr[u].pb(v);
		deg[v]++;
	}

	queue<int> q;

	vector<int> topsort;
	for (int i = 0; i < n; ++i) if (!deg[i]) {
		q.push(i);
	}

	while (q.size()) {
		int W = q.front();
		q.pop();
		topsort.pb(W);
		for (auto to : gr[W]) {
			deg[to]--;
			if (!deg[to]) q.push(to);
		}
	}

	vector<int> grundy(n, 0);

	reverse(all(topsort));

	for (auto x : topsort) {
		set<int> ms;
		for (auto to : gr[x]) {
			ms.insert(grundy[to]);
		}

		int Q = 0;
		while (ms.count(Q)) Q++;

		grundy[x] = Q;
		cnt[Q]++;

	}

	solve_gauss();



}