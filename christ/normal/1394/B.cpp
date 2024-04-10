    #include <bits/stdc++.h>
    using namespace std;
    using ll = long long;
    using ull = unsigned long long;
    using pii = pair<int,int>;
    using pll = pair<ll,ll>;
    using ld = long double;
    #define all(x) (x).begin(),(x).end()
    const int MN = 2e5 + 5, MOD = 1e9 + 7;
    vector<pii> adj[MN];
    bitset<MN> bb[10][10];
    unordered_map<bitset<MN>,int> cntA, cntB;
    int deg[MN];
    int main () {
    	int n,m,k;
    	scanf ("%d %d %d",&n,&m,&k);
    	while (m--) {
    		int a,b,c;
    		scanf ("%d %d %d",&a,&b,&c);
    		adj[a].emplace_back(b,c);
    		++deg[a];
    	}
    	for (int i = 1; i <= n; i++) {
    		sort(all(adj[i]),[](pii a, pii b){return a.second < b.second;});
    		for (int j = 0; j < deg[i]; j++) bb[deg[i]][j+1].set(adj[i][j].first);
    	}
    	bitset<MN> mask;
    	for (int i = 1; i <= n; i++) mask.set(i);
    	function<void(int,bitset<MN>&)> gen = [&] (int cur, bitset<MN> &bs) {
    		if (cur > k || cur > 6) {
    			cntA[bs]++;
    			return;
    		}
    		for (int take = 1; take <= cur; take++) if (!(bs&bb[cur][take]).count()){
    			bs |= bb[cur][take];
    			gen(cur+1,bs);
    			bs &= (mask ^ bb[cur][take]);
    		}
    	};
    	function<void(int,bitset<MN>&)> gen2 = [&] (int cur, bitset<MN> &bs) {
    		if (cur > k) {
    			cntB[bs]++;
    			return;
    		}
    		for (int take = 1; take <= cur; take++) if (!(bs&bb[cur][take]).count()){
    			bs |= bb[cur][take];
    			gen2(cur+1,bs);
    			bs &= (mask ^ bb[cur][take]);
    		}
    	};
    	bitset<MN> bs;
    	gen(1,bs);
    	if (k <= 6) {
    		int ret = 0;
    		for (auto &au : cntA) if (au.first == mask) ret += au.second;
    		return !printf ("%d\n",ret);
    	}
    	assert(!bs.count());
    	gen2(7,bs);
    	ll ret = 0;
    	for (auto &au : cntB) {
    		bitset<MN> need = mask ^ au.first;
    		if (cntA.count(need)) ret += (ll)au.second * cntA[need];
    	} 
    	printf ("%lld\n",ret);
    	return 0;
    }