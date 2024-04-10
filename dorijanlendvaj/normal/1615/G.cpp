//DUEL
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define x first
#define y second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define eb emplace_back
#pragma GCC optimize("unroll-loops")
#define shandom_ruffle(a, b) shuffle(a, b, rng)
#define vi vector<int>
#define vl vector<ll>
#define popcnt __builtin_popcountll
#define all(a) begin(a),end(a)
//for kactl
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

using namespace std;
using namespace __gnu_pbds;

using ll=long long;
using ull=unsigned long long;
using ld=long double;
int MOD=1000000007;
int MOD2=998244353;
vector<int> bases;
const ll LLINF=1ll<<60;
const char en='\n';

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void yes() {cout<<"YES"<<en; exit(0);}
void no() {cout<<"NO"<<en; exit(0);}
inline int rund() {int x576363482791fuweh=rng();return abs(x576363482791fuweh)%RAND_MAX;}
template<class T>
void prVec(vector<T> w,bool fl=false)
{
	cout<<w.size()<<en;
	for (int i=0;i<int(w.size())-1;++i) cout<<w[i]<<' ';
	if (w.size()) cout<<w[w.size()-1]<<en;
	if (fl) cout<<flush;
}

void M998()
{
	swap(MOD,MOD2);
}

ll raand()
{
	ll a=rund();
	a*=RAND_MAX;
	a+=rund();
    return a;
}

#define rand raand

ll raaand()
{
	return raand()*(MOD-7)+raand();
}

template<class T>
vi compress(vector<T>&v)
{
	set<T> s;
	for (auto a: v) s.insert(a);
	vector<T> o(all(s));
	vi nv;
	for (int i=0;i<(int)v.size();++i) nv.pb(lower_bound(all(o),v[i])-o.begin());
	return nv;
}

string to_upper(string a)
{
	for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
	return a;
}

string to_lower(string a)
{
	for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
	return a;
}

ll sti(string a,int base=10)
{
	ll k=0;
	for (int i=0;i<(int)a.size();++i)
	{
		k*=base;
		k+=a[i]-'0';
	}
	return k;
}

template<class T>
void eras(vector<T>& a,T b)
{
	a.erase(find(a.begin(),a.end(),b));
}

string its(ll k,int base=10)
{
	if (k==0) return "0";
	string a;
	while (k)
	{
		a.push_back((k%base)+'0');
		k/=base;
	}
	reverse(a.begin(),a.end());
	return a;
}

ll min(ll a,int b)
{
	if (a<b) return a;
	return b;
}

ll min(int a,ll b)
{
	if (a<b) return a;
	return b;
}

ll max(ll a,int b)
{
	if (a>b) return a;
	return b;
}

ll max(int a,ll b)
{
	if (a>b) return a;
	return b;
}

ll gcd(ll a,ll b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}

ll lcm(ll a,ll b)
{
	return a/gcd(a,b)*b;
}

template<class T,class K>
pair<T,K> mp(T a,K b)
{
	return make_pair(a,b);
}

inline int mult(ll a,ll b)
{
	return (a*b)%MOD;
}

inline int pot(int n,int k)
{
	if (k==0) return 1;
	ll a=pot(n,k/2);
	a=mult(a,a);
	if (k%2) return mult(a,n);
	else return a;
}

int divide(int a,int b)
{
	return mult(a,pot(b,MOD-2));
}

inline int sub(int a,int b)
{
	if (a-b>=0) return a-b;
	return a-b+MOD;
}

inline int add(int a,int b)
{
	if (a+b>=MOD) return a+b-MOD;
	return a+b;
}

void ad(int&a,int b)
{
	a+=b;
	if (a>=MOD) a-=MOD;
}

void su(int&a,int b)
{
	a-=b;
	if (a<0) a+=MOD;
}

bool prime(ll a)
{
	if (a==1) return 0;
	for (int i=2;i<=round(sqrt(a));++i)
	{
		if (a%i==0) return 0;
	}
	return 1;
}

struct blossom {
    int n, m;
    vector<int> mate;
    vector<vector<int>> b;
    vector<int> p, d, bl;
    vector<vector<int>> g;
    blossom(int n) : n(n) {
        m = n + n / 2;
        mate.assign(n, -1);
        b.resize(m);
        p.resize(m);
        d.resize(m);
        bl.resize(m);
        g.assign(m, vector<int>(m, -1));
    }
    void add_edge(int u, int v) {
        g[u][v] = u;
        g[v][u] = v;
    }
    void match(int u, int v) {
        g[u][v] = g[v][u] = -1;
        mate[u] = v;
        mate[v] = u;
    }
    vector<int> trace(int x) {
        vector<int> vx;
        while(true) {
            while(bl[x] != x) x = bl[x];
            if(!vx.empty() && vx.back() == x) break;
            vx.push_back(x);
            x = p[x];
        }
        return vx;
    }
    void contract(int c, int x, int y, vector<int> &vx, vector<int> &vy) {
        b[c].clear();
        int r = vx.back();
        while(!vx.empty() && !vy.empty() && vx.back() == vy.back()) {
            r = vx.back();
            vx.pop_back();
            vy.pop_back();
        }
        b[c].push_back(r);
        b[c].insert(b[c].end(), vx.rbegin(), vx.rend());
        b[c].insert(b[c].end(), vy.begin(), vy.end());
        for(int i = 0; i <= c; i++) {
            g[c][i] = g[i][c] = -1;
        }
        for(int z : b[c]) {
            bl[z] = c;
            for(int i = 0; i < c; i++) {
                if(g[z][i] != -1) {
                    g[c][i] = z;
                    g[i][c] = g[i][z];
                }
            }
        }
    }
    vector<int> lift(vector<int> &vx) {
        vector<int> A;
        while(vx.size() >= 2) {
            int z = vx.back(); vx.pop_back();
            if(z < n) {
                A.push_back(z);
                continue;
            }
            int w = vx.back();
            int i = (A.size() % 2 == 0 ? find(b[z].begin(), b[z].end(), g[z][w]) - b[z].begin() : 0);
            int j = (A.size() % 2 == 1 ? find(b[z].begin(), b[z].end(), g[z][A.back()]) - b[z].begin() : 0);
            int k = b[z].size();
            int dif = (A.size() % 2 == 0 ? i % 2 == 1 : j % 2 == 0) ? 1 : k - 1;
            while(i != j) {
                vx.push_back(b[z][i]);
                i = (i + dif) % k;
            }
            vx.push_back(b[z][i]);
        }
        return A;
    }
    int solve() {
        for(int ans = 0; ; ans++) {
            fill(d.begin(), d.end(), 0);
            queue<int> Q;
            for(int i = 0; i < m; i++) bl[i] = i;
            for(int i = 0; i < n; i++) {
                if(mate[i] == -1) {
                    Q.push(i);
                    p[i] = i;
                    d[i] = 1;
                }
            }
            int c = n;
            bool aug = false;
            while(!Q.empty() && !aug) {
                int x = Q.front(); Q.pop();
                if(bl[x] != x) continue;
                for(int y = 0; y < c; y++) {
                    if(bl[y] == y && g[x][y] != -1) {
                        if(d[y] == 0) {
                            p[y] = x;
                            d[y] = 2;
                            p[mate[y]] = y;
                            d[mate[y]] = 1;
                            Q.push(mate[y]);
                        }else if(d[y] == 1) {
                            vector<int> vx = trace(x);
                            vector<int> vy = trace(y);
                            if(vx.back() == vy.back()) {
                                contract(c, x, y, vx, vy);
                                Q.push(c);
                                p[c] = p[b[c][0]];
                                d[c] = 1;
                                c++;
                            }else {
                                aug = true;
                                vx.insert(vx.begin(), y);
                                vy.insert(vy.begin(), x);
                                vector<int> A = lift(vx);
                                vector<int> B = lift(vy);
                                A.insert(A.end(), B.rbegin(), B.rend());
                                for(int i = 0; i < (int) A.size(); i += 2) {
                                    match(A[i], A[i + 1]);
                                    if(i + 2 < (int) A.size()) add_edge(A[i + 1], A[i + 2]);
                                }
                            }
                            break;
                        }
                    }
                }
            }
            if(!aug) return ans;
        }
    }
};

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
const int N=300010;
int t,n,h[N],comp[N];
vector<pii> ch[N],ch1[N];
vi im[N];
bool bio[N],maed[N];
vi ord;
int osi,kak,par[N];

void dfs(int i)
{
	ord.pb(i);
	bio[i]=1;
	map<int,bool> pos;
	for (auto a: ch[i])
	{
		if (bio[a.x])
		{
			if (a.x!=par[i])
			{
				if (!osi && !pos[a.x])
				{
					osi=a.x;
					kak=i;
					//cout<<"T2"<<kak<<' '<<osi<<' '<<i<<' '<<a.x<<' '<<a.y<<' '<<par[i]<<en;
					h[a.y]=a.x;
				}
			}
		}
		else
		{
			par[a.x]=i;
			pos[a.x]=1;
			dfs(a.x);
		}
	}
}

void dfs1(int i)
{
	bio[i]=1;
	for (auto a: ch[i])
	{
		//cout<<i<<' '<<a.x<<' '<<bio[a.x]<<en;
		if (!bio[a.x] && !(i==osi && a.x==kak))
		{
			h[a.y]=a.x;
			dfs1(a.x);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829*2)+13893829);
	cin>>n;
	for (int i=0;i<n;++i) cin>>h[i];
	vector<pair<pii,pii>> parn,nep;
	for (int i=0;i<n;++i) if (h[i]==0)
	{
		int poc=-1;
		if (i) poc=h[i-1];
		int gp=i;
		while (i<n && h[i]==0) ++i;
		int kol=i-gp;
		--i;
		int kr=-1;
		if (i<n-1) kr=h[i+1];
		//cout<<kol<<' '<<poc<<' '<<kr<<' '<<gp<<' '<<i<<en;
		if (kol%2)
		{
			if (poc!=-1 && kr!=-1) nep.pb({{poc,kr},{gp,i}});
			else if (poc!=-1 && kr==-1) nep.pb({{poc,poc},{gp,gp}});
			else if (poc==-1 && kr!=-1) nep.pb({{kr,kr},{i,i}});
		}
		else
		{
			if (poc!=-1 && kr!=-1) parn.pb({{poc,kr},{gp,i}});
		}
	}
	for (int i=0;i<n-1;++i) if (h[i] && h[i]==h[i+1]) nep.pb({{h[i],h[i]},{i,i}});
	map<pii,vector<pii>> vnep;
	for (auto x: nep) vnep[x.x].pb(x.y);
	for (auto x: nep)
	{
		ch[x.x.x].pb({x.x.y,x.y.y});
		ch[x.x.y].pb({x.x.x,x.y.x});
	}
	for (int i=1;i<=600;++i) if (!bio[i])
	{
		osi=0;
		kak=0;
		ord.clear();
		dfs(i);
		if (!osi)
		{
			for (auto x: ord) if (!osi)
			{
				map<int,vi> poj;
				for (auto y: ch[x]) poj[y.x].pb(y.y);
				for (auto y: poj) if (y.y.size()>1)
				{
					int des=y.x;
					vector<pii> po;
					for (auto x: vnep[{x,des}]) po.pb({x.x,x.y});
					for (auto x: vnep[{des,x}]) po.pb({x.y,x.x});
					assert(po.size()>1);
					h[po[0].x]=x;
					h[po[1].y]=des;
					osi=x;
					kak=des;
					for (auto u: ord) bio[u]=0;
					dfs1(osi);
					dfs1(kak);
					break;
				}
			}
			if (!osi)
			{
				for (auto x: ord) comp[x]=i,im[i].pb(x);
			}
		}
		else
		{
			assert(kak);
			for (auto x: ord) bio[x]=0;
			dfs1(osi);
		}
	}
	blossom B(600);
	map<pii,pair<pii,pii>> parr;
	for (auto x: parn)
	{
		if (comp[x.x.x] && comp[x.x.y])
		{
			int u=comp[x.x.x]-1,v=comp[x.x.y]-1;
			if (u==v) continue;
			if (u>v) parr[{v,u}]={{x.x.y,x.x.x},{x.y.y,x.y.x}};
			else parr[{u,v}]=x;
		}
	}
	for (auto x: parr)
	{
		B.add_edge(x.x.x,x.x.y);
	}
	B.solve();
	for (int i=0;i<600;++i) if (i<B.mate[i])
	{
		auto dob=parr[{i,B.mate[i]}];
		h[dob.y.x]=dob.x.x;
		h[dob.y.y]=dob.x.y;
		for (auto x: im[comp[dob.x.x]]) bio[x]=0;
		for (auto x: im[comp[dob.x.y]]) bio[x]=0;
		//cout<<dob.x.x<<' '<<dob.x.y<<' '<<comp[dob.x.x]<<' '<<comp[dob.x.y]<<en;
		dfs1(dob.x.x);
		dfs1(dob.x.y);
		maed[comp[dob.x.x]]=1;
		maed[comp[dob.x.y]]=1;
	}
	osi=kak=-1;
	for (int i=1;i<=600;++i) if (im[i].size()>1 && !maed[i])
	{
		for (auto x: im[i]) bio[x]=0;
		/*cout<<i<<endl;
		prVec(im[i]);
		for (int j=1;j<=4;++j)
		{
			cout<<"ch["<<j<<"]\n";
			for (auto x: ch[j]) cout<<x.x<<' '<<x.y<<en;
		}*/
		dfs1(i);
	}
	set<int> mog;
	for (int i=1;i<=n;++i) mog.insert(i);
	for (int i=0;i<n;++i) if (mog.count(h[i])) mog.erase(h[i]);
	for (int i=1;i<n;++i) if (h[i]==0 && h[i-1]==0)
	{
		int kak=*mog.begin();
		mog.erase(kak);
		h[i]=h[i-1]=kak;
	}
	for (int i=0;i<n;++i) if (h[i]==0) h[i]=n;
	for (int i=0;i<n;++i) cout<<h[i]<<' ';
	cout<<en;
}