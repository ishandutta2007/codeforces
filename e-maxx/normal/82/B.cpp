#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;


int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	int n;
	cin >> n;
	int m = n * (n-1) / 2;
	vector < set<int> > a (m);
	for (int i=0; i<m; ++i) {
		int s;
		scanf ("%d", &s);
		for (int j=0; j<s; ++j) {
			int x;
			scanf ("%d", &x);
			a[i].insert (x);
		}
	}

	if (n == 2) {
		int x = *a[0].begin();
		printf ("1 %d\n", x);
		vector<int> v (++a[0].begin(), a[0].end());
		printf ("%d", v.size());
		for (size_t i=0; i<v.size(); ++i)
			printf (" %d", v[i]);
		puts("");
		return 0;
	}

	vector<char> u (m);
	for (int i=0; i<m; ) {
		if (u[i]) { ++i;  continue;}

		int num = *a[i].begin();
		vector<int> cans;
		for (int j=i+1; j<m; ++j) {
			if (u[j])  continue;
			if (a[j].count (num)) {
				for (set<int>::iterator it=a[i].begin(); it!=a[i].end(); ++it)
					if (a[j].count (*it))
						cans.push_back (*it);
				break;
			}
		}

		if (cans.empty())
			cans = vector<int> (a[i].begin(), a[i].end());

		printf ("%d", cans.size());
		for (size_t j=0; j<cans.size(); ++j)
			printf (" %d", cans[j]);
		puts("");

		for (int j=i; j<m; ++j) {
			if (u[j])  continue;
			if (!a[j].count (num))  continue;
			for (size_t k=0; k<cans.size(); ++k)
				a[j].erase (cans[k]);
			if (a[j].empty())
				u[j] = true;
		}
	}

}