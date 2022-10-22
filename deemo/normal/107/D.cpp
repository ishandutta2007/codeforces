#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

typedef long long ll;

const ll MAX = 123 + 4;
const ll MOD = 12345;

struct Mat{
	ll v[MAX][MAX];
	Mat(ll x = 0){
		for (ll i = 0; i < MAX; i++)
			for (ll j = 0; j < MAX; j++)
				if (i == j)
					v[i][j] = x;
				else
					v[i][j] = 0;
	}
};

ll n, m;
vector<ll>	vec, gec;
vector<vector<ll>>	sec;
bool ok[30][200], mark[30];
ll save[30];
Mat adj, ans(1);

void generate(ll x){
	if (x == vec.size()){
		sec.push_back(gec);
		return;
	}

	for (ll i = 0; i < save[vec[x]]; i++){
		gec.push_back(i);
		generate(x + 1);
		gec.pop_back();
	}
}

void put_edges(){
	vector<ll>	temp;
	for (ll i = 0; i < sec.size(); i++){
		temp.assign(sec[i].begin(), sec[i].end());
		for (ll j = 0; j < temp.size(); j++){

			temp[j] = (temp[j] + 1) % save[vec[j]];
			for (ll w = 0; w < sec.size(); w++){
				bool fl = 1;
				for (ll q = 0; q < temp.size(); q++)
					if (temp[q] != sec[w][q]){
						fl = 0;
						break;
					}
				if (fl)
					adj.v[i][w] += 1;
			}
			temp[j] = (temp[j] + save[vec[j]] - 1) % save[vec[j]];

		}
	}		
}

Mat mul(Mat a, Mat b){
	Mat ret;
	for (ll i = 0; i < sec.size(); i++)
		for (ll j = 0; j < sec.size(); j++)
			for (ll w = 0; w < sec.size(); w++)
				ret.v[i][j] = (ret.v[i][j] + a.v[i][w] * b.v[w][j]) % MOD;
	return	ret;
}

void solve(){
	Mat t(1);
	while (n){
		if (n & 1)
			t = mul(adj, t);
		n >>= 1;
		adj = mul(adj, adj);
	}

	ans = mul(t, ans);
}

bool check(ll ind){
	vector<ll>	temp = sec[ind];
	for (ll i = 0; i < temp.size(); i++){
		ll t = temp[i];
		bool fl = 0;
		for (ll j = 0; j <= MAX; j++)
			if (ok[vec[i]][j] && t % j == 0)	fl = 1;
		if (!fl)	return	false;
	}
	return	true;
}

void show_Ans(){
	long long ret = 0;
	for (ll i = 0; i < sec.size(); i++)
		if (check(i))	ret = (ret + ans.v[0][i]) % MOD;
	printf("%I64d\n", (ll)ret);
}

int main(){
	scanf("%I64d%I64d", &n, &m);
	for (ll i = 0; i < m; i++){
		char c;	ll x;	scanf("%1s %I64d", &c, &x);
		c -= 'A';
		save[c] = max(save[c], ll(1)) * x;
		ok[c][x] = 1;
		vec.push_back(c);
	}
	sort(vec.begin(), vec.end());
	vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
	generate(0);
	put_edges();
	solve();
	show_Ans();
	return 0;
}