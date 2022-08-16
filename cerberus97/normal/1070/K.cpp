#include <bits/stdc++.h>
 
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define cin_desync()                      \
	do {                                  \
		ios_base::sync_with_stdio(false); \
		cin.tie(0);                       \
	} while (0)                           \

#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " << arg1 << " | ";
	__f(comma + 1, args...);
}

#else
#define trace(...)
#endif // ifndef ONLINE_JUDGE

const int max_N = 1e5 + 10;
int a[max_N];

void fail()
{
	cout << "No" << endl;
	exit(0);
}

int main()
{
	cin_desync();

	int N, K;
	cin >> N >> K;

	int sum = 0;
	for (int i = 1; i <= N; ++i) {
		cin >> a[i];
		sum += a[i];
	}

	if (sum % K > 0) {
		fail();
	}

	int target = sum / K;
	int prev = 0;
	vector<int> ans;
	int j = 1;
	for (int i = 1; i <= K; ++i) {
		int res = target;
		while(j <= N && a[j] <= res) {
			res -= a[j];
			j++;
		}

		if (res != 0) {
			fail();
		}

		ans.push_back(j - 1 - prev);
		prev = j - 1;
	}

	cout << "Yes" << endl;
	for (auto &x : ans) {
		cout << x << ' ';
	}
	cout << endl;
}