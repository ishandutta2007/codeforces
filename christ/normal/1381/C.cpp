    #include<bits/stdc++.h>
    using namespace std;
    using pii = pair<int,int>;
    using ll = long long;
    using pll = pair<ll,ll>;
    using pli = pair<ll,int>;
    using pil = pair<int,ll>;
    using ld = long double;
    using ui = unsigned int;
    using ull = unsigned long long;
    using ui128 = __uint128_t;
    using pvi = pair<vector<int>,int>;
    #define all(x) (x).begin(),(x).end()
    #define mp make_pair
    #define setio(x) freopen(x ".in","r",stdin); freopen(x ".out","w",stdout)
    const int MN = 1e5 + 2, LOG = 17, INF = 1e8, MOD = 998244353, BASE = 131;
    void solve () {
    	int n,x,y;
    	scanf ("%d %d %d",&n,&x,&y);
    	vector<int> b(n+1), freq(n+2), match(n+2);
    	for (int i = 1; i <= n; i++) {
    		scanf ("%d",&b[i]), ++freq[b[i]];
    	}
    	int emp = 0; set<pii> big;
    	for (int i = 0; i <= n+1; i++) {
    		if (freq[i] == 0) emp = i;
    		else big.insert({freq[i],i});
    	}
    	for (int _i = 0; _i < x; _i++) {
    		int take = big.rbegin()->second;
    		big.erase(prev(big.end()));
    		--freq[take]; ++match[take];
    		if (freq[take]) big.insert({freq[take],take});
    	}
    	int mxfreq = big.empty() ? 0 : big.rbegin()->first, ext = min(n-x,2 * (n-x-mxfreq));
    	y -= x;
    	if (ext < y || y < 0) return (void) printf ("NO\n");
    	vector<int> ans(n+1); vector<pvi> where(n+2);
    	for (int i = 0; i <= n+1; i++) where[i].second = i;
    	for (int i = 1; i <= n; i++) {
    		if (match[b[i]]-- > 0) ans[i] = b[i];
    		else where[b[i]].first.push_back(i);
    	}
    	sort(where.begin(),where.end(),[](const pvi &a, const pvi &bb) {return a.first.size() > bb.first.size();});
    	int p1 = 0, p2 = 1; vector<int> left(n+2);
    	for (int i = 0; i <= n+1;i++)left[i]=(int)where[i].first.size();
    	for (int i = 0; i < y; i++) {
    		if (where[p1].first.empty()) p1++;
    		assert(!(int)where[p1].first.empty());
    		if (p2 && !left[p2]) p2++;
    		if (!left[p2]) p2 = 0;
    		if (p1 == p2) ++p1;
    		int pos = where[p1].first.back(); where[p1].first.pop_back();
    		int cur2 = where[p2].second; --left[p2];
    		ans[pos] = cur2;
    	}
    	for (int i = 1; i <= n; i++) if (!ans[i]) ans[i] = emp;
    	int cnt1 = 0, cnt2 = 0;
    	for (int i = 1; i <= n; i++) if (ans[i] == b[i]) ++cnt1;
    	vector<int> freq1(n+2), freq2(n+2);
    	for (int i = 1; i <= n; i++) freq1[ans[i]]++, freq2[b[i]]++;
    	for (int i = 0; i <= n+1; i++) cnt2 += min(freq1[i],freq2[i]);
    	cnt1 = x; cnt2 = x+y;
    	if (cnt1 != x || cnt2 != x+y) printf ("NO\n");
    	else {
			printf ("YES\n");
			for (int i = 1; i <= n; i++) printf ("%d%c",ans[i]," \n"[i==n]);
		}
		assert(cnt1 == x && cnt2 == x+y);
    }
    int main () {
    	int tt;
    	scanf ("%d",&tt);
    	while (tt--) solve();
    	return 0;
    }
    //once you have matched some, # of extra you can take is min(n,2*(n - maxfreq))
    //therefore we want to minimize maxfreq...