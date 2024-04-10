#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <cassert> 
#include <algorithm> 
#include <set> 
#include <iomanip> 
#include <queue> 
#include <deque> 
#include <unordered_set> 
#include <unordered_map> 
#include <functional> 
#include <cmath> 

bool home = true;
using namespace std;

struct Data {
	int index;
	int first;
	int second;
};

bool operator == (Data a, Data b) {
	return a.first == b.first && a.second == b.second;
}


signed main() {

#ifdef ONLINE_JUDGE
	home = 0;
#endif
	if (home) {
		FILE* stream;
		freopen_s(&stream, "iron_man.txt", "r", stdin);
	}
	else {
		ios::sync_with_stdio(0); cin.tie(0);
	}


	int n;
	string s;
	cin >> n >> s;
	assert((int)s.size() == (1 << n));
	vector<int> order, comp(1 << n), f((1 << n) + 1, 0);

	{
		vector<pair<char, int>> positions;
		for (int i = 0; i < (1 << n); i++) {
			positions.push_back(make_pair(s[i], i));
		}
		sort(positions.begin(), positions.end());
		int low = 0, cnt_c = 0;
		while (low < (1 << n)) {
				int high = low;
			order.push_back(positions[low].second);
			comp[positions[low].second] = cnt_c;
			while (high + 1 < (1 << n) && positions[high + 1].first == positions[high].first) {
				order.push_back(positions[++high].second);
				comp[positions[high].second] = cnt_c;
			}
			low = high + 1;
			cnt_c++;
		}
	}

	vector<Data> datas_aux(1 << n), datas(1 << n);
	for (int new_size = 2; new_size <= (1 << n); new_size *= 2) {
		int mx_c = 0;
		for (int i = 0; i < (1 << n); i++) {
			datas[i] = { i, comp[i], comp[i ^ (new_size / 2)] };
			f[i] = 0;
			mx_c = max(mx_c, datas[i].first);
			mx_c = max(mx_c, datas[i].second);
		}
		// second (actually first, lol) phase
		
		for (int i = 0; i < (1 << n); i++) {
			f[datas[i].second]++;
		}

		for (int i = 1; i <= mx_c; i++) {
			f[i] += f[i - 1];
		}

		for (int i = 0; i < (1 << n); i++) {
			datas_aux[--f[datas[i].second]] = datas[i];
		}



		// first (actually second, lol) phase 

		for (int i = 0; i <= mx_c; i++) {
			f[i] = 0;
		}

		for (int i = 0; i < (1 << n); i++) {
			f[datas_aux[i].first]++;
		}

		for (int i = 1; i <= mx_c; i++) {
			f[i] += f[i - 1];
		}

		for (int i = (1 << n) - 1; i >= 0; i--) {
			datas[--f[datas_aux[i].first]] = datas_aux[i];
		}


		
		order.clear();

		int cnt_c = 0;
		for (int i = 0; i < (1 << n); i++) {
			if (i > 0 && !(datas[i] == datas[i - 1])) {
				cnt_c++;
			}
			order.push_back(datas[i].index);
			comp[datas[i].index] = cnt_c;
		}
	}

	int index = order[0];
	string ret;
	for (int i = 0; i < (1 << n); i++) {
		ret += s[i ^ index];
	}
	cout << ret << "\n";
}