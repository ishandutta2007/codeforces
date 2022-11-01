#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <iostream>

#define foreach(e, x) for(__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)

using namespace std;

vector<pair<int, int> > pairs;

int n;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		pair<int, int> t;
		scanf("%d %d", &t.first, &t.second);
		pairs.push_back(t);
	}
	sort(pairs.begin(), pairs.end());
	int last = 0;
	for(int i = 0; i < n; i++) {
		if (pairs[i].second >= last) {
			last = pairs[i].second;
		} else {
			last = pairs[i].first;
		}
	}
	cout << last << endl;
	return 0;
}