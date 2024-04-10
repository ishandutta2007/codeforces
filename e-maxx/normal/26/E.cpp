#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


void no() {
	cout << "No";
	exit (0);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	int n, w;
	cin >> n >> w;
	vector<int> a (n);
	int sum = 0;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		sum += a[i];
	}

	if (w > sum || w < 0)
		no();

	vector<int> p (n);

	vector<int> ans;
	if (n == 1) {
		if (w == sum)
			for (int i=0; i<w*2; ++i)
				ans.push_back (0);
		else
			no();
	}
	else {
		int x = int (min_element (a.begin(), a.end()) - a.begin()),
			y = x ? 0 : 1;
		if (w >= a[x]) {
			ans.push_back (x);
			int ptr = 0;
			for (int i=0; i<sum-w; ++i) {
				while (ptr==x || p[ptr]==a[ptr])
					++ptr;
				ans.push_back (ptr);
				ans.push_back (ptr);
				++p[ptr];
			}
			for (int i=0; i<a[x]*2-1; ++i)
				ans.push_back (x);
			for (;;) {
				while (ptr<n && (ptr==x || p[ptr]==a[ptr]))
					++ptr;
				if (ptr == n)  break;
				ans.push_back (ptr);
				ans.push_back (ptr);
				++p[ptr];
			}
		}
		else {
			if (w < 2)  no();

			ans.push_back (x);
			int ptr = 0;
			--a[y];
			for (;;) {
				while (ptr<n && (ptr==x || p[ptr]==a[ptr]))
					++ptr;
				if (ptr == n)  break;
				ans.push_back (ptr);
				ans.push_back (ptr);
				++p[ptr];
			}
			ans.push_back (x);
			++p[x];
			for (int i=0; i<w-2; ++i) {
				ans.push_back (x);
				ans.push_back (x);
				++p[x];
			}
			ans.push_back (y);
			while (p[x] < a[x]) {
				ans.push_back (x);
				ans.push_back (x);
				++p[x];
			}
			ans.push_back (y);
		}
	}

	puts ("Yes");
	for (int i=0; i<(int)ans.size(); ++i)
		printf ("%d ", ans[i]+1);

}