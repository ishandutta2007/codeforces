///created by Arsenii Kirillov
#ifdef DEBUG
# define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int) (x).size())

template <typename T>
T input() {
    T res;
    std::cin >> res;
    return res;
}

template <typename IT>
void input_seq(IT b, IT e) {
    std::generate(b, e, input<typename std::remove_reference<decltype(*b)>::type>);
}

#define SZ(vec)         int((vec).size())
#define ALL(data)       data.begin(),data.end()
#define RALL(data)      data.rbegin(),data.rend()
#define TYPEMAX(type)   std::numeric_limits<type>::max()
#define TYPEMIN(type)   std::numeric_limits<type>::min()


using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 123;
const ll INFL = 1e18 + 1e6;
mt19937 tw(228);
ll rnd(ll l, ll r) { return tw() % (r - l + 1) + l; }

const int mod = 998244353;

int add(int a, int b)
{
	return a + b >= mod ? a + b - mod : a + b;
}

int sub(int a, int b)
{
	return a >= b ? a - b : a + mod - b;
}

int mul(int a, int b)
{
	return ((long long)a * b) % mod;
}

int poww(int a, int n, int ans = 1)
{
	while (n)
	{
		if (n & 1)
			ans = mul(ans, a);
		a = mul(a, a);
		n /= 2;
	}	
	return ans;
}

int divv(int a, int b)
{
	return mul(a, poww(b, mod - 2));
}

vector<int> arr, pr, sum;

void init(int v, int l, int r)
{
	if (r - l == 1)
	{
		pr[v] = arr[l];
		sum[v] = 1;
		return;
	}
	int m = (l + r) / 2;
	init(2 * v + 1, l, m);
	init(2 * v + 2, m, r);
	pr[v] = mul(pr[2 * v + 1], pr[2 * v + 2]);
	sum[v] = add(sum[2 * v + 1], mul(sum[2 * v + 2], pr[2 * v + 1]));
}

pair<int, int> get(int v, int l, int r, int q, int w)
{
	if (l >= w || r <= q)
		return {1, 0};
	if (q <= l && r <= w)
		return {pr[v], sum[v]};
	int m = (l + r) / 2;
	auto x = get(2 * v + 1, l, m, q, w);
	auto y = get(2 * v + 2, m, r, q, w);
	return {mul(x.first, y.first), add(x.second, mul(x.first, y.second))};
}

int n, m;

int get(int l, int r)
{
	auto p = get(0, 0, n, l, r);
	return divv(p.second, p.first);
}


void solve() {
	cin >> n >> m;
	arr.resize(n);
	pr.resize(4 * n);
	sum.resize(4 * n);
	set<int> se;
	se.insert(0);
	se.insert(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		arr[i] = divv(arr[i], 100);
		
	}
	init(0, 0, n);
	int ans = get(0, n);
	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		x--;
		if (se.count(x))
		{
			se.erase(x);
			auto q = se.upper_bound(x);
			int r = (*q);
			q--;
			int l = (*q);
			ans = sub(ans, get(l, x));
			ans = sub(ans, get(x, r));
			ans = add(ans, get(l, r));
		}
		else
		{
			auto q = se.upper_bound(x);
			int r = (*q);
			q--;
			int l = (*q);
			se.insert(x);
			ans = sub(ans, get(l, r));
			ans = add(ans, get(l, x));
			ans = add(ans, get(x, r));
		}
		cout << ans << "\n";
	}
}

int main() {
    cout << fixed << setprecision(15);
    cerr << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }

#ifdef LOCAL
    cerr << "time: " << clock() * 1000 / CLOCKS_PER_SEC << endl;
#endif
    return 0;
}