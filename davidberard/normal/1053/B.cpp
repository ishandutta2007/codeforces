#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct segtree
{
	vector<int> t;
	int n, h;
	segtree(vector<int> v)
	{
		int sz = v.size();
		h = sizeof(int)*8 - __builtin_clz(sz);
		n = 1 << h;
		t = vector<int>(n<<1, 0);
		for(int i=0;i<v.size();++i)
		{
			t[i+n] = v[i];
		}
	}
	int query(int l, int r)
	{
		int ans = 0;
		for(l+=n, r+=n;l<r;l/=2, r/=2)
		{
			if(l&1) ans = max(ans, t[l++]);
			if(r&1) ans = max(ans, t[--r]);
		}
		return ans;
	}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	vector<int> v, pfx, nxtbig, epfx;
	int N;
	scanf("%I64d", &N);
	v.resize(N);
	for(auto& x : v) {
		ll l;
		scanf("%I64d", &l);
		x = __builtin_popcountll(l);
	}
	//cerr;for(auto& x : v) //cerr << " " << x; //cerr << endl;
	pfx.resize(N+1);
	epfx.resize(N+1); // how many prefixes are even
	pfx[0] = 0;
	epfx[0] = 0;
	for(int i=0;i<N;++i)
	{
		pfx[i+1] = pfx[i]+v[i];
		epfx[i+1] = epfx[i] + (pfx[i+1]%2 == 0);
	}
	nxtbig.resize(N);
	vector<int> aa(64, N);
	for(int i=N-1;i>=0;--i)
	{
		nxtbig[i] = aa[v[i]];
		for(int j=0;j<v[i];++j)
		{
			aa[j] = i;
		}
	}
	ll ans = 0;
	for(int i=0;i<N;++i)
	{
		for(int p=i;p<N;p=nxtbig[p])
		{
			auto it = lower_bound(pfx.begin(), pfx.end(), pfx[i] + v[p]*2);
			int lb = max((int) (it-pfx.begin())-1, p);
			int ub = max(nxtbig[p], lb);
			assert(lb < N+1);
			assert(ub < N+1);
			//cerr << " FOR " << p << " aka " << lg[p] << " WE HAVE lb " << lb << " AND ub " << ub << " which corresponds to " << lg[p+1] << endl;
			int amt = epfx[ub]-epfx[lb];
			//cerr << "  amt " << amt << endl;
			//cerr << "pfx[i]%2 == 0 : " << pfx[i]%2 << " ub lb amt " << ub << " " << lb << " " << amt << " : " << ub-lb-amt<< endl;
			amt = (pfx[i]%2 == 0 ? amt : ub-lb - amt);
			//cerr << "  amt " << amt << endl;
			ans += amt;
		}
		//cerr << endl;
	}
	cout << ans << endl;
	return 0;
}