#include <cstdio>
#include <cassert>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

#define fori(i,s,e) for(int i = s; i < ((int)e); i++)
#define scan_d(x) scanf("%d", &(x))

int n;
map<int,int> freq;
vector<int> res;

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int main() {
	scan_d(n);
	fori (i, 0, n*n) {
		int x;
		scan_d(x);
		freq[x]++;
	}
	fori (i, 0, n) {
		pair<int,int> p = *(freq.rbegin());
		int m = p.first;
		for (int r : res) {
			int g = gcd(r, m);
			assert(freq[g] >= 2);
			freq[g] -= 2;
			if (freq[g] == 0) freq.erase(g);
		}
		res.push_back(m);
		assert(freq[m] >= 1);
		freq[m] -= 1;
		if (freq[m] == 0) freq.erase(m);
	}
	for (int x : res) printf("%d ", x);
}