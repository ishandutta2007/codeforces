#include<bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ri(x) scanf("%d",&(x))
#define ri2(x,y) scanf("%d %d",&(x),&(y))
#define ri3(x,y,z) scanf("%d %d %d",&(x),&(y),&(z))
#define rll(x) scanf("%lld",&(x))
#define rll2(x,y) scanf("%lld %lld",&(x),&(y))
#define rll3(x,y,z) scanf("%lld %lld %lld",&(x),&(y),&(z))
#define gc(x) ((x) = getchar())
using namespace::std;
 
const long double PI = acos(-1);
const long long MOD = 1000000000 +7;
 
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> tll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<tll> vtll;
typedef vector<string> vs;
typedef set<int> si;
typedef set<ii> sii;
typedef set<iii> siii;
 
ll gcd(ll a, ll b){ return b==0?a:gcd(b,a%b);}
 
ll add(ll a, ll b, ll m = MOD){
	if(a >= m) a %= m;
	if(b >= m) b %= m;
	if(a < 0) a += m;
	if(b < 0) b += m;
	ll res = a+b;
	if(res >= m or res <= -m) res %= m;
	if(res < 0) res += m;
	return res;
}
 
ll mul(ll a, ll b, ll m = MOD){
	if(a >= m) a %= m;
	if(b >= m) b %= m;
	if(a < 0) a += m;
	if(b < 0) b += m;
	ll res = a*b;
	if(res >= m or res <= -m) res %= m;
	if(res < 0) res += m;
	return res;
}
 
ll pow_mod(ll a, ll b, ll m = MOD){
	ll res = 1LL;
	a = a%m;
	while(b){
		if(b&1) res = mul(res,a,m);
		b >>= 1;
		a = mul(a,a,m);
	}
	return res;
}
 
ll fastexp(ll a, ll b){
	ll res = 1LL;
	while(b){
		if(b&1) res = res*a;
		b >>= 1;
		a *= a;
	}
	return res;
}
 
int gcdExtendido(int a, int b, int *x, int *y){
	if(a == 0){
		*x = 0;
		*y = 1;
		return b;
	}
	int x1, y1;
	int gcd = gcdExtendido(b%a,a,&x1,&y1);
	
	*x = y1-(b/a)*x1;
	*y = x1;
	return gcd;
}
 
int modInverso(int a, int m){
	int x, y;
	int g = gcdExtendido(a,m,&x,&y);
	if(g!=1) return -1;
	else return (x%m + m)%m;
}
 
/****************************************
*************P*L*A*N*T*I*L*L*A************
*****************************************/
 
const int SUML = 300000 + 5;
const int E = 26;
 
int n;
int q;
int nodes;
int a[SUML];
char s[SUML];
int sup[SUML];
int suf[SUML];
int cur[SUML];
int pat[SUML];
int go[SUML][E];
set<ii> val[SUML];
 
void insert(int npat){
	int pos = 0;
	for(int i = 0; s[i]; i++){
		int nxt = s[i] - 'a';
		if(go[pos][nxt] == 0){
			cur[nodes] = -1;
			go[pos][nxt] = nodes++;
		}
		pos = go[pos][nxt];
	}
	pat[npat] = pos;
	cur[pos] = 0;
	val[pos].emplace(mp(0, npat));
}
 
void BFS(int src){
	queue<int> Q;
	Q.emplace(src);
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		sup[u] = suf[u] ? (val[suf[u]].empty() ? sup[suf[u]] : suf[u]) : 0;
		for(int e = 0; e < E; e++){
			if(go[u][e]){
				int v = go[u][e];
				suf[v] = u ? go[suf[u]][e] : 0;
				Q.emplace(v);
			}
			else{
				go[u][e] = u ? go[suf[u]][e] : 0;
			}
		}
	}
}
 
void buildAutomaton(int npat){
	nodes = 1;
	for(int i = 1; i <= npat; i++){
		scanf("%s", s);
		insert(i);
	}
	BFS(0);
}
 
void update(int i, int x){
	int pos = pat[i];
	int before = a[i];
	val[pos].erase(mp(before, i));
	a[i] = x;
	val[pos].emplace(mp(a[i], i));
	cur[pos] = (*val[pos].rbegin()).first;
}
 
int getAns(int state){
	int res = -1;
	while(state > 0){
		res = max(res, cur[state]);
		state = sup[state];
	}
	return res;
}
 
int solve(){
	int res = -1;
	int state = 0;
	for(int i = 0; s[i]; i++){
		int nxt = s[i] - 'a';
		state = go[state][nxt];
		res = max(res, getAns(state));
	}
	return res;
}
 
int main(){
	ri2(n, q);
	buildAutomaton(n);
	while(q--){
		int op;
		ri(op);
		if(op == 1){
			int i, x;
			ri2(i, x);
			update(i, x);
		}
		else{
			scanf("%s", s);
			printf("%d\n", solve());
		}
	}
	return 0;
}