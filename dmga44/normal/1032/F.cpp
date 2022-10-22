#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MOD = 998244353;

struct COMBINATORIAL_SET
{
    typedef long long ll;

    ll MOD;

    ll sz;

    vector<ll> _fact, _inum, _ifact, _pw2;

    vector<vector<ll>> _dp, _stirling1, _stirling2, _pascal;

    ll _update_dp_value;
    bool _update_dp_value_flag;

    COMBINATORIAL_SET(ll m)
    {
        MOD = m;
        sz = 1;
        _fact = {1,1};
        _inum = {0,1};
        _ifact = {1,1};
        _pw2 = {1};
        _dp = {{1}};
        _stirling1 = {{1}};
        _stirling2 = {{1}};
        _pascal = {{1}};
        _update_dp_value_flag = false;
        _update_dp_value = 0;
    }

    ll mod(ll x)
    {
        x %= MOD;
        if(x < 0)x += MOD;
        return x;
    }

    ll qpow(ll a, ll b)
    {
        a = mod(a);
        ll res = 1;
        while(b)
        {
            if(b&1)res = res*a%MOD;
            a = a*a%MOD;
            b >>= 1;
        }
        return res;
    }

    ll inv(ll x)
    {
        x = mod(x);
        if(x <= sz)return _inum[x];
        return qpow(x, MOD-2);
    }

    ll fact(int x)
    {
        update(x);
        return _fact[x];
    }

    ll inum(int x)
    {
        update(x);
        return _inum[x];
    }

    ll ifact(int x)
    {
        update(x);
        return _ifact[x];
    }

    void update(int n)
    {
        while(sz < n)
        {
            sz++;
            _fact.push_back(_fact.back()*sz%MOD);
            _inum.push_back((MOD-MOD/sz)*_inum[MOD%sz]%MOD);
            _ifact.push_back(_ifact.back()*_inum.back()%MOD);
        }
    }

    ll summation(ll n, int k)
    {
        if(n <= 0)return 0;
        vector<ll> sum(k+1), sum2(k+1);
        n = (n-1)%MOD;
        sum[0] = n+1;
        for(int i = 1 ; i <= k ; i++)
        {
            for(int j = 0 ; j < i-1 ; j++)
            {
                sum[i] = (sum[i]+(sum2[j]+MOD-sum[j])*comb(i,j))%MOD;
            }
            sum[i] = ((sum[i]+(sum[i-1]*(ll)i%MOD)*n)%MOD)*inum(i+1)%MOD;
            sum2[i-1] = (sum[i-1]*(n+1)+MOD-sum[i])%MOD;
        }
        return sum[k];
    }

    void update_summation(int n, int k, int a = 0, int b = 1)
    {
        a = mod(a), b = mod(b);
        if(!_update_dp_value_flag)
        {
            _update_dp_value_flag = true;
            _update_dp_value = b;
        }
        else
        {
            if(_update_dp_value != b)
            {
                _update_dp_value = b;
                _dp = {{1}};
            }
        }
        int tn = _dp.size(), tk = _dp[0].size();
        n = max(n, tn-1), k = max(k, tk-1);
        while((int)_pw2.size() <= n)
        {
            _pw2.push_back(_pw2.back()*2ll%MOD);
        }
        function<void(int,int)> f = [&](int n, int k)
        {
            _dp[n][k] = _dp[n-1][k];
            ll x = 1;
            ll pw = (b*_pw2[n-1])%MOD;
            for(int i = 0 ; i <= k ; i++)
            {
                _dp[n][k] = (_dp[n][k]+(comb(k,i)*x%MOD)*_dp[n-1][k-i])%MOD;
                x = (x*pw)%MOD;
            }
        };
        if(tk <= k)
        {
            _dp[0].resize(k+1);
            for(int i = 1 ; i < tn ; i++)
            {
                _dp[i].resize(k+1);
                for(int j = tk ; j <= k ; j++)
                {
                    f(i,j);
                }
            }
        }
        for(int i = tn ; i <= n ; i++)
        {
            _dp.emplace_back();
            _dp.back().resize(k+1);
            for(int j = 0 ; j <= k ; j++)
            {
                f(i,j);
            }
        }
    }

    ll summation_dp(ll n, int k, int a = 0, int b = 1)
    {
        //Remember to rebuild the dp when we use "Fn = a + b*n" for different values of "b"
        if(n <= 0)return 0;
        a = mod(a), b = mod(b);
        update_summation(__lg(n), k, a, b);
        ll res = 0, pos = 0;
        for(int j = __lg(n) ; j >= 0 ; j--)
        {
            if(n&(1ll<<j))
            {
                ll x = 1;
                ll pw = (a+b*pos)%MOD;
                for(int i = 0 ; i <= k ; i++)
                {
                    res = (res+(comb(k,i)*x%MOD)*_dp[j][k-i])%MOD;
                    x = (x*pw)%MOD;
                }
                pos = (pos+_pw2[j])%MOD;
            }
        }
        return res;
    }

    ll stirling1(ll n, ll k)
    {
        int k2 = n-k;
        ll res = 0;
        for(int i = 0 ; i <= 2*k2 ; i++)
        {
            int tot = 0;
            for(int j = 0 ; j <= i ; j++)
            {
                if(i-j-k2 < 0)break;
                if(j&1)tot = mod(tot - comb(i,j)*stirling1_dp(i-j,i-j-k2));
                else tot = mod(tot + comb(i,j)*stirling1_dp(i-j,i-j-k2));
            }
            res = mod(res + tot*comb2(n,i));
        }
        return res;
    }

    vector<ll> stirling1_fast(ll n, ll k)
    {
        vector<ll> ans;
        int k2 = n-k;
        if(k2 < 0)return ans;
        vector<ll> dp(k2+1);
        vector<ll> iv(k2+1);
        for(int i = 1 ; i <= k2 ; i++)iv[i] = inum(i);
        dp[0] = 1;
        ll pt = 0;
        for(int i = __lg(n) ; i >= 0 ; i--)
        {
            vector<ll> big(k2+1), pw(k2+1), tmp(k2+1);
            pw[0] = 1;
            for(int j = 1 ; j <= k2 ; j++)pw[j] = (pt%MOD)*pw[j-1]%MOD;

            int sz = min((ll)k2,pt)+1;

            vector<vector<ll>> ncr(sz,vector<ll>(sz));

            for(int j = 0 ; j < sz ; j++)
            {
                ncr[j][0] = 1;
                for(int l = 1 ; l < sz ; l++)
                {
                    ncr[j][l] = (pt-j-l+1)%MOD*ncr[j][l-1]%MOD*iv[l]%MOD;
                }
            }

            for(int j = 0 ; j <= min((ll)k2,pt) ; j++)
            {
                for(int l = 0 ; l <= j ; l++)
                {
                    big[j] = (big[j] + ncr[l][j-l]*pw[j-l]%MOD*dp[l])%MOD;
                }
            }

            for(int j = 0 ; j <= k2 ; j++)
            {
                for(int l = 0 ; l <= j ; l++)
                {
                    tmp[j] = (tmp[j] + dp[l]*big[j-l])%MOD;
                }
            }

            dp = tmp;
            pt *= 2;

            if(n&(1ll<<i))
            {
                tmp.assign(k2+1,0);
                tmp[0] = 1;
                for(int j = 1 ; j <= k2 ; j++)
                {
                    tmp[j] = (dp[j] + (pt%MOD)*dp[j-1])%MOD;
                }
                dp = tmp;
                pt++;
            }
        }
        ans = dp;
        return ans;
    }

    void update_stirling1(int n, int k)
    {
        int tn = _stirling1.size(), tk = _stirling1[0].size();
        n = max(n, tn-1), k = max(k, tk-1);
        function<void(int,int)> f = [&](int n, int k)
        {
            _stirling1[n][k] = (_stirling1[n-1][k-1]+_stirling1[n-1][k]*(n-1))%MOD;
        };
        if(tk <= k)
        {
            _stirling1[0].resize(k+1);
            for(int i = 1 ; i < tn ; i++)
            {
                _stirling1[i].resize(k+1);
                for(int j = tk ; j <= k ; j++)
                {
                    f(i,j);
                }
            }
        }
        for(int i = tn ; i <= n ; i++)
        {
            _stirling1.emplace_back();
            _stirling1.back().resize(k+1);
            for(int j = 1 ; j <= k ; j++)
            {
                f(i,j);
            }
        }
    }

    ll stirling1_dp(int n, int k)
    {
        update_stirling1(n,k);
        return _stirling1[n][k];
    }

    ll stirling2(ll n, int k)
    {
        ll res = 0;
        for(int i = 0 ; i <= k ; i++)
        {
            if(i&1)res = (res + MOD - comb(k,i)*qpow(k-i,n)%MOD)%MOD;
            else res = (res + comb(k,i)*qpow(k-i,n))%MOD;
        }
        return res*ifact(k)%MOD;
    }

    void update_stirling2(int n, int k)
    {
        int tn = _stirling2.size(), tk = _stirling2[0].size();
        n = max(n, tn-1), k = max(k, tk-1);
        function<void(int,int)> f = [&](int n, int k)
        {
            _stirling2[n][k] = (_stirling2[n-1][k-1]+_stirling2[n-1][k]*k)%MOD;
        };
        if(tk <= k)
        {
            _stirling2[0].resize(k+1);
            for(int i = 1 ; i < tn ; i++)
            {
                _stirling2[i].resize(k+1);
                for(int j = tk ; j <= k ; j++)
                {
                    f(i,j);
                }
            }
        }
        for(int i = tn ; i <= n ; i++)
        {
            _stirling2.emplace_back();
            _stirling2.back().resize(k+1);
            for(int j = 1 ; j <= k ; j++)
            {
                f(i,j);
            }
        }
    }

    ll stirling2_dp(int n, int k)
    {
        update_stirling2(n,k);
        return _stirling2[n][k];
    }

    void update_pascal(int n, int k)
    {
        int tn = _pascal.size(), tk = _pascal[0].size();
        n = max(n, tn-1), k = max(k, tk-1);
        function<void(int,int)> f = [&](int n, int k)
        {
            _pascal[n][k] = (_pascal[n-1][k]+_pascal[n-1][k-1])%MOD;
        };
        if(tk <= k)
        {
            _pascal[0].resize(k+1);
            for(int i = 1 ; i < tn ; i++)
            {
                _pascal[i].resize(k+1);
                for(int j = tk ; j <= k ; j++)
                {
                    f(i,j);
                }
            }
        }
        for(int i = tn ; i <= n ; i++)
        {
            _pascal.emplace_back();
            _pascal.back().resize(k+1);
            _pascal.back()[0] = 1;
            for(int j = 1 ; j <= k ; j++)
            {
                f(i,j);
            }
        }
    }

    ll comb_dp(int n, int k)
    {
        update_pascal(n,k);
        return _pascal[n][k];
    }

    ll extended_binomial(ll n, ll x, int k)
    {
        //x != (MOD-1)
        x = mod(x);
        if(x == 0 && k == 0)return 1;
        x = (inv(x)+1ll)%MOD;
        ll val = inv(x), res = 0, pw = 1;
        for(int i = 0 ; i <= k ; i++)
        {
            res = (res + stirling2_dp(k,i)*pw)%MOD;
            pw = (pw*(n-i)%MOD)*val%MOD;
        }
        res = res*qpow(x*inv((x+MOD-1)%MOD)%MOD,n)%MOD;
        return res;
    }

    ll lagrange_interpolation_arithmetic(const vector<ll> &y, ll T, ll a = 0, ll d = 1)
    {
        T = mod(T), a = mod(a), d = mod(d);

        int N = (int)y.size()-1;
        if(a == 0 && d == 1 && T <= N)return y[T];

        vector<ll> dp(N+1, 1), pd(N+1, 1);
        for(int i = 0 ; i < N ; i++)dp[i+1] = dp[i]*(T+MOD-(a+d*i)%MOD)%MOD;
        for(int i = N ; i > 0 ; i--)pd[i-1] = pd[i]*(T+MOD-(a+d*i)%MOD)%MOD;

        vector<ll> fact(N+1, 1), finv(N+1, 1);

        for(int i = 1 ; i <= N ; i++)fact[i] = fact[i-1]*d%MOD*i%MOD;
        finv[N] = finv[N]*inv(fact[N])%MOD;
        for(int i = N ; i >= 1 ; i--)finv[i-1] = finv[i]*d%MOD*i%MOD;

        ll ret = 0;

        for(int i = 0 ; i <= N ; i++)
        {
            ll tmp = y[i]*dp[i]%MOD*pd[i]%MOD*finv[i]%MOD*finv[N-i]%MOD;
            if((N-i)&1)ret = (ret+MOD-tmp)%MOD;
            else ret = (ret+tmp)%MOD;
        }

        return ret;
    }

    ll lagrange_interpolation(vector<pair<ll,ll>> p, ll z)
    {
        int n = p.size();
        ll l, val = 0;

        for(int i = 0 ; i < n ; i++)
        {
            p[i].first = mod(p[i].first);
            p[i].second = mod(p[i].second);
        }

        z = mod(z);

        for(int i = 0 ; i < n ; i++)
        {
            l = p[i].second;
            for(int j = 0 ; j < n ; j++)
            {
                if(i != j)
                {
                    l = l*(z+MOD-p[j].first)%MOD*inv(p[i].first+MOD-p[j].first)%MOD;
                }
            }
            val = (val+l)%MOD;
        }
        return val;
    }

    //Intersection value when you do inclusion and exclusion
    //principle with all subsets of size K of a set of N elements
    ll intersection_value(ll N, ll K)
    {
        if(N < K)return 0;
        if(K == 0)
        {
            if(N == 0)return 1;
            return 0;
        }
        if((N-K)&1)return mod(-comb(N-1,K-1));
        return comb(N-1,K-1);
    }

    ll catalan(int n)
    {
        return comb(2*n,n)*inum(n+1)%MOD;
    }

    ll comb(int n, int k)
    {
        if(n < k)return 0;
        update(n);
        return (_fact[n]*_ifact[n-k]%MOD)*_ifact[k]%MOD;
    }

    ll comb2(ll n, int k)
    {
        if(n < k)return 0;
        update(k);
        ll res = 1;
        for(ll i = n ; i > n-k ; i--)res = i%MOD*res%MOD;
        return res*_ifact[k]%MOD;
    }
}math(MOD);

#ifdef LOCAL 
#include "/media/brayand/BrayanD/debugger.h"
#else
#define db(...) false
#define dbl(...) false
#define dbg(...) false
#define dbm(...) false
#define dbs(...) false
#define dbas(...) false
#endif

const int MAXN = 3e5 + 100;

vector<int> L[MAXN];

int dp[MAXN][3];

void DFS(int nodo, int padre)
{
	vector<int> vect;

	for(auto v : L[nodo])
	{
		if(v != padre)
		{
			DFS(v, nodo);
			vect.push_back(v);
		}
	}

	if(vect.size() == 0)
	{
		dp[nodo][1] = 1;
		return;
	}

	dp[nodo][1] = 1;

	for(auto v : vect)
	{
		dp[nodo][1] *= (dp[v][0] + dp[v][1])%MOD;
		dp[nodo][1] %= MOD;
	}

	int tp1 = 1;
	int tp2 = 1;

	for(auto v : vect)
	{
		tp1 *= (dp[v][0] + dp[v][1])%MOD;
		tp1 %= MOD;

		tp2 *= (dp[v][0]*2 + dp[v][1])%MOD;
		tp2 %= MOD;
	}

	dp[nodo][2] = (tp2+MOD-tp1)%MOD;

	int mult = 1;

	for(auto v : vect)
	{
		mult *= (dp[v][0]*2 + dp[v][1])%MOD;
		mult %= MOD;
	}

	for(auto v : vect)
	{
		int temp = mult*math.inv((dp[v][0]*2 + dp[v][1])%MOD)%MOD;

		dp[nodo][0] += temp*(dp[v][1] + dp[v][2]);
		dp[nodo][0] %= MOD;
	}
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i = 1 ; i <= N-1 ; i++)
    {
    	int a, b;
    	cin >> a >> b;

    	L[a].push_back(b);
    	L[b].push_back(a);
    }

    DFS(1,-1);

    for(int i = 1 ; i <= N ; i++)
    {
    	dbs(dp,i,0);
    	dbs(dp,i,1);
    	dbs(dp,i,2);
    }

    int res = (dp[1][0]+dp[1][1])%MOD;

    cout << res << '\n';

    return 0;
}