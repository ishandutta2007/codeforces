#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>

using namespace std;

typedef long long ll;

ll n, m, k;
vector<vector<ll>>	vec;
multiset<ll>	st[8];

ll get_max(){
	set<ll>::iterator it;
	
	ll sum = 0;
	for (ll j = 0; j < m; j++){
		it = st[j].end();
		it--;
		sum += *it;
	}
	return	sum;
}

int main(){
	scanf("%I64d%I64d%I64d", &n, &m, &k);
	vec.resize(n);
	for (ll i = 0; i < n; i++){
		vec[i].resize(m);
		for (ll j = 0; j < m; j++)
			scanf("%I64d", &vec[i][j]);
	}
	
	ll l = 0, r = 0, ansl = -1, ansr = -1;
	for (ll i = 0; i < n; i++){
		for (ll j = 0; j < m; j++)
			st[j].insert(vec[i][j]);
		r++;	
	
		while (l < r && get_max() > k){
			for (ll j = 0; j < m; j++)
				st[j].erase(st[j].find(vec[l][j]));
			l++;
		}

		if (r != l)
			if (r - l > ansr - ansl){
				ansr = r;
				ansl = l;
			}
	}

	if (ansl == ansr){
		for (ll i = 0; i < m; i++)
			printf("0 ");
		printf("\n");
		return 0;
	}

	for (ll i = 0; i < m; i++)
		st[i].clear();
	
	for (ll i = ansl; i < ansr; i++)
		for (ll j = 0; j < m; j++)
			st[j].insert(vec[i][j]);
	
	for (ll i = 0; i < m; i++){
		set<ll>::iterator it = st[i].end();
		it--;
		printf("%I64d ", *it);
	}
	printf("\n");

	return 0;
}