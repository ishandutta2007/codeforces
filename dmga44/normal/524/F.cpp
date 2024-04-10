#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<int,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(1e6+5)

template <typename T>
struct ST{
    vector< T > st;
    int sz;

    ST (int n) : sz(n),st(4*n) {}

    T merge(T v1,T v2)
    {
        return min(v1,v2);
    }

    void build(vector<T> &arr) { build(1,0,sz-1,arr); }

    void build(int p,int l,int r,vector<T> &arr)
    {
        if(l==r)
        {
            st[p]=arr[l];
            return ;
        }
        int mid=(l+r)>>1;

        build(p<<1,l,mid,arr);
        build((p<<1)+1,mid+1,r,arr);

        st[p]=merge(st[p<<1],st[(p<<1)+1]);
    }

    T query(int L,int R) { return query(1,0,sz-1,L,R); }

    T query(int p,int l,int r,int L,int R)
    {
        if(L<=l && r<=R)
            return st[p];

        int mid=(l+r)>>1;

        if(R<=mid)
            return query(p<<1,l,mid,L,R);
        if(L>mid)
            return query((p<<1)+1,mid+1,r,L,R);
        return merge(query(p<<1,l,mid,L,R),query((p<<1)+1,mid+1,r,L,R));
    }
};

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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    s=s+s;
    int n=s.size()/2;
    vector<int> a(2*n+1);
    for(int i=0;i<2*n;i++)
    {
        if(s[i]=='(')
            a[i+1]=a[i]+1;
        else
            a[i+1]=a[i]-1;
    }

    ST<int> rmq(2*n+1);
    rmq.build(a);
    SuffixArray<char> sa(s);

    int len=1e6+5;
    int best=-1;
    for(int i=0;i<n;i++)
    {
        int mi_int=rmq.query(i,i+n);
        int v_ini=a[i];
        int v_fin=a[i+n];
        mi_int-=v_ini;
        v_fin-=v_ini;
        int cant=0;
        if(mi_int<0)
        {
            cant-=mi_int;
            v_fin-=mi_int;
            mi_int=0;
        }
        if(v_fin>0)
        {
            cant+=v_fin;
            v_fin=0;
        }
        if(cant<=len)
        {
            if(best==-1 || cant<len || sa.rank[best]>sa.rank[i])
                best=i;
            len=cant;
        }
//        cout << i << ' ' << cant << '\n';
    }

    int mi_int=rmq.query(best,best+n);
    int v_ini=a[best];
    int v_fin=a[best+n];
    mi_int-=v_ini;
    v_fin-=v_ini;
    int aa=0,b=0;
    if(mi_int<0)
    {
        aa-=mi_int;
        v_fin-=mi_int;
        mi_int=0;
    }
    if(v_fin>0)
    {
        b+=v_fin;
        v_fin=0;
    }

    for(int i=0;i<aa;i++)
        cout << '(';
    for(int i=0;i<n;i++)
        cout << s[best+i];
    for(int i=0;i<b;i++)
        cout << ')';
    cout << '\n';

    return 0;
}