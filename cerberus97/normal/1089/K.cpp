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

const int max_N = 3e5 + 10;
const int max_B = 1e3 + 10;
const int B = 1e3;

ll T[max_B], X[max_B];
int ent[max_N], dur[max_N];
set<pii> block[max_B];

void fixup(int id);
void insert(int t, int d);
void remove(int t, int d);
ll query(int t);

int main() {
	cin_desync();
	int q;
	cin >> q;

	for (int i = 1; i <= q; ++i) {
		char type;
		cin >> type;

		if (type == '?') {
			int t;
			cin >> t;
			cout << query(t) << '\n';
		} else if (type == '+') {
			int t, d;
			cin >> t >> d;
			ent[i] = t; dur[i] = d;
			insert(t, d);
		} else if (type == '-') {
			int id;
			cin >> id;
			remove(ent[id], dur[id]);
		}
	}
}

void insert(int t, int d)
{
	int id = t / B;
	block[id].insert({t, d});
	fixup(id);
}

void remove(int t, int d)
{
	int id = t / B;
	block[id].erase({t, d});
	fixup(id);
}

void fixup(int id)
{
	ll prev = id * B;
	ll x = 0;
	for (auto &knight : block[id]) {
		if (knight.first > prev) {
			x += (knight.first - prev);
		}
		prev = max(prev + knight.second, (ll)knight.first + knight.second);
	}

	T[id] = prev;
	X[id] = x;
}

ll query(int t)
{
	int id = t / B;
	ll prev = 0;
	for (int i = 0; i < id; ++i) {
		ll bstart = B * i;
		if (T[i] == 0) {
			continue;
		}
		if (prev > bstart + X[i]) {
			prev = T[i] + (prev - bstart - X[i]);
		} else {
			prev = T[i];
		}
	}

	for (auto &k : block[id]) {
		if (k.first > t) {
			break;
		}
		prev = max(prev + k.second, (ll)k.first + k.second);
	}

	return max(prev - t, 0ll);
}