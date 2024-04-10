#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 998244353 ;
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

const int MAXN = 1e3 + 10;
const int LOG = 30;

int n, a[MAXN], m;
vector<pii> vec[MAXN];

struct Mat {
    int v[64][64], n, m;
    Mat(int n, int m): n(n), m(m) {
        memset(v, 0, sizeof(v));
    }
	Mat(){}
    int* operator [](int x) { return v[x]; }
};

Mat mul(Mat a, Mat b){
    Mat ret(a.n, b.m);
    for (int i = 0; i < a.n; i++)
        for (int j = 0; j < b.m; j++)
            for (int w = 0; w < a.m; w++)
                ret[i][j] = (ret[i][j] + 1ll*a[i][w]*b[w][j]) % MOD;
    return ret;
}

int f[4][4];
Mat sv[LOG];

Mat pw(Mat a, int b){
    Mat ret(a.n, a.m);
    for (int i = 0; i < ret.n; i++) ret[i][i] = 1;
    while (b) {
        if (b & 1)
            ret = mul(ret, a);
        b >>= 1;
        a = mul(a, a);
    }
    return ret;
}

int getNext(int cur, int last){
	int mask = 0;
	for (int i = 0; i < 3; i++)
		if (f[last][i])
			mask |= 1<<((cur>>i*2)&3);
	int nn = 0;
	while (mask>>nn&1) nn++;
	cur &= (1<<4)-1;
	cur <<= 2;
	cur ^= nn;
	return cur;
}


void pre() {
	sv[0] = Mat(64, 64);
	for (int last = 0; last < 3; last++)
		for (int i = 0; i < 64; i++){
			int nxt = getNext(i, last);
			add(sv[0][nxt][i], 1);
		}
	for (int w = 1; w < LOG; w++)
		sv[w] = mul(sv[w-1], sv[w-1]);
}

void apply(Mat &cur, int t){
	for (int w = LOG-1; ~w; w--)
		if (t - (1<<w) >= 0)
			cur = mul(sv[w], cur), t -= 1<<w;
}

void applySpec(Mat &cur, int last){
	Mat temp(64, 1);
	for (int i = 0; i < 64; i++) 
		add(temp[getNext(i, last)][0], cur[i][0]);
	cur = temp;
}

vector<int> get(int ind){
	sort(vec[ind].begin(), vec[ind].end());
	Mat cur(64, 1);
	cur[(3<<4)|(3<<2)|3][0] = 1;
	int last = 0;
	for (int i = 0; i < (int)vec[ind].size(); i++){
		apply(cur, vec[ind][i].F - last);
		applySpec(cur, vec[ind][i].S);
		last = vec[ind][i].F+1;
	}
	if (last < a[ind])
		apply(cur, a[ind] - last);

	vector<int> res(4, 0);
	for (int k = 0; k < 4; k++)
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				add(res[k], cur[i<<4|j<<2|k][0]);
	return res;
}

int ans[4], _ans[4];
void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> m;
	for (int i = 0; i < m; i++){
		int x, y, c; cin >> x >> y >> c, x--, y--, c--;
		vec[x].push_back({y, c});
	}
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> f[i][j];
	pre();
	ans[0] = 1;
	for (int i = 0; i < n; i++){
		vector<int> temp = get(i);
		memset(_ans, 0, sizeof(_ans));
		for (int a = 0; a < 4; a++)
			for (int b = 0; b < 4; b++)
				add(_ans[a^b], 1ll*ans[a]*temp[b]%MOD);
		memcpy(ans, _ans, sizeof(ans));
	}
	cout << ans[0] << "\n";
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