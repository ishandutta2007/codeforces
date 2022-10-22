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
typedef pair<ll,ll> pii;
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
#define MAXN (ll)(1e5+5)

struct trie{
    struct node{
        node *sons[26];
        bool leaf;
        node() : leaf(1)
        {
            for(int i=0;i<26;i++)
                sons[i]=0;
        }
    }*root;

    trie() : root(new node()) {}

    void insert(string s)
    {
        node *p=root;
        for(int i=0;i<s.size();i++)
        {
            int v=s[i]-'a';
            if(!p->sons[v])
                p->sons[v]=new node();
            p->leaf=0;
            p=p->sons[v];
        }
    }

    bool dfs(node *p,bool base)
    {
        if(p->leaf)
            return base;
        bool res=0;
        for(int i=0;i<26;i++)
            if(p->sons[i] && !dfs(p->sons[i],base))
                res=1;
        return res;
    }

    bool game(bool base)
    {
        return dfs(root,base);
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    trie t;
    int n,k;
    cin >> n >> k;
    string s;
    for(int i=0;i<n;i++)
    {
        cin >> s;
        t.insert(s);
    }

    bool w=t.game(0);
    bool l=t.game(1);
//    cout << w << ' ' << l << '\n';
    if(!w)
        db("Second")
    else
    {
        if(k==1)
            db("First")
        else
        {
            if(l)
                db("First")
            else
            {
                if(k&1)
                    db("First")
                else
                    db("Second")
            }
        }
    }

    return 0;
}
/**

2 3
a
b

3 1
a
b
c

1 2
ab

**/