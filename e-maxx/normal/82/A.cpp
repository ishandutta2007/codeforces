#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;


string a[] = {
	"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"
};

int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	int n;
	cin >> n;

	vector < pair<int,long long> > q;
	for (int i=0; i<5; ++i)
		q.push_back (make_pair (i, 1));

	for(;;) {
		if (q[0].second >= n) {
			cout << a[q[0].first] << endl;
			return 0;
		}
		n -= q[0].second;
		q.push_back (make_pair (q[0].first, q[0].second*2));
		q.erase (q.begin());
	}

}