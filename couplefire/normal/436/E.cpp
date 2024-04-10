#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 5e5 + 10;
const ll inf = 1e18;

multiset<int> asli, fare;
ll tot, mark[maxn];
pair<pair<int, int>, int> a[maxn];

bool cmp(pair<pair<int,int>, int> fi, pair<pair<int,int>, int> se){
	return fi.first.second < se.first.second;
}

void add(int x){
	asli.insert(x);
	tot += x;
}

void del(int x){
	if (asli.find(x) != asli.end()){
		tot -= x;
		asli.erase(asli.find(x));
	}
	else
		fare.erase(fare.find(x));
}

ll get(int n){
	if (asli.size() + fare.size() < n)
		return inf;
	while (asli.size() > n){
		auto it = asli.end();
		it --;
		tot -= *it;
		fare.insert(*it);
		asli.erase(it);
	}
	while (asli.size() < n){
		auto it = fare.begin();
		tot += *it;
		asli.insert(*it);
		fare.erase(fare.begin());
	}
	return tot;
}

int main(){
	int n, w;
	scanf("%d%d", &n, &w);
	for (int i = 1; i <= n; i++){
		scanf("%d%d", &a[i].first.first, &a[i].first.second);
		a[i].second = i;
	}
	sort(a + 1, a + n + 1);
	sort(a + 1, a + n + 1, cmp);
	for (int i = n; i >= 1; i--)
		add(a[i].first.first);
	ll answer = inf;
	ll sum = 0, idx = -1;
	for (int i = 1; i <= min(w - 1, n); i++){
		del(a[i].first.first);
		if (answer > a[i].first.second + get(w - i - 1) + sum){
			answer = a[i].first.second + get(w - i - 1) + sum;
			idx = i;
		}
		sum += a[i].first.first;
		add(a[i].first.second - a[i].first.first);
	}
	if (w <= n){
		sort(a + 1, a + n + 1);
		ll now = 0;
		for (int i = 1; i <= w; i++)
			now += a[i].first.first;
		if (now <= answer){
			printf("%lld\n", now);
			for (int i = 1; i <= w; i++)
				mark[a[i].second] = 1;
			for (int i = 1; i <= n; i++)
				printf("%lld", mark[i]);
			return 0;
		}
		sort(a + 1, a + n + 1, cmp);
	}
	asli.clear();
	fare.clear();
	for (int i = 1; i < idx; i++){
		add(a[i].first.second - a[i].first.first);
		mark[a[i].second] = 1;
	}
	mark[a[idx].second] = 2;
	for (int i = idx + 1; i <= n; i++)
		add(a[i].first.first);
	get(w - idx - 1);
	for (int i = 1; i < idx; i++){
		if (asli.find(a[i].first.second - a[i].first.first) != asli.end()){
			mark[a[i].second] = 2;
			asli.erase(asli.find(a[i].first.second - a[i].first.first));
		}
	}
	for (int i = idx + 1; i <= n; i++){
		if (asli.find(a[i].first.first) != asli.end()){
			mark[a[i].second] = 1;
			asli.erase(asli.find(a[i].first.first));
		}
	}
	printf("%lld\n", answer);
	for (int i = 1; i <= n; i++)
		printf("%lld", mark[i]);
}