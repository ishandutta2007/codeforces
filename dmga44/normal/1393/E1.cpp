#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
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
#define oo (ll)(0x3f3f3f3f3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(1.2e6+5)

//template<typename charT>
//struct SuffixArray
//{
//	int n;
//	vector<int> sa, rank, lcp;
//
//	SuffixArray(const basic_string<charT> &s) :
//		n(s.length() + 1), sa(n), rank(n), lcp(n)
//	{
//		vector<int> _sa(n), bucket(n);
//
//		iota(sa.rbegin(), sa.rend(), 0);
//		sort(next(sa.begin()), sa.end(),
//			[&](int i, int j) { return s[i] < s[j]; });
//
//		for (int i = 1, j = 0; i < n; ++i)
//		{
//			rank[sa[i]] = rank[sa[i - 1]] +
//						  (i == 1 || s[sa[i - 1]] < s[sa[i]]);
//			if (rank[sa[i]] != rank[sa[i - 1]])
//				bucket[++j] = i;
//		}
//
//		for (int len = 1; len <= n; len += len)
//		{
//			for (int i = 0, j; i < n; ++i)
//			{
//				if ((j = sa[i] - len) < 0) j += n;
//				_sa[bucket[rank[j]]++] = j;
//			}
//
//			sa[_sa[bucket[0] = 0]] = 0;
//
//			for (int i = 1, j = 0; i < n; ++i)
//			{
//				if (rank[_sa[i]] != rank[_sa[i - 1]] ||
//					rank[_sa[i] + len] != rank[_sa[i - 1] + len])
//					bucket[++j] = i;
//
//				sa[_sa[i]] = j;
//			}
//
//			copy(sa.begin(), sa.end(), rank.begin());
//			sa.swap(_sa);
//
//			if (rank[sa[n - 1]] == n - 1) break;
//		}
//
//		for (int i = 0, j = rank[lcp[0] = 0], k = 0; i < n - 1; ++i, ++k)
//			while (k >= 0 && s[i] != s[sa[j - 1] + k])
//				lcp[j] = k--, j = rank[sa[j] + 1];
//	}
//};

//namespace SuffixArray{
    unsigned char mask[] = { 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01 };
    #define tget(i) ( (t[(i)/8]&mask[(i)%8]) ? 1 : 0 )
    #define tset(i, b) t[(i)/8]=(b) ? (mask[(i)%8]|t[(i)/8]) : ((~mask[(i)%8])&t[(i)/8])
    #define chr(i) (cs==sizeof(int)?((int*)s)[i]:((unsigned char *)s)[i])
    #define isLMS(i) (i>0 && tget(i) && !tget(i-1))

    // find the start or end of each bucket
    void getBuckets(unsigned char *s, int *bkt, int n, int K, int cs, bool end) {
        int i, sum = 0;
        for (i = 0; i <= K; i++)
            bkt[i] = 0; // clear all buckets
        for (i = 0; i < n; i++)
            bkt[chr(i)]++; // compute the size of each bucket
        for (i = 0; i <= K; i++) {
            sum += bkt[i];
            bkt[i] = end ? sum : sum - bkt[i];
        }
    }
    // compute SAl
    void induceSAl(unsigned char *t, int *SA, unsigned char *s, int *bkt, int n, int K, int cs, bool end) {
        int i, j;
        getBuckets(s, bkt, n, K, cs, end); // find starts of buckets
        for (i = 0; i < n; i++) {
            j = SA[i] - 1;
            if (j >= 0 && !tget(j))
                SA[bkt[chr(j)]++] = j;
        }
    }
    // compute SAs
    void induceSAs(unsigned char *t, int *SA, unsigned char *s, int *bkt, int n, int K, int cs, bool end) {
        int i, j;
        getBuckets(s, bkt, n, K, cs, end); // find ends of buckets
        for (i = n - 1; i >= 0; i--) {
            j = SA[i] - 1;
            if (j >= 0 && tget(j))
                SA[--bkt[chr(j)]] = j;
        }
    }

    // find the suffix array SA of s[0..n-1] in {1..K}^n
    // require s[n-1]=0 (the sentinel!), n>=2
    // use a working space (excluding s and SA) of at most 2.25n+O(1) for a constant alphabet
    void SA_IS(unsigned char *s, int *SA, int n, int K, int cs) {
        int i, j;
        unsigned char *t = (unsigned char *) malloc(n / 8 + 1); // LS-type array in bits
        // Classify the type of each character
        tset(n-2, 0);
        tset(n-1, 1); // the sentinel must be in s1, important!!!
        for (i = n - 3; i >= 0; i--)
            tset(i, (chr(i)<chr(i+1) || (chr(i)==chr(i+1) && tget(i+1)==1))?1:0);
        // stage 1: reduce the problem by at least 1/2
        // sort all the S-substrings
        int *bkt = (int *) malloc(sizeof(int) * (K + 1)); // bucket array
        getBuckets(s, bkt, n, K, cs, true); // find ends of buckets
        for (i = 0; i < n; i++)
            SA[i] = -1;
        for (i = 1; i < n; i++)
            if (isLMS(i))
                SA[--bkt[chr(i)]] = i;
        induceSAl(t, SA, s, bkt, n, K, cs, false);
        induceSAs(t, SA, s, bkt, n, K, cs, true);
        free(bkt);
        // compact all the sorted substrings into the first n1 items of SA
        // 2*n1 must be not larger than n (proveable)
        int n1 = 0;
        for (i = 0; i < n; i++)
            if (isLMS(SA[i]))
                SA[n1++] = SA[i];
        // find the lexicographic names of all substrings
        for (i = n1; i < n; i++)
            SA[i] = -1; // init the name array buffer
        int name = 0, prev = -1;
        for (i = 0; i < n1; i++) {
            int pos = SA[i];
            bool diff = false;
            for (int d = 0; d < n; d++)
                if (prev == -1 || chr(pos+d) != chr(prev+d) || tget(pos+d) != tget(prev+d)) {
                    diff = true;
                    break;
                } else if (d > 0 && (isLMS(pos+d) || isLMS(prev+d)))
                    break;
            if (diff) {
                name++;
                prev = pos;
            }
            pos = (pos % 2 == 0) ? pos / 2 : (pos - 1) / 2;
            SA[n1 + pos] = name - 1;
        }
        for (i = n - 1, j = n - 1; i >= n1; i--)
            if (SA[i] >= 0)
                SA[j--] = SA[i];
        // stage 2: solve the reduced problem
        // recurse if names are not yet unique
        int *SA1 = SA, *s1 = SA + n - n1;
        if (name < n1)
            SA_IS((unsigned char*) s1, SA1, n1, name - 1, sizeof(int));
        else
            // generate the suffix array of s1 directly
            for (i = 0; i < n1; i++)
                SA1[s1[i]] = i;
        // stage 3: induce the result for the original problem
        bkt = (int *) malloc(sizeof(int) * (K + 1)); // bucket array
        // put all left-most S characters into their buckets
        getBuckets(s, bkt, n, K, cs, true); // find ends of buckets
        for (i = 1, j = 0; i < n; i++)
            if (isLMS(i))
                s1[j++] = i; // get p1
        for (i = 0; i < n1; i++)
            SA1[i] = s1[SA1[i]]; // get index in s
        for (i = n1; i < n; i++)
            SA[i] = -1; // init SA[n1..n-1]
        for (i = n1 - 1; i >= 0; i--) {
            j = SA[i];
            SA[i] = -1;
            SA[--bkt[chr(j)]] = j;
        }
        induceSAl(t, SA, s, bkt, n, K, cs, false);
        induceSAs(t, SA, s, bkt, n, K, cs, true);
        free(bkt);
        free(t);
    }

    int sa[MAXN];
    int lcp[MAXN];
    int rankk[MAXN];
    unsigned char *s;
    int n;

    void buildLcp(){
        int i, j, k;
        for(j = rankk[lcp[i = k = 0] = 0]; i < n - 1; i++, k++)
            while(k >= 0 && s[i] != s[sa[j - 1] + k])
                lcp[j] = (k--), j = rankk[sa[j] + 1];
    }

    void build(string str)
    {
        n = str.size();
        s = (unsigned char*) str.c_str();
        SA_IS(s, sa, n + 1, 256, 1);
        for (int i = 0; i < n; ++i){
            sa[i] = sa[i + 1];
            rankk[sa[i]] = i;
        }
        buildLcp();
    }
//}
//using namespace SuffixArray;

int rmq[MAXN][21];
int lg[MAXN];

int query(int l,int r)
{
    if(l>r)
        swap(l,r);
    int po=lg[r-l];
    return min(rmq[l+1][po],rmq[r-(1<<po)+1][po]);
}

char sssxxx[MAXN];
int ps[MAXN];
vector<int> psss[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    freopen(".in","r",stdin);

    int n;
    scanf("%d",&n);
    string s="";
    for(int i=0;i<n;i++)
    {
        scanf("%s",&sssxxx);
        int pos=0;
        ps[i]=s.size();
        while(sssxxx[pos]!='\0')
        {
            s.push_back(sssxxx[pos]);
            pos++;
        }
        s.push_back('0');
    }
    ps[n]=s.size();

    int* isa=rankk;
    build(s);
    lg[0]=-1;
    for(int i=0;i<s.size();i++)
    {
        rmq[i][0]=lcp[i];
        lg[i+1]=lg[i]+!((i+1)&(i));
    }
    for(int j=1;j<=lg[s.size()];j++)
        for(int i=0;i+(1<<j)<=s.size();i++)
            rmq[i][j]=min(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);

    vector<pii> pieces;
    for(int i=0;i<n;i++)
    {
        int pos=0;
        while(ps[i]+pos<ps[i+1])
        {
            pieces.push_back(pii(i,pos));
            pos++;
        }
    }

    auto cacho=[&](pii a,pii b,int len)
    {
        int w1=a.f;
        int p1=a.s;
        int w2=b.f;
        int p2=b.s;
        if(w1==w2 && p1==p2)
            return 0;
        int x=query(isa[ps[w1]+p1],isa[ps[w2]+p2]);
        if(x<len)
            return (isa[ps[w1]+p1]<isa[ps[w2]+p2])+1;
        return 0;
    };

    auto cmp=[&](pii a,pii b)
    {
        int w1=a.f;
        int p1=a.s;
        int w2=b.f;
        int p2=b.s;

        int l1=min(p1,p2);
        int v1=cacho(pii(w1,0),pii(w2,0),l1);
        if(v1)
            return v1-1;

        int ok=0;
        if(p1>p2)
        {
            swap(p1,p2);
            swap(w1,w2);
            ok=1;
        }
        int c1=ps[w1+1]-ps[w1]-1;
        int c2=ps[w2+1]-ps[w2]-1;
        int l2=min(c1-p1-(p1!=c1),p2-p1);
        int v2=cacho(pii(w1,p1+1),pii(w2,p1),l2);
        if(v2)
            return (v2-1)^ok;

        int l3=min(c1-p1-(p1!=c1)-l2,c2-p2-(p2!=c2));
        int v3=cacho(pii(w1,p1+1+l2),pii(w2,p2+1),l3);
        if(v3)
            return (v3-1)^ok;
        if((c1-(c1!=p1))!=(c2-(c2!=p2)))
            return (((c1-(c1!=p1)))<((c2-(c2!=p2))))^ok;
        return (int)(a<b);
    };

    sort(all(pieces),cmp);

    for(int i=0;i<pieces.size();i++)
        psss[pieces[i].f].push_back(i+1);

    vector<pii> ac;
    ac.push_back(pii(0,1));
    for(int i=0;i<n;i++)
    {
        vector<pii> nac;
        nac.push_back(pii(0,0));
        for(auto y : psss[i])
        {
            ll p=lower_bound(all(ac),pii(y,0))-ac.begin()-1;
            nac.push_back(pii(y,(nac.back().s+ac[p].s)%mod));
        }
        ac=nac;
    }

    db(ac.back().s)

    return 0;
}
/**
3
abcd
zaza
ataka
4

4
dfs
bfs
sms
mms
8

3
abc
bcd
a
0

6
lapochka
kartyshka
bigbabytape
morgenshtern
ssshhhiiittt
queen
2028

**/