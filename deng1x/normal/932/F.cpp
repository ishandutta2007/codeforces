#include<bits/stdc++.h>

typedef long long ll;
const ll INF = LLONG_MAX;
inline ll divide(ll a, ll b){return a / b - ((a ^ b) < 0 && a % b);}

class L{
public:
	static bool isquery;
	mutable ll k, b, p;
	L (ll k = 0, ll b = 0, ll p = 0):k(k), b(b), p(p){}
	bool operator < (const L &l)const{return isquery ? p < l.p : k < l.k;}
	ll gety(ll x)const{return k * x + b;}
};
bool L::isquery = false;

typedef std::multiset <L>::iterator iter;

bool over(std::multiset <L> &set, iter l1, iter l2){
	if (l2 == set.end()) return l1 -> p = INF, false;
	if (l1 -> k == l2 -> k) l1 -> p = l1 -> b > l2 -> b ? INF : -INF;
	else l1 -> p = divide(l2 -> b - l1 -> b, l1 -> k - l2 -> k);
	return l1 -> p >= l2 -> p;
}

void insert(std::multiset <L> &set, ll k, ll b){
	auto u = set.insert(L (k, b)), v = u ++, w = v;
	while (over(set, v, u)) u = set.erase(u);
	if (v != set.begin() && over(set, -- w, v)) over(set, w, set.erase(v));
	while ((v = w) != set.begin() && (-- w) -> p >= v -> p) over(set, w, set.erase(v));
}

ll query(std::multiset <L> &set, ll x){
	L::isquery = true;
	auto u = *(set.lower_bound(L (0, 0, x)));
	L::isquery = false;
	return u.gety(x);
}

const int N = 100010;

std::multiset <L> set[N];
ll a[N], b[N], sit[N], sz[N];
ll dp[N];
std::vector <int> e[N];

void dfs(int u, int fa){
	sz[u] = 1;
	int max = 0, ssit = 0;
	for (auto v : e[u]){
		if (v == fa) continue;
		dfs(v, u);
		sz[u] += sz[v];
		if (sz[v] > max){
			max = sz[v];
			ssit = v;
		}
	}
	if (ssit){
		sit[u] = sit[ssit];
		for (auto v : e[u]){
			if (v == fa || v == ssit) continue;
			for (auto w : set[sit[v]]){
				insert(set[sit[u]], w.k, w.b);
			}
		}
		dp[u] = -query(set[sit[u]], a[u]);
	}
	else{
		sit[u] = u;
	}
	insert(set[sit[u]], -b[u], -dp[u]);
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i){
		scanf("%I64d", &a[i]);
	}
	for (int i = 1; i <= n; ++ i){
		scanf("%I64d", &b[i]);
	}
	for (int i = 0, u, v; i < n - 1; ++ i){
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; ++ i){
		printf("%I64d%c", dp[i], " \n"[i == n]);
	}
	return 0;
}