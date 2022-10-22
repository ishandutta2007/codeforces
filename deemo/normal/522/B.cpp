#include<cstdio>
#include<vector>
#include<cmath>
#include<utility>

using namespace std;

const int max_n = 3e5 + 50;
const int INF = 2e9 + 1;

int n, sum;
vector<pair<int, int>>	vec;
vector<int>	l, r;

int main(){
	scanf("%d", &n);
	vec.resize(n);
	l.resize(n + 2);
	r.resize(n + 2);
	l[0] = 0;
	r[n] = 0;
	for (int i = 0; i < n; i++){
		scanf("%d%d", &vec[i].first, &vec[i].second);	
		sum += vec[i].first;
		l[i + 1] = max(vec[i].second, l[i]);
	}
	for (int i = n - 1; i >= 0; i--)
		r[i] = max(r[i + 1], vec[i].second);
	
	for (int i = 0; i < n; i++){
		int a = sum - vec[i].first;
		int b = max(l[i], r[i + 1]);
		printf("%d\n", a * b);
	}
	return 0;
}