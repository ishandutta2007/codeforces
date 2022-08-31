/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 10;

struct S {
	int a, ind;
	ll t;
	bool operator<(const S &other) const {
		return a < other.a;
	}
} p[N];

class ComparisonClass {
public:
    bool operator() (S &l, S &r) {
    	return l.t < r.t;
    }
};

bool check(int k, int n, ll T);

int main() {
	fast_cin();
	int n; ll T;
	cin >> n >> T;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i].a >> p[i].t;
		p[i].ind = i;
	}

	int j = n; ll sum = 0;
	priority_queue <S, vector <S>, ComparisonClass> q;
	sort(p + 1, p + 1 + n);
	for (int k = n; k >= 0; --k) {
		// cout << k << endl;
		while (j and p[j].a >= k) {
			sum += p[j].t;
			q.push(p[j]);
			--j;
		}

		if (q.size() < k) {
			continue;
		}

		while (!q.empty() and q.size() > k) {
			sum -= q.top().t;
			q.pop();
		}

		if (sum <= T) {
			cout << k << endl << k << endl;
			while (!q.empty()) {
				cout << q.top().ind << ' ';
				q.pop();
			}

			break;
		}
	}
}