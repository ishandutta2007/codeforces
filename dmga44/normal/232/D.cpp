#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
#include <bits/stdc++.h>
#define db(x) cerr << #x << ':' << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define int ll
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
// typedef __int128_t int128;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef vector<ll> vi;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-6);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

template<typename charT>
struct SuffixArray
{
	int n;
	vector<int> sa, rank, lcp;

	SuffixArray(const basic_string<charT> &s) :
		n(s.length() + 1), sa(n), rank(n), lcp(n)
	{
		vector<int> _sa(n), bucket(n);

		iota(sa.rbegin(), sa.rend(), 0);
		sort(next(sa.begin()), sa.end(), 
			[&](int i, int j) { return s[i] < s[j]; });

		for (int i = 1, j = 0; i < n; ++i)
		{
			rank[sa[i]] = rank[sa[i - 1]] + 
						  (i == 1 || s[sa[i - 1]] < s[sa[i]]);
			if (rank[sa[i]] != rank[sa[i - 1]])
				bucket[++j] = i;
		}

		for (int len = 1; len <= n; len += len)
		{
			for (int i = 0, j; i < n; ++i)
			{
				if ((j = sa[i] - len) < 0) j += n;
				_sa[bucket[rank[j]]++] = j;
			}

			sa[_sa[bucket[0] = 0]] = 0;

			for (int i = 1, j = 0; i < n; ++i)
			{
				if (rank[_sa[i]] != rank[_sa[i - 1]] || 
					rank[_sa[i] + len] != rank[_sa[i - 1] + len])
					bucket[++j] = i;

				sa[_sa[i]] = j;
			}

			copy(sa.begin(), sa.end(), rank.begin());
			sa.swap(_sa);

			if (rank[sa[n - 1]] == n - 1) break;
		}

		for (int i = 0, j = rank[lcp[0] = 0], k = 0; i < n - 1; ++i, ++k)
			while (k >= 0 && s[i] != s[sa[j - 1] + k])
				lcp[j] = k--, j = rank[sa[j] + 1];
	}
};

template<typename T>
struct RMQ{
    vector<vector<T>> rmq;
    vector<int> lg;
    int n;
    bool t;
    RMQ(vector<T> &v,bool t) : n(v.size()),t(t)
    {
        lg.push_back(-1);
        for(int i=1;i<=n+5;i++)
            lg.push_back(lg.back()+!(i&(i-1)));

        for(int i=0;i<=n;i++)
            rmq.push_back(vector<T>(lg[n]+1));
        for(int i=0;i<n;i++)
            rmq[i][0]=v[i];
        for(int j=1;j<=lg[n];j++)
            for(int i=0;i+(1<<j)<=n;i++)
            {
                if(!t)
                    rmq[i][j]=min(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
                else
                    rmq[i][j]=max(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
            }
    }

    T query(int l,int r)
    {
        if(l>r)
            swap(l,r);
        int po=lg[r-l+1];
        if(!t)
            return min(rmq[l][po],rmq[r-(1<<po)+1][po]);
        return max(rmq[l][po],rmq[r-(1<<po)+1][po]);
    }
};

///ops fall in [0,n-1] range
struct st2d_abi
{
    vector<vector<int>> abi;
    int sz;

    st2d_abi(vector<int>& v)
    {
        sz=v.size()+1;
        abi=vector<vector<int>>(sz,vector<int>(0));
        for(int i=0;i<sz-1;i++)
            update(i+1,v[i]);
        for(int i=1;i<sz;i++)
            sort(all(abi[i]));
    }

    void update(int p,int v)
    {
        while(p<sz)
        {
            abi[p].push_back(v);
            p+=(p&-p);
        }
    }

    int query(int p,int v)
    {
        int ans=0;
        while(p)
        {
            ans+=upper_bound(all(abi[p]),v)-abi[p].begin();
            p-=(p&-p);
        }
        return ans;
    }

    ///x1<=x2 must hold
    int query(int l,int r,int x1,int x2)
    {
        return query(r+1,x2)-query(r+1,x1-1)-query(l,x2)+query(l,x1-1);
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];

    basic_string<int> d;
    for(int i=1;i<n;i++)
        d.push_back(a[i-1]-a[i]);

    d.push_back(1e9+5);

    for(int i=0;i<n;i++)
        d.push_back(-d[i]);

    SuffixArray<int> sa(d);
    vector<int> d_;
    for(auto y : d)
        d_.push_back(y);

    RMQ<int> lcp(sa.lcp,0); 
    st2d_abi abi(sa.sa);

    // for(auto y : d)
    //     cout << y << ' ';
    // cout << '\n';
    // for(auto y : sa.sa)
    //     cout << y << ' ';
    // cout << '\n';
    // for(auto y : sa.lcp)
    //     cout << y << ' ';
    // cout << '\n';

    int q;
    cin >> q;
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        l--,r--;
        if(l==r)
        {
            cout << n-1 << '\n';
            continue;
        }
        r--;

        int pos=sa.rank[l];
        int len=r-l+1;
        int l1=pos,r1=pos;
        for(int po=(1<<17);po;po>>=1)
        {
            if(l1-po>=0 && lcp.query(l1-po+1,pos)>=len)
                l1-=po;
            if(r1+po<sa.lcp.size() && lcp.query(pos+1,r1+po)>=len)
                r1+=po;
        }
        // cout << lcp.query(l1)
        // cout << l1 << ' ' << pos << ' ' << r1 << '\n';

        // for(int i=l1;i<=r1;i++)
        //     cout << sa.sa[i] << ' ';
        // cout << '\n';

        int ans=0;
        if(l-len-1>=0)
            ans+=abi.query(l1,r1,n,n+l-len-1);
        // cout << ans << '\n';
        if(r+1+len+1<n)
            ans+=abi.query(l1,r1,n+r+2,2*n-1);
        cout << ans << '\n';
        // cout << '\n';
    }

    return 0;   
}