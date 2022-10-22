#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

#define F first
#define S second

const int MAXN = 1e3 + 10;

typedef unsigned long long ull;
ull modmul(ull a, ull b, ull M) {
	ll ret = a * b - M * ull(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
	ull ans = 1;
	for (; e; b = modmul(b, b, mod), e /= 2)
		if (e & 1) ans = modmul(ans, b, mod);
	return ans;
}

bool isPrime(ull n) {
	if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
	ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
	    s = __builtin_ctzll(n-1), d = n >> s;
	for (ull a : A) {   // ^ count trailing zeroes
		ull p = modpow(a%n, d, n), i = s;
		while (p != 1 && p != n - 1 && a % n && i--)
			p = modmul(p, p, n);
		if (p != n-1 && i != s) return 0;
	}
	return 1;
}

ull pollard(ull n) {
	auto f = [n](ull x) { return modmul(x, x, n) + 1; };
	ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
	while (t++ % 40 || __gcd(prd, n) == 1) {
		if (x == y) x = ++i, y = f(x);
		if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
		x = f(x), y = f(f(y));
	}
	return __gcd(prd, n);
}
vector<ull> factor(ull n) {
	if (n == 1) return {};
	if (isPrime(n)) return {n};
	ull x = pollard(n);
	auto l = factor(x), r = factor(n / x);
	l.insert(l.end(), r.begin(), r.end());
	return l;
}

int n, k;
ull a[MAXN];
vector<ull> ps[MAXN];
bool sng[MAXN];
map<ull, int> cnt;
pair<int, ull> sec[MAXN]; int sz;

void solve() {
    cin >> n >> k;
    if (k == 1) {
        cout << "0\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ps[i] = factor(a[i]);
        sort(ps[i].begin(), ps[i].end());
        ps[i].resize(unique(ps[i].begin(), ps[i].end()) - ps[i].begin());
        if ((int)ps[i].size() == 1) {
            sng[i] = true;
            cnt[ps[i][0]]++;
        }
    }
    int tot = 0;
    for (auto x: cnt) {
        if (x.S == 1) continue;
        tot += x.S;
        sec[sz++] = {x.S, x.F};
    }
    if (tot < k) {
        set<ull> st;
        for (int i = 0; i < sz; i++)
            st.insert(sec[i].S);
        int c = 0;
        for (int i = 0; i < n; i++)
            if (sng[i] && cnt[ps[i][0]] == 1)
                sng[i] = false;
        for (int i = 0; i < n; i++) {
            if (sng[i] && cnt[ps[i][0]] > 1) {
                c++;
            } else {
                bool fl = false;
                for (auto p: ps[i])
                    if (!st.count(p)) {
                        fl = true;
                        break;
                    }
                if (!fl)
                    c++, sng[i] = true;
            }
        }
        if (c < k) {
            cout << "0\n";
        }
        else {
            for (int i = 0; i < n && k; i++)
                if (sng[i] && (int)ps[i].size() == 1) {
                    cout << a[i] << " ";
                    k--;
                }
            for (int i = 0; i < n && k; i++)
                if (sng[i] && (int)ps[i].size() > 1) {
                    cout << a[i] << " ";
                    k--;
                }
            cout << "\n";
        }
    } else {
        sort(sec, sec + sz);
        if (k % 2 == 1 && sec[sz-1].F == 2) {
            set<ull> st;
            for (int i = 0; i < sz; i++)
                st.insert(sec[i].S);
            for (int i = 0; i < n; i++)
                if (!sng[i]) {
                    bool fl = false;
                    for (auto p: ps[i])
                        if (!st.count(p)) {
                            fl = true;
                            break;
                        }
                    if (!fl && (int)ps[i].size() * 2 < k) {
                        set<ull> to_use;
                        for (auto p: ps[i])
                            to_use.insert(p);
                        int rem = k - 1 - (int)ps[i].size() * 2;
                        for (int i = 0; i < sz && rem; i++)
                            if (!to_use.count(sec[i].S))
                                to_use.insert(sec[i].S), rem -= 2;
                        for (int j = 0; j < n; j++)
                            if (sng[j]) {
                                if (to_use.count(ps[j][0]))
                                    cout << a[j] << " ";
                            } else if (j == i){
                                cout << a[j] << " ";
                            }
                        cout << "\n";
                        return;
                    }
                }
            cout << "0\n";
        } else {
            map<ull, int> take;
            int rem = k;
            for (int i = sz-1; ~i && rem >= 2; i--) {
                take[sec[i].S] = 2;
                rem -= 2;
            }
            if (rem)
                for (int i = sz-1; ~i && rem; i--) {
                    int g = min(rem, sec[i].F - 2);
                    take[sec[i].S] += g;
                    rem -= g;
                }
            for (int i = 0; i < n; i++)
                if (sng[i] && take[ps[i][0]]) {
                    cout << a[i] << " ";
                    take[ps[i][0]]--;
                }
            cout << "\n";
        }
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