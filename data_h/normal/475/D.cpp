#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int N = 111111;

vector<pair<int, int > > vec;
int n;
int a[N];
map<int, long long> answer;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = n; i >= 1; i--) {
		for(int j = 0; j < (int)vec.size(); j++) {
			vec[j].first = __gcd(vec[j].first, a[i]);
		}
		vec.push_back(make_pair(a[i], 1));
		vector<pair<int, int> > temp;
		for(int j = 0; j < (int)vec.size(); j++) {
			if (temp.size() && temp.back().first == vec[j].first) {
				temp.back().second += vec[j].second;
			} else {
				temp.push_back(vec[j]);
			}
		}
		vec = temp;
		for(int j = 0; j < (int)vec.size(); j++) {
			answer[vec[j].first] += vec[j].second;
		}
	}
	int m;
	scanf("%d", &m);
	for(int i = 1; i <= m; i++) {
		int x;
		scanf("%d", &x);
		printf("%I64d\n", answer[x]);
	}
	return 0;
}