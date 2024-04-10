#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define pb emplace_back
#define lb(v,k) (lower_bound(all(v),(k))-v.begin())
#define ub(v,k) (upper_bound(all(v),(k))-v.begin())
#define fi first
#define se second
#define pi M_PI
#define PQ(T) priority_queue<T>
#define SPQ(T) priority_queue<T,vector<T>,greater<T>>
#define dame(a) {out(a);return 0;}
#define decimal cout<<fixed<<setprecision(15);
#define all(a) a.begin(),a.end()
#define rsort(a) {sort(all(a));reverse(all(a));}
#define dupli(a) {sort(all(a));a.erase(unique(all(a)),a.end());}
#define popcnt __builtin_popcountll
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef tuple<ll,ll,ll,ll> PPP;
using vi=vector<ll>;
using vvi=vector<vi>;
using vvvi=vector<vvi>;
using vvvvi=vector<vvvi>;
using vp=vector<P>;
using vvp=vector<vp>;
using vb=vector<bool>;
using vvb=vector<vb>;
const ll inf=1001001001001001001;
const ll INF=1001001001;
const ll mod=1000000007;
const double eps=1e-10;
template<class T> bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}
template<class T> bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T> void out(T a){cout<<a<<'\n';}
template<class T> void outp(T a){cout<<'('<<a.fi<<','<<a.se<<')'<<'\n';}
template<class T> void outvp(T v){rep(i,v.size())cout<<'('<<v[i].fi<<','<<v[i].se<<')';cout<<'\n';}
template<class T> void outvvp(T v){rep(i,v.size())outvp(v[i]);}
template<class T> void outv(T v){rep(i,v.size()){if(i)cout<<' ';cout<<v[i];}cout<<'\n';}
template<class T> void outvv(T v){rep(i,v.size())outv(v[i]);}
template<class T> void yesno(T b){if(b)out("yes");else out("no");}
template<class T> void YesNo(T b){if(b)out("Yes");else out("No");}
template<class T> void YESNO(T b){if(b)out("YES");else out("NO");}
template<class T> void outset(T s){auto itr=s.begin();while(itr!=s.end()){if(itr!=s.begin())cout<<' ';cout<<*itr;itr++;}cout<<'\n';}
void outs(ll a,ll b){if(a>=inf-100)out(b);else out(a);}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll modpow(ll a,ll b){ll res=1;a%=mod;while(b){if(b&1)res=res*a%mod;a=a*a%mod;b>>=1;}return res;}
class BipartiteMatching {
	int N, M;
	vector<vector<int>> G;
	vector<bool> used;
	vector<int> p, q;
	bool dfs(int v) {
		if (used[v]) return false;
		used[v] = true;
		for (auto u : G[v]) {
			if (q[u] == -1 || dfs(q[u])) {
				q[u] = v;
				p[v] = u;
				return true;
			}
		}
		return false;
	}
public:
	BipartiteMatching(int n, int m, const vector<vector<int>>& g) : N(n), M(m), G(g), used(N), p(N, -1), q(M, -1) {}
	BipartiteMatching(int n, int m) : N(n), M(m), G(n), used(N), p(N, -1), q(M, -1) {}
	void add_edge(int s, int t) {
		G[s].push_back(t);
	}
	int solve() {
		int res = 0;
		bool flag = true;
		fill(p.begin(), p.end(), -1);
		fill(q.begin(), q.end(), -1);
		fill(used.begin(), used.end(), false);
		while (flag) {
			flag = false;
			for (int i = 0; i < N; ++i) {
				if (p[i] == -1 && dfs(i)) {
					flag = true;
					++res;
				}
			}
			if (flag) {
				fill(used.begin(), used.end(), false);
			}
		}
		return res;
	}
	vector<pair<int, int>> edges() const {
		vector<pair<int, int>> res;
		for (size_t i = 0; i < N; ++i) {
			if (p[i] != -1) {
				res.emplace_back(i, p[i]);
			}
		}
		return res;
	}
};
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
        ll n,m;cin>>n>>m;
        vi v(n);rep(i,n)cin>>v[i];
        vi a,b;
        rep(i,n){
            if(v[i]*3>m)a.pb(v[i]);
            else b.pb(v[i]);
        }
        BipartiteMatching G(a.size(),b.size());
        rep(i,a.size())rep(j,b.size())if(a[i]%b[j]==0&&a[i]*2+b[j]<=m)G.add_edge(i,j);
        if(G.solve()!=a.size())out(-1);
        else{
            vp ans;
            auto e=G.edges();
            vb done(b.size(),false);
            for(auto x:e){
                done[x.se]=true;
                ans.pb(a[x.fi]*2+b[x.se],a[x.fi]+b[x.se]);
            }
            rep(i,b.size())if(!done[i])ans.pb(b[i]*3,b[i]*2);
            out(ans.size());
            for(auto x:ans)cout<<x.fi<<' '<<x.se<<endl;
        }
}