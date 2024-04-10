#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

const ll max_n = 2e5;

ll n;
vector<ll>	vec;
ll cnt[max_n], d[max_n];

int main(){
	scanf("%I64d", &n);
	vec.resize(n);
	for (ll i = 0; i < n; i++){
		scanf("%I64d", &vec[i]);
		cnt[vec[i]]++;
	}
	sort(vec.begin(), vec.end());
	vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
	d[0] = vec[0] * cnt[vec[0]];
	for (ll i = 1; i < vec.size(); i++){
		if (vec[i] != vec[i - 1] + 1){
			d[i] = d[i - 1] + cnt[vec[i]] * vec[i];
			continue;
		}
		if (i == 1)
			d[i] = max(d[i - 1], cnt[vec[i]] * vec[i]);
		else
			d[i] = max(d[i - 1], cnt[vec[i]] * vec[i] + d[i - 2]);
	}
	printf("%I64d\n", d[vec.size() - 1]);
	return 0;
}