//Seperate..
//sifting through the wreckage 
//I can't concentrate 
//searching for a message in the fear and pain
//broken down and waiting for a chance to feel alive.. @_@'


#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

using namespace std;

typedef long long ll;

const ll max_n = 1e6 + 10;
const ll BASE = 71;

ll ans;
int n, m;
vector<int>	adj[max_n];
ll h[max_n];
ll	vec[max_n];
pair<int, int>	sec[max_n];
ll pw[max_n];

void init(){
	pw[0] = 1;
	for (int i = 1; i < max_n; i++)
		pw[i] = (pw[i - 1] * BASE);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < adj[i].size(); j++)
			h[i] += pw[adj[i][j]];
}

ll get(ll x){
	if (x < 2)	return	0;
	return	x * (x - 1) / 2;
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++){
		int a, b;	scanf("%d%d", &a, &b);	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
		sec[i] = {a, b};
	}
	init();
	copy(h, h + n, vec);
	sort(vec, vec + n);
	for (int i = 0; i < n;){
		int j = i;
		i++;
		while (i < n && (i == 0 || vec[i] == vec[i - 1]))	i++;
		ans += get(i - j);
	}		

	for (int i = 0; i < n; i++)
		h[i] += pw[i];

	for (int i = 0; i < m; i++)
		if (h[sec[i].first] == h[sec[i].second])
			ans++;
	cout << ans << endl;
	return 0;
}