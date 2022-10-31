#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

const int LOGN = 18;
const int MOD = 998244353;
int g = 3;

int mul(int a, int b) {
	return int(a * 1ll * b % MOD);
}
int norm(int a) {
	while(a >= MOD) a -= MOD;
	while(a < 0) a += MOD;
	return a;
}
int binPow (int a, int k) {
	int ans = 1;
	for (; k > 0; k >>= 1) {
		if (k & 1)
			ans = mul(ans, a);
		a = mul(a, a);
	}
	return ans;
}
int inv(int a) {
	return binPow(a, MOD - 2);
}

vector<int> w[LOGN], rv;
bool precalced = false;

void precalc() {
	if(precalced)
		return;
	precalced = true;
	
    int wb = binPow(g, (MOD - 1) / (1 << LOGN));
    fore(st, 0, LOGN) {
        w[st].assign(1 << st, 1);

        int bw = binPow(wb, 1 << (LOGN - st - 1));
        int cw = 1;

        fore(k, 0, (1 << st)) {
            w[st][k] = cw;
            cw = mul(cw, bw);
        }
    }
    
    rv.assign(1 << LOGN, 0);
    fore(i, 1, sz(rv))
		rv[i] = (rv[i >> 1] >> 1) | ((i & 1) << (LOGN - 1));
}

const int MX = (1 << LOGN) + 3;

inline void fft(int a[MX], int n, bool inverse) {
	precalc();
	
    int ln = __builtin_ctz(n);
    assert((1 << ln) < MX);
    assert((1 << ln) == n);

    fore(i, 0, n) {
        int ni = rv[i] >> (LOGN - ln);
        if(i < ni) swap(a[i], a[ni]);
    }

    for(int st = 0; (1 << st) < n; st++) {
        int len = (1 << st);
        for(int k = 0; k < n; k += (len << 1)) {
        	fore(pos, k, k + len) {
                int l = a[pos];
                int r = mul(a[pos + len], w[st][pos - k]);

                a[pos] = norm(l + r);
                a[pos + len] = norm(l - r);
            }
        }
    }
    
    if(inverse) {
        int in = inv(n);
        fore(i, 0, n)
            a[i] = mul(a[i], in);
        reverse(a + 1, a + n);
    }
}

int aa[MX], bb[MX], cc[MX];

vector<int> multiply(const vector<int> &a, const vector<int> &b) {
	int ln = 1;
	while(ln < (sz(a) + sz(b)))
		ln <<= 1;
	
	fore(i, 0, ln)
		aa[i] = (i < sz(a) ? a[i] : 0);
	fore(i, 0, ln)
		bb[i] = (i < sz(b) ? b[i] : 0);
		
	fft(aa, ln, false);
	fft(bb, ln, false);
	
	fore(i, 0, ln)
		cc[i] = mul(aa[i], bb[i]);
	fft(cc, ln, true);
	
	vector<int> ans(cc, cc + ln);
	while(ans.back() == 0)
		ans.pop_back();
	return ans;
}

int n;
vector<int> ps;

inline bool read() {
	if(!(cin >> n))
		return false;
	ps.resize(n);
	fore(i, 0, n)
		cin >> ps[i];
	return true;
}

struct cmp {
	bool operator ()(const vector<int> &a, const vector<int> &b) {
		return sz(a) < sz(b);
	}
};

inline void solve() {
	map<int, int> cnt;
	fore (i, 0, n)
		cnt[ps[i]]++;
	
	multiset< vector<int>, cmp > polys;
	for (auto p : cnt)
		polys.emplace(p.second + 1, 1);
	
	while (sz(polys) > 1) {
		auto it2 = polys.begin();
		auto it1 = it2++;
		polys.insert(multiply(*it1, *it2));
		
		polys.erase(it1);
		polys.erase(it2);
	}

	auto poly = *polys.begin();
//	cerr << '[';
//	fore(i, 0, sz(poly)) {
//		if(i) cerr << ", ";
//		cerr << poly[i];
//	}
//	cerr << ']' << endl;

	cout << poly[n / 2] << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	
	if(read()) {
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	}
	return 0;
}