#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define SZ(a) (int)(a).size()

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	unordered_map<char, int> t;
	for (char c: s) {
		t[c]++;
	}
	vector<char> mids;
	for (auto it = begin(t); it != end(t); ) {
		if (it->second & 1) {
			mids.push_back(it->first);
			it->second--;
		}
		if (it->second == 0) {
			it = t.erase(it);
		} else {
			it++;
		}
	}

	int k = SZ(mids);
	if (k == 0) {
		printf("1\n");
		string s;
		for (int j = 0; j < n; j += 2) {
			auto it = begin(t);
			s += it->first;
			it->second -= 2;
			if (it->second == 0) {
				t.erase(it);
			}
		}
		printf(s.c_str());
		reverse(begin(s), end(s));
		printf(s.c_str());
		puts(" ");
		return 0;
	}

	for (; !(n%k == 0 && (n/k)%2 == 1); k += 2) {
		auto it = begin(t);
		mids.push_back(it->first);
		mids.push_back(it->first);
		it->second -= 2;
		if (it->second == 0) {
			t.erase(it);
		}
	}
	int m = n/k;
	printf("%d\n", k);
	for (int i = 0; i < k; i++) {
		string s;
		for (int j = 1; j < m; j += 2) {
			auto it = begin(t);
			s += it->first;
			it->second -= 2;
			if (it->second == 0) {
				t.erase(it);
			}
		}
		printf(s.c_str());
		printf("%c", mids[i]);
		reverse(begin(s), end(s));
		printf(s.c_str());
		printf(" ");
	}
	puts("");
	return 0;
}