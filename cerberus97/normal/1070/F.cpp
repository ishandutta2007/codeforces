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

int main()
{
	cin_desync();

	int N;
	cin >> N;

	map<string, vector<int>> audi;

	int ans = 0;
	int t1 = 0, t2 = 0;
	for (int i = 1; i <= N; ++i) {
		string type; int x;
		cin >> type >> x;

		if (type == "11") {
			ans += x;
			++t1; ++t2;
		} else {
			audi[type].push_back(x);
		}
	}

	for (auto &p : audi) {
		sort(p.second.begin(), p.second.end());
	}

	int m = min(audi["01"].size(), audi["10"].size());
	int tot = t1 + 2 * m;
	t1 += m; t2 += m;

	for (int i = 0; i < m; ++i) {
		string arr[] = {"01", "10"};
		for (auto &key : arr) {
			ans += audi[key].back();
			audi[key].pop_back();
		}
	}

	vector<int> rem;
	for (auto &c : audi) {
		rem.insert(rem.end(), c.second.begin(), c.second.end());
	}

	sort(rem.begin(), rem.end());
	while(!rem.empty() && (min(t1, t2) * 2 >= tot + 1)) {
		ans += rem.back();
		rem.pop_back();
		++tot;
	}

	cout << ans << endl;
}