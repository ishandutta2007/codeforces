#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair <ll, ll>;

random_device rd;
mt19937 rng(rd());

vector <tuple <char, ll, ll>> Q;
vector <pll> P;
set <ll> S;
vector <ll> V, B(62), L;
vector <bool> chk;

void dfs(int t)
{
	chk[t] = 1;
	if(!t) return;
	if(!chk[P[t].first]) dfs(P[t].first);
	if(!chk[P[t].second]) dfs(P[t].second);
	Q.emplace_back('+', V[P[t].first], V[P[t].second]);
}

void test(ll x)
{
	Q.clear(); P.clear(); S.clear(); V.clear(); L.clear();
	B = vector <ll> (62);
	
	S.insert(0);
	V.push_back(x); P.emplace_back(0, 0); S.insert(x);

	ll a, b, aa, bb, t, i;

	for(; ; ){
		aa = rng() % V.size(); a = V[aa];
		bb = rng() % V.size(); b = V[bb];
		if(a + b <= 4e18 && S.find(a + b) == S.end()){
			S.insert(a + b);
			V.push_back(a + b);
			P.emplace_back(aa, bb);
//			Q.emplace_back('+', a, b);
			for(t = a + b, i = 61; i > 0; i --){
				if(t & 1ll << i){
					if(B[i]){
//						Q.emplace_back('^', t, B[i]);
						t ^= B[i];
					}
					else {
						B[i] = t; L.push_back(V.size() - 1);
						break;
					}
				}
			}
			if(t == 1){
				L.push_back(V.size() - 1);
				break;
			}
		}
	}

	chk = vector <bool> (V.size());
	B = vector <ll> (62);

	for(auto &t: L){
		dfs(t); t = V[t];
		for(i = 61; i > 0; i --){
			if(t & 1ll << i){
				if(B[i]){
					Q.emplace_back('^', B[i], t);
					t ^= B[i];
				}
				else{
					B[i] = t;
					break;
				}
			}
		}
		if(t == 1) break;
	}
//	if(Q.size() > 100000) cout << "!" << x << endl;


	cout << Q.size() << "\n";
	for(auto &[o, a, b]: Q){
		cout << a << " " << o << " " << b << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
/*
	int i;

	for(i = 3; i <= 999999; i += 2){
		test(i);
	}
*/
	ll n; cin >> n; test(n);

	return 0;
}