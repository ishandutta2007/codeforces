#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[32;1m " << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;
template<class T> void mkuni(vector<T>&v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}
ll rand_int(ll l, ll r) //[l, r]
{
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<ll>(l, r)(gen);
}
template<class T>
void print(T x,int suc=1)
{
    cout<<x;
    if(suc==1) cout<<'\n';
    else cout<<' ';
}
template<class T>
void print(const vector<T>&v,int suc=1)
{
    for(int i=0;i<v.size();i++)
    print(v[i],i==(int)(v.size())-1?suc:2);
}
const int maxn=5e5+7;
int id[maxn];
vi G[maxn];
struct AC_auto
{
    int ch[maxn][26];
    int fail[maxn];
	int num[maxn];
    // ffail.
    int tot;
    void init()
    {
        tot = 0;
        for (int i = 0; i < 26; ++i)
            ch[0][i] = 0;
    }
    int insert(string s)
    {
        int u = 0;
		int len=s.length();
        for (int i = 0; i < len; i++)
        {
            if (!ch[u][s[i] - 'a'])
            {
                ch[u][s[i] - 'a'] = ++tot;
                for (int j = 0; j < 26; ++j)
                    ch[tot][j] = 0;
            }
            u = ch[u][s[i] - 'a'];
        }
		num[u]=1;
		return u;
    } //Trie.
    void build()
    {
        queue<int> q;
        for (int i = 0; i < 26; i++)
        {
            if (ch[0][i])
			{
				fail[ch[0][i]] = 0,
                //,fail.
                    q.push(ch[0][i]);
				G[0].push_back(ch[0][i]);
			}
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int i = 0; i < 26; i++)
                if (ch[u][i])
                {
                    fail[ch[u][i]] = ch[fail[u]][i];
					G[fail[ch[u][i]]].push_back(ch[u][i]);
					num[ch[u][i]]|=num[fail[ch[u][i]]];
				//	dbg(ch[fail[u]][i],ch[u][i]);
                    q.push(ch[u][i]);
                }
                else
                    ch[u][i] = ch[fail[u]][i];
            //.
        }
    } //Fail.
} AC;
ll mx[maxn<<2];
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
int n,k;
int tot;
int v[maxn];
multiset<int> allv[maxn];
void update(int l,int r,int v,int L=1,int R=tot,int o=1)
{
	if(l<=L&&r>=R)
	{
		mx[o]=v;
		return;
	}
	int mid=L+R>>1;
	if(l<=mid) update(l,r,v,Lson);
	if(r>mid) update(l,r,v,Rson);
	mx[o]=max(mx[lson],mx[rson]);
}
int query(int l,int r,int L=1,int R=tot,int o=1)
{
	if(l<=L&&r>=R)
		return mx[o];
	int mid=L+R>>1;
	int ret=0;
	if(l<=mid)
		ret=max(ret,query(l,r,Lson));
	if(r>mid) ret=max(ret,query(l,r,Rson));
	return ret;
}
namespace HLD{
	int fa[maxn], dep[maxn], maxson[maxn], son[maxn]; //dfs
	int top[maxn], dfn[maxn];                    //link
	int dfs(int u)
	{
		int ret = 0;
		for (auto v:G[u])
		{
			if (v == fa[u])
				continue;
			fa[v] = u;
			dep[v] = dep[u] + 1;
			int sz = dfs(v);
			ret += sz;
			if (sz > maxson[u])
			{
				maxson[u] = sz;
				son[u] = v;
			}
		}
		return ret + 1;
	}
	void link(int u, int t)
	{
		dfn[u] = ++tot;
		top[u] = t;
		if (son[u])
			link(son[u], t);
		for (auto v:G[u])
		{
			if (v == fa[u] || v == son[u])
				continue;
			link(v, v);
		}
	}
	void hld()
	{
		dfs(0);
		link(0, 0);
	}
	int ask(int u,int v)
	{
		int ret=0;
		while(top[u]!=top[v])
		{
			if(dep[top[u]]<dep[top[v]])
				swap(u,v);
			ret=max(ret,query(dfn[top[u]],dfn[u]));
			u=fa[top[u]];
		}
		if(dep[u]>dep[v]) swap(u,v);
		ret=max(ret,query(dfn[u],dfn[v]));
		return ret;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		id[i]=AC.insert(s);
		allv[id[i]].insert(0);
	}
	AC.build();
	HLD::hld();
	while(m--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int i,x;
			cin>>i>>x;
			i--;
			allv[id[i]].erase(allv[id[i]].find(v[i]));
			v[i]=x;
			allv[id[i]].insert(v[i]);
			x=*allv[id[i]].rbegin();
			i=id[i];
			update(HLD::dfn[i],HLD::dfn[i],x);
		}
		else{
			string s;
			cin>>s;
			int u=0,ans=0;
			bool suc=0;
			for(int i=0;i<s.length();i++)
			{
				u=AC.ch[u][s[i]-'a'];
				suc|=AC.num[u];
				ans=max(ans,HLD::ask(0,u));
			}
			if(!suc) print(-1);
			else print(ans);
		}
	}
}