#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;
typedef pair<pii,ll> ppi;
typedef pair<pii,pii> ppp;
typedef pair<ld,ll> pli;
typedef pair<pii,string> pps;
typedef pair<char,ll> pci;
typedef complex<double> point;
typedef vector<point> polygon;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define MAXN 3005
#define mod (ll(1e9+7))
#define m2 (ll(2e9+99))
#define bbb (ll(331))
#define bb (ll(997))
#define b (ll(10003))

ll dp[MAXN],ilcp[MAXN],isa[MAXN];

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
             [&](int i, int j)
        {
            return s[i] < s[j];
        });
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
                if ((j = sa[i] - len) < 0)
                    j += n;
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
            if (rank[sa[n - 1]] == n - 1)
                break;
        }
        for (int i = 0, j = rank[lcp[0] = 0], k = 0; i < n - 1; ++i, ++k)
            while (k >= 0 && s[i] != s[sa[j - 1] + k])
                lcp[j] = k--, j = rank[sa[j] + 1];
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll m,x;
    cin >> m;
    string s;
    ll res=0;
    for(int i=0;i<m;i++)
    {
        cin >> x;
        if(x==0)
            s=s+"0";
        else
            s=s+"1";
    }

    reverse(s.begin(),s.end());

    SuffixArray<char> a(s);

    reverse(s.begin(),s.end());

    for(int i=1;i<m+1;i++)
        isa[m-a.sa[i]-1]=i;
    for(int i=0;i<m;i++)
    {
        int ma=0,mi=MAXN;
        for(int j=isa[i];j>=1;j--)
        {
            mi=min(mi,a.lcp[j]);
            if(m-a.sa[j-1]-1<i)
                ma=max(ma,mi);
        }
        mi=MAXN;
        for(int j=isa[i]+1;j<=m;j++)
        {
            mi=min(mi,a.lcp[j]);
            if(m-a.sa[j]-1<i)
                ma=max(ma,mi);
        }
        ilcp[i]=ma;
    }

    for(int i=0;i<m;i++)
    {
        dp[i+1]=1;
        for(int j=i+1;j;j--)
        {
            int sum=0;
            dp[j]%=mod;
            for(int u=1;u<=j && u<=4;u++)
            {
                if(s[j-u]=='1')
                    sum+=(1<<(u-1));
                if(u!=4  || (sum!=3 && sum!=5 && sum!=14 && sum!=15))
                    dp[j-u]+=dp[j];
            }
        }

        for(int j=0;j<=i+1;j++)
        {
            if((i+1)-j>ilcp[i])
                res+=dp[j];
            dp[j]=0;
        }
        res%=mod;
        db(res)
    }

    return 0;
}