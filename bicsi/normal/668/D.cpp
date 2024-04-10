#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

unordered_map<int, int> N;
map<int, int> Map;

int elems = 0, times = 0;
int Norm(int x) {
	auto &ret = N[x];
	if(ret == 0) ret = ++elems;
	return ret;
}

int Type[MAXN], Sol[MAXN], Time[MAXN], AIB[MAXN];
vector<int> Queries[MAXN];

void add(int pos, int val) {
	for(; pos <= times; pos += (pos & -pos))
		AIB[pos] += val;
}
int query(int pos) {
	int s = 0;
	for(; pos; pos -= (pos & -pos))
		s += AIB[pos];
	return s;
}

void Read(int &x) {
	char c;
	for(c = getchar(); !isdigit(c); c = getchar());
	for(x = 0; isdigit(c); c = getchar())
		x = (x << 1) + (x << 3) + c - '0';
}

int main() {
	int q, t, x, v;
	Read(q);

	for(int i = 1; i <= q; ++i) {
		Read(Type[i]); Read(Time[i]); Read(x);
		Queries[Norm(x)].emplace_back(i);
		Map[Time[i]] = 1;
	}

	for(auto &p : Map) {
		p.second = ++times;
	}

	for(int i = 1; i <= q; ++i) {
		Time[i] = Map[Time[i]];
	}

	for(int i = 1; i <= elems; ++i) {

		for(auto qi : Queries[i]) {
			if(Type[qi] == 1) {
				add(Time[qi], 1);
			} else if(Type[qi] == 2) {
				add(Time[qi], -1);
			} else {
				Sol[qi] = query(Time[qi]);
			}
		}

		for(auto qi : Queries[i]) {
			if(Type[qi] == 1) {
				add(Time[qi], -1);
			} else if(Type[qi] == 2) {
				add(Time[qi], 1);
			}
		}
	}

	for(int i = 1; i <= q; ++i) {
		if(Type[i] == 3)
			cout << Sol[i] << '\n';
	}

	return 0;
}