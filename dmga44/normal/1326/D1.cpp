#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;

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
#define MAXN 500005

int rmq[MAXN][20],lg[MAXN];
int pos[MAXN];

int query(int l,int r)
{
    if(l>r)
        swap(l,r);
    l++;
    int po=lg[r-l+1];
    return min(rmq[l][po],rmq[r-(1<<po)+1][po]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    lg[0]=-1;
    for(int i=1;i<MAXN;i++)
        lg[i]=lg[i-1]+!(i&(i-1));

    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int ma=0,n=s.size();
        for(int i=0;i<n/2;i++)
        {
            if(s[i]==s[n-i-1])
                ma++;
            else
                break;
        }
        string sss=s;
        reverse(all(sss));

        string ss=s+"#"+sss;

        SuffixArray<char> sa(ss);

        for(int i=0;i<sa.lcp.size();i++)
            rmq[i][0]=sa.lcp[i];
        for(int i=1;i<=lg[sa.lcp.size()];i++)
            for(int j=0;j+(1<<i)<=sa.lcp.size();j++)
                rmq[j][i]=min(rmq[j][i-1],rmq[j+(1<<(i-1))][i-1]);

//        db(ss)
//        db(ma)
        for(int i=0;i<sa.sa.size();i++)
        {
            pos[sa.sa[i]]=i;
//            cout << sa.sa[i] << ' ' << sa.lcp[i] << '\n';
        }
//        db("")

        pii res=pii(1,1);
        for(int i=0;i<n/2;i++)
        {
            if(ma>i)
                res=max(res,pii(2*(i+1),1));
            else
            {
                int faltan=i+1-ma;
                int p1=ma;
                int p2=2*n-(i+faltan);

                if(query(pos[p1],pos[p2])>=faltan)
                    res=max(res,pii(2*(i+1),1));
            }
        }

        for(int i=0;i<(n+1)/2;i++)
        {
            if(ma>=i)
                res=max(res,pii(2*i+1,1));
            else
            {
                int faltan=i-ma;
                int p1=ma;
                int p2=2*n-(i+faltan);

                if(query(pos[p1],pos[p2])>=faltan)
                    res=max(res,pii(2*i+1,1));
            }
        }

        for(int i=0;i<n/2;i++)
        {
            if(ma>i)
                res=max(res,pii(2*(i+1),1));
            else
            {
                int faltan=i+1-ma;
                int p1=n-1-i-faltan;
                int p2=n+ma+1;

                if(query(pos[p1],pos[p2])>=faltan)
                    res=max(res,pii(2*(i+1),2));
            }
        }

        for(int i=0;i<(n+1)/2;i++)
        {
            if(ma>=i)
                res=max(res,pii(2*i+1,1));
            else
            {
                int faltan=i-ma;
                int p1=n-1-i-faltan;
                int p2=n+ma+1;

                if(query(pos[p1],pos[p2])>=faltan)
                    res=max(res,pii(2*i+1,2));
            }
        }

//        cout << res.first << ' ' << res.second << '\n';
        if(res.second==1)
        {
            for(int i=0;i<res.first/2;i++)
                cout << s[i];
            if(res.first&1)
                cout << s[res.first/2];
            for(int i=0;i<res.first/2;i++)
                cout << s[res.first/2-i-1];
            cout << '\n';
        }
        else
        {
            for(int i=0;i<res.first/2;i++)
                cout << s[n-1-i];
            if(res.first&1)
                cout << s[n-1-res.first/2];
            for(int i=0;i<res.first/2;i++)
                cout << s[n-res.first/2+i];
            cout << '\n';
        }
    }

    return 0;
}
/**
1
acbba
**/