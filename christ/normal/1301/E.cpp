#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef gp_hash_table<int, null_type,hash<int>, equal_to<int>, direct_mask_range_hashing<int>, linear_probe_fn<>,
    hash_standard_resize_policy<hash_exponential_size_policy<>, hash_load_check_resize_trigger<true>,true>> hash_set;
typedef gp_hash_table<int,null_type> hash_map;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define complete_unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define all(a) a.begin(),a.end()
#define println printf("\n");
#define readln(x) getline(cin,x);
#define pb push_back
#define endl "\n"
#define INT_INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007
#define MOD2 1494318097
#define SEED 131
#define mp make_pair
#define fastio cin.tie(0); cin.sync_with_stdio(0);

#define MAXN 100005

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef pair<int,pii> triple;
typedef int8_t byte;

const ld PI = (ld)4*atanl(1);

mt19937 g1(chrono::steady_clock::now().time_since_epoch().count());

int randint(int a, int b){return uniform_int_distribution<int>(a, b)(g1);}
ll randlong(ll a,ll b){return uniform_int_distribution<long long>(a, b)(g1);}

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll  b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

char grid[505][505];
int pre[505][505][505];

int main() {
	fastio;
	int N, M, Q;
	cin >> N >> M >> Q;
	for(int i = 0; i < N; i++)
		cin >> grid[i];
	for(int i = 0; i + 1 < N; i++) {
		for(int j = 0; j + 1 < M; j++) {
			if(grid[i][j] == 'R' && grid[i][j + 1] == 'G' && grid[i + 1][j] == 'Y' && grid[i + 1][j + 1] == 'B') {
				int k = 2;
				for(; k <= min(min(i, j) + 1, min(N - i, M - j)); k++) {
					for(int l = 0; l < k; l++) {
						if(grid[i - l][j - (k - 1)] != 'R')
							goto no;
						if(grid[i - l][j + k] != 'G')
							goto no;
						if(grid[i + l + 1][j - (k - 1)] != 'Y')
							goto no;
						if(grid[i + l + 1][j + k] != 'B')
							goto no;
						if(grid[i - (k - 1)][j - l] != 'R')
							goto no;
						if(grid[i - (k - 1)][j + l + 1] != 'G')
							goto no;
						if(grid[i + k][j - l] != 'Y')
							goto no;
						if(grid[i + k][j + l + 1] != 'B')
							goto no;
					}
				}
no:
				for(int l = 1; l < k; l++) {
					//cout << "ins " << l << ' ' << i + 1 << ' ' << j + 1 << endl;
					pre[l][i + 1][j + 1] = 1;
				}
			}
		}
	}
	int mn = min(N, M);
	for(int k = 1; k <= mn; k++)
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= M; j++)
				pre[k][i][j] += pre[k][i - 1][j] + pre[k][i][j - 1] - pre[k][i - 1][j - 1];
	/*
	for(int k = 1; k <= mn; k++) {
		for(int i = 0; i <= N; i++) {
			for(int j = 0; j <= M; j++)
				cout << pre[k][i][j] << ' ';
			cout << endl;
		}
		cout << endl;
	}
	*/
	for(int i = 0; i < Q; i++) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		r1--; c1--;
		int k = min(r2 - r1, c2 - c1) / 2;
		while(k) {
			int nr1 = r1 + k - 1, nc1 = c1 + k - 1, nr2 = r2 - k, nc2 = c2 - k;
			//cout << "q " << k << ' ' << r1 << ' ' << c1 << ' ' << r2 << ' ' << c2 << " val " << pre[k][r2][c2] + pre[k][r1][c1] - pre[k][r1][c2] - pre[k][r2][c1] << endl;
			if(pre[k][nr2][nc2] + pre[k][nr1][nc1] - pre[k][nr1][nc2] - pre[k][nr2][nc1] > 0) break;
			--k;
		}
		cout << (4 * k * k) << '\n';
	}
}