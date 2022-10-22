    #include<bits/stdc++.h>
    using namespace std;
    char _;
    typedef long long ll;
    typedef pair<int,int> pii;
    typedef pair<ll,ll> pll;
    template <typename t> void scan (t& x) {do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);}
    template <typename t, typename ...r> void scan (t& x, r&... xs) {scan(x); scan(xs...);}
    const int MAXN = 2e5+2;
    ll p[MAXN];
    ll bit[MAXN];
    int a [MAXN];
    bool gone[MAXN];
    void update (int i, ll v) {
    	for (;i<MAXN;i+=i&-i)
    		bit[i] += v;
    }
    ll query (int i) {
    	ll ret = 0;
    	for (;i>0;i^=i&-i)
    		ret += bit[i];
    	return ret;
    }
    int main () {
    	int n;
    	scanf ("%d",&n);
    	for (int i = 1; i <= n; i++) update(i,i);
    	for (int i = 0; i < n; i++) scanf ("%lld",&p[i]);
    	int maxleft = n;
    	for (int i = n-1; i >= 0; i--) {
    		int low = 1, high = maxleft, ans;
    		while (low <= high) {
    			int mid = (low+high)>>1;
    			ll att = query(mid-1);
    			if (att > p[i]) high = mid-1;
    			else low = mid+1, ans = mid;
    		}
    		update(ans,-ans);
    		gone[ans] = 1;
    		while (gone[maxleft]) maxleft--;
    		a[i] = ans;
    	}
    	for (int i = 0; i < n; i++) printf ("%d ",a[i]);
    	printf ("\n");
    	return 0;
    }