#include <bits/stdc++.h>
#include <bits/extc++.h>

#define int long long
#define ull unsigned long long
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
//#define inf 2000000000
#define inf 8000000000000000000
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
const int maxn=505;
//i_am_noob
int n,u,v,a[maxn],ord[maxn],siz[maxn],G,k,sum;
vector<int> vec,adj[maxn];
vector<pii> e,vec1;
set<int> st;

int query(int u, vector<int> vec, int v){
    print1(1),print1(u+1),print1(sz(vec));
    for(auto i: vec) print0(i+1);
    cout << "\n";
    print1(v+1);
    cout << flush;
    int res;
    cin >> res;
    return res;
}

void add_edge(int u, int v){
    adj[u].pb(v),adj[v].pb(u);
    e.pb({u,v});
}

void dfs1(int u, int pa){
    siz[u]=1;
    for(auto v: adj[u]) if(v!=pa&&st.count(v)){
        dfs1(v,u);
        siz[u]+=siz[v];
    }
}

int findG(int u, int pa){
    for(auto v: adj[u]) if(v!=pa&&st.count(v)&&siz[v]>sz(st)/2) return findG(v,u);
    return u;
}

void dfs2(int u, int pa){
    vec.pb(u);
    for(auto v: adj[u]) if(v!=pa&&st.count(v)) dfs2(v,u);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    rep2(i,1,n) vec.pb(i);
    rep2(i,1,n) a[i]=query(0,vec,i);
    rep2(i,1,n) ord[i]=i;
    sort(ord+1,ord+n,[&](int i, int j){return a[i]>a[j];});
    rep2(i,1,n){
        st.clear();
        rep1(j,i) st.insert(ord[j]);
        while(1){
            if(sz(st)==1){
                add_edge(ord[i],*st.begin());
                break;
            }
            if(sz(st)==2){
                if(query(ord[i],{*st.begin()},*st.rbegin())) add_edge(ord[i],*st.rbegin());
                else add_edge(ord[i],*st.begin());
                break;
            }
            dfs1(*st.begin(),-1);
            G=findG(*st.begin(),-1);
            dfs1(G,-1);
            vec1.clear();
            for(auto u: adj[G]) if(st.count(u)) vec1.pb({siz[u],u});
            sort(all(vec1));
            sum=0;
            rep1(j,sz(vec1)){
                sum+=vec1[j].first;
                if(sum*3>=(sz(st)-1)){
                    k=j;
                    break;
                }
            }
            vec.clear();
            rep1(j,k+1) dfs2(vec1[j].second,G);
            if(query(ord[i],vec,G)==sz(vec)) for(auto u: vec) st.erase(u);
            else{
                st.clear();
                st.insert(G);
                for(auto u: vec) st.insert(u);
            }
        }
    }
    print1("ANSWER");
    rep(n-1) print2(e[i].first+1,e[i].second+1);
    cout << flush;
    return 0;
}