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

void solve() {
	int n;
	cin >> n;
	vector<int> mas(n), arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> mas[i];
		arr[i] = mas[i];
	}
	sort(arr.begin(), arr.end());
	int m = unique(arr.begin(), arr.end()) - arr.begin();
	arr.resize(m);
	vector<int> cnt(m, 0);
	for (int i = 0; i < n; i++)
	{
		mas[i] = lower_bound(arr.begin(), arr.end(), mas[i]) - arr.begin();
		cnt[mas[i]]++;
	}
	int g = cnt[m - 1];
	assert(g > 0);
	int s = 0;
	int q = m - 2;
	while (q >= 0 && s <= g)
	{
		s += cnt[q];
		q--;
	}
	int b = 0;
	while (q >= 0 && b <= g)
	{
		b += cnt[q];
		q--;
	}
	if (b <= g || g + s + b > n / 2)
	{
		cout << "0 0 0\n";
		return;
	}
	while (q >= 0 && g + s + b + cnt[q] <= n / 2)
	{
		b += cnt[q];
		q--;
	}
	cout << g << " " << s << " " << b << "\n";
}

int main() {
    cout << fixed << setprecision(15);
    cerr << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }

#ifdef LOCAL
    cerr << "time: " << clock() * 1000 / CLOCKS_PER_SEC << endl;
#endif
    return 0;
}