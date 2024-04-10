#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
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

#define MAXP (ll)(1e7+5)
///up to change
typedef int T;
struct node{
    int l,r;
    T v;
};

node pool[MAXP];
int actual;

int next()
{
    actual++;
    return actual;
}

//template<typename T>
struct pst{
    vector<int> versions;
    int n;
    pst() : n(0) {}
    pst(int n) : n(n) {}
    pst(vector<T> &a) : n(a.size()) { versions.push_back(build(0,n-1,a)); }

    T merge(T v1,T v2)
    {
        return v1+v2;
    }

    void up(int p,T v)
    {
        pool[p].v+=v;
    }

    int build(int l,int r,vector<T> &a)
    {
        int ans=next();
        if(l==r)
        {
            pool[ans].v=a[l];
            return ans;
        }
        int mid=(l+r)>>1;
        pool[ans].l=build(l,mid,a);
        pool[ans].r=build(mid+1,r,a);
        pool[ans].v=merge(pool[pool[ans].l].v,pool[pool[ans].r].v);
        return ans;
    }

    int build(int l,int r,T* a)
    {
        int ans=next();
        if(l==r)
        {
            pool[ans].v=a[l];
            return ans;
        }
        int mid=(l+r)>>1;
        pool[ans].l=build(l,mid,a);
        pool[ans].r=build(mid+1,r,a);
        pool[ans].v=merge(pool[pool[ans].l].v,pool[pool[ans].r].v);
        return ans;
    }

    int clone(int p)
    {
        int ans=next();
        pool[ans].l=pool[p].l;
        pool[ans].r=pool[p].r;
        pool[ans].v=pool[p].v;
        return ans;
    }

    void update(int ver,int pos,T v) { versions.push_back(update(versions[ver],0,n-1,pos,v)); }
    void update(int pos,T v) { versions.push_back(update(versions.back(),0,n-1,pos,v)); }

    int update(int p,int l,int r,int pos,T v)
    {
        p=clone(p);

        if(r==l)
        {
            up(p,v);
            return p;
        }
        int mid=(l+r)>>1;
        if(pos<=mid)
            pool[p].l=update(pool[p].l,l,mid,pos,v);
        else
            pool[p].r=update(pool[p].r,mid+1,r,pos,v);
        pool[p].v=merge(pool[pool[p].l].v,pool[pool[p].r].v);
        return p;
    }

    T query(int t,int l,int r) { return query(versions[t],0,n-1,l,r); }

    T query(int p,int l,int r,int L,int R)
    {
        if(L<=l && r<=R)
            return pool[p].v;

        int mid=(l+r)>>1;
        if(R<=mid)
            return query(pool[p].l,l,mid,L,R);
        if(L>mid)
            return query(pool[p].r,mid+1,r,L,R);
        return merge(query(pool[p].l,l,mid,L,R),query(pool[p].r,mid+1,r,L,R));
    }

    int multi_kth(vector<int> &p,vector<int> &sg,int l,int r,int k)
    {
        if(l==r)
            return l;

        int mid=(l+r)>>1;
        int sl=0;
        for(int i=0;i<p.size();i++)
            sl+=(pool[pool[p[i]].l].v)*(sg[i]);
        if(sl>=k)
        {
            vector<int> next;
            for(auto pp : p)
                next.push_back(pool[pp].l);
            return multi_kth(next,sg,l,mid,k);
        }
        k-=sl;

        vector<int> next;
        for(auto pp : p)
            next.push_back(pool[pp].r);
        return multi_kth(next,sg,mid+1,r,k);
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

int lims[MAXN][2],pos[MAXN];
int sz[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin >> n >> q;
    vector<int> ini(n);
    vector<char> vs;
    for(int i=0;i<n;i++)
    {
        string ss;
        cin >> ss;
        sz[i]=ss.size();
        ini[i]=vs.size();
        for(auto y : ss)
            vs.push_back(y);
        vs.push_back('#');
    }

    string s;
    s.resize(vs.size());
    for(int i=0;i<vs.size();i++)
        s[i]=vs[i];
    SuffixArray<char> sa(s);
    vector<int> ini2(n);
    pst st(ini);
    RMQ<int> rmq(sa.lcp,0);
//    db(s)
//    for(int i=0;i<sa.sa.size();i++)
//        cout<< sa.sa[i] << ' ';
//    cout << '\n';
//    for(int i=0;i<sa.lcp.size();i++)
//        cout<< sa.lcp[i] << ' ';
//    cout << '\n';

    for(int i=0;i<sa.sa.size();i++)
    {
        int y=sa.sa[i];
        int x=upper_bound(all(ini),y)-ini.begin()-1;
        st.update(x,1);
//        cout << x << ' ';
        if(y==ini[x])
            pos[x]=i;
    }
//    cout << '\n';

    for(int i=0;i<n;i++)
    {
        int mi=pos[i];
        int ma=pos[i];
        for(int po=(1<<18);po;po>>=1)
            if(mi-po>=0 && rmq.query(mi-po+1,pos[i])>=sz[i])
                mi-=po;
        for(int po=(1<<18);po;po>>=1)
            if(ma+po<sa.lcp.size() && rmq.query(pos[i]+1,ma+po)>=sz[i])
                ma+=po;
        lims[i][0]=mi;
        lims[i][1]=ma;
//        cout << lims[i][0] << ' ' << lims[i][1] << '\n';
    }

    while(q--)
    {
        int l,r,k;
        cin >> l >> r >> k;
        k--,l--,r--;
        db(st.query(lims[k][1]+1,l,r)-st.query(lims[k][0],l,r))
    }

    return 0;
}
/**
5 5
a
ab
abab
ababab
b
1 5 1
3 5 1
1 5 2
1 5 3
1 4 5
**/