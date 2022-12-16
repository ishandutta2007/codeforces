#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll INF = 0x3f3f3f3f3f3f3f3fLL;

inline ll cs(int n)
{
	ll ans = 0;
	ll cv = 1;
	for(int i=0;i<n;++i)
	{
		ans += cv;
		cv = cv*4;
		if(ans >= INF) return INF;
	}
	return ans;
}

inline ll wrd(int n)
{
	ll ans = 0;
	for(int i=1;i<=n;++i)
	{
		ans += (1LL<<i)-1;
		if(ans >= INF) return INF;
	}
	return ans;
}

inline ll mult(ll x, ll y)
{
    ll ans = 0;
    int aa = __builtin_clzll(x) + __builtin_clzll(y);
    aa = 128-aa;
    //cerr << " aa = " << aa << " from " << x << " " << y << endl;
    if(aa > 60) {
        return INF;
    }
    return min(INF, x*y);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TT;
    cin >> TT;
    while(TT--)
    {
        ll n, k;
        cin >> n >> k;
        bool good = false;
        ll ans = 0;
        for(int i=1; i <= n;++i)
        {
            ll minCut = wrd(i);
            if(minCut >= INF) break;
            if(minCut > k)
            {
                break;
            }
            ll maxCut = wrd(i);
            for(int j=2;j<i+2;++j)
            {
                //cerr << " cs of " << n-j+1 << " is " << cs(n-j+1)<< endl;
                maxCut += mult((1LL<<j)-3, cs(n-j+1));
                maxCut = min(maxCut, INF);
            }
            //cerr << " FOR " << i << " we get " << minCut << " to " << maxCut << " vs " << k << " and INF is " << INF << endl;
            if(minCut <= k && maxCut >= k)
            {
                good = true;
                ans = n-i;
                break;
            }
        }
        if(good){
            cout << "YES " << ans << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}