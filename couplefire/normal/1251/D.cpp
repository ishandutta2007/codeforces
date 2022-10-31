#include <bits/stdc++.h>

using namespace std;

const int N = int(2e5) + 99;
const int INF = int(1e9) + 100;

int t;
int n;
long long s;
pair<int, int> p[N];

bool ok(int mid){
	long long sum = 0;
	int cnt = 0;
	vector <int> v;
	for(int i = 0; i < n; ++i){
		if(p[i].second < mid)
			sum += p[i].first;
		else if(p[i].first >= mid){
			sum += p[i].first;
			++cnt;
		}
		else
			v.push_back(p[i].first);
	}

	assert(is_sorted(v.begin(), v.end()));
	
	int need = max(0, (n + 1) / 2 - cnt);
	if(need > v.size()) return false;
	for(int i = 0; i < v.size(); ++i){
		if(i < v.size() - need)
			sum += v[i];
		else
			sum += mid;
	}

	return sum <= s;
}

int main() {	
	scanf("%d", &t);
	for(int tc = 0; tc < t; ++tc){
		scanf("%d %lld", &n, &s);
		for(int i = 0; i < n; ++i)
			scanf("%d %d", &p[i].first, &p[i].second);
		
		sort(p, p + n);
		int lf = 1, rg = INF; ///WA -> 10^9
		while(rg - lf > 1){
			int mid = (lf + rg) / 2;
			if(ok(mid)) lf = mid;
			else rg = mid;
		}
		
		printf("%d\n", lf);
	}
	return 0;
}