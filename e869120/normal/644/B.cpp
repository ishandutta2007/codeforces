#include<iostream>
#include<queue>
#include<vector>
#include<functional>
#include<tuple>
using namespace std;
long long n, b, t[300000], d[300000], e[300000], U, G;
priority_queue<tuple<long long, long long, long long>, vector<tuple<long long, long long, long long>>, greater<tuple<long long, long long, long long>>>Q;
int main() {
	cin >> n >> b;
	for (long long i = 0; i < n; i++) { cin >> t[i] >> d[i]; Q.push(make_tuple(t[i], 1, i)); }
	while (!Q.empty()) {
		tuple<long long, long long, long long>tup = Q.top(); Q.pop();
		if (get<1>(tup) == 1) {
			if (U == b + 1)e[get<2>(tup)] = -1;
			else {
				U++; Q.push(make_tuple(max(G, get<0>(tup)) + d[get<2>(tup)], 0, get<2>(tup)));
				G = max(G, get<0>(tup)) + d[get<2>(tup)];
			}
		}
		if (get<1>(tup) == 0) { e[get<2>(tup)] = get<0>(tup); U--; }
	}
	for (long long i = 0; i < n; i++) { if (i)printf(" "); printf("%lld", e[i]); }cout << endl;
	return 0;
}