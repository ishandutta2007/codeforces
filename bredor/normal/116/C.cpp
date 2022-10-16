//  228

#include <bits/stdc++.h>
using namespace std;

#define debug(T) { cout << ">> " << #T << " = " << (T) << endl; }
#define println() { cout << endl; }
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define sz(c) int((c).size())

typedef long long ll;
typedef unsigned long long ull;

template<typename T> void read(vector<T>& v);
template<typename T> void read(T* arr, int n);
template<typename T> void print(const vector<T>& v);
template<typename T> void print(T* arr, int n);
template<typename T> void print(const T& c);
template<typename T> inline T ceil(T x, T y);

const ll MOD = 1'000'000'007;

void precalc() {}

int degree(const vector<int> &v, int n) {
    if (v[n] == -1) return 0;
    return 1 + degree(v, v[n]);
}

vector<int> getDegrees(const vector<int> &v) {
    int n = v.size();
    vector<int> degrees(n, -1);
    for (int i = 0; i < sz(v); ++i) {
        if (degrees[i] == -1) {
            degrees[i] = degree(v, i);
        }
    }
    return degrees;
}

void solve() {
    int n; cin >> n;
    vector<int> v(n); read(v);
    for (auto& x : v) {
        if (x != -1) --x;
    }

    vector<int> degrees = getDegrees(v);
    int maxHeight = *max_element(all(degrees)) + 1;

    cout << maxHeight << "\n";
}

int main() {
	// for fast I/O
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	// redirect I/O
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int T = 1;
	// cin >> T;

	// precalc();
	for (int tc = 1; tc <= T; ++tc) {
		solve();
		// println();
	}
	// cout << "All OK!" << endl;

	return 0;
}

template<typename T> 
void read(vector<T>& v) {
	for (auto &it : v) cin >> it;
}

template<typename T> 
void read(T* arr, int n) {
	for (int i = 0; i < n; ++i) cin >> arr[i];
}

template<typename T> 
void print(const vector<T>& v) {
	for (auto &it : v) cout << it << " ";
	cout << "\n";
}

template<typename T> 
void print(T* arr, int n) {
	for (int i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

template<typename T>
void print(const T& c) {
	for (auto& it : c) cout << it << " ";
	cout << "\n";
}

template<typename T> 
inline T ceil(T x, T y) {
	return (x + y - 1) / y;
}