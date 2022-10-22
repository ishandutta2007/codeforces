//I had to fall, to lose it all
//but in the end it doesn't even matter..

#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const int max_n = 8 + 2;

int n, m, ans = 1000, fl;
vector<ll>	vec;
vector<ll>	sec[max_n];
vector<int>	child[max_n];

void get(int ind){
	if (ind >= n){
		int ret = fl + bool(fl > 1);
		for (int i = 0; i < n; i++){
			ret += child[i].size();
			ll t = sec[i].size(), x = 1;
			for (int j:child[i]){
				x *= vec[j];
				t -= sec[j].size();
				if (x > vec[i])	return;
			}
			if (vec[i] % x)	return;
			ret += t;
		}
		ans = min(ans, ret - m);
		return;
	}

	for (int i = -1; i < ind; i++){
		if (i == -1)	fl++;
		if (i != -1)	child[i].push_back(ind);
		get(ind + 1);

		if (i != -1)	child[i].pop_back();
		if (i == -1)	fl--;
	}
}

int main(){
	scanf("%d", &n);
	vec.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &vec[i]);
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++){
		ll temp = vec[i];
		for (ll j = 2; temp != 1; j++){
			if (j * j > temp){
				sec[i].push_back(temp);
				break;
			}
			while (temp % j == 0){
				temp /= j;
				sec[i].push_back(j);
			}
		}
		if (sec[i].size() == 1)	m++;
	}
	get(0);
	printf("%d\n", ans);
	return 0;
}