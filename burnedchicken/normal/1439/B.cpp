#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

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
//#define inf 1010000000
#define inf 4000000000000000000
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;
const int maxn=100005;
//i_am_noob
int t,n,m,k,u,v,e[maxn][2],mindeg,arr[maxn];
unordered_set<int> adj[maxn];
set<pii> degset;
vector<int> vec,vec1;
bool adj2[6005][6005],flag;

void Erase(int u){
    for(auto v: adj[u]){
        degset.erase({sz(adj[v]),v});
        adj[v].erase(u);
        degset.insert({sz(adj[v]),v});
    }
    degset.erase({sz(adj[u]),u});
    adj[u].clear();
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        rep(n) adj[i].clear();
        rep(m){
            cin >> u >> v;
            u--,v--;
            e[i][0]=u,e[i][1]=v;
            adj[u].insert(v),adj[v].insert(u);
        }
        degset.clear();
        rep(n) degset.insert({sz(adj[i]),i});
        flag=false;
        rep1(_,n){
            u=(*degset.begin()).second,mindeg=(*degset.begin()).first;
            if(mindeg<k-1) Erase(u);
            else if(mindeg>=k){
                print(1,sz(degset));
                for(auto& [x,y]: degset) print0(y+1);
                cout << "\n";
                flag=true;
                break;
            }
            else{
                vec.clear();
                for(auto& [x,y]: degset) vec.pb(y);
                break;
            }
        }
        if(flag) continue;
        if(degset.empty()){
            print(-1);
            continue;
        }
        if(k>=40){
            rep(sz(vec)) arr[vec[i]]=i;
            rep(sz(vec)) memset(adj2[i],0,sz(vec));
            rep(m) if(sz(adj[e[i][0]])>=1&&sz(adj[e[i][1]])>=1) adj2[arr[e[i][0]]][arr[e[i][1]]]=true,adj2[arr[e[i][1]]][arr[e[i][0]]]=true;
        }
        rep1(_,n+1){
            if(degset.empty()){
                print(-1);
                break;
            }
            u=(*degset.begin()).second,mindeg=(*degset.begin()).first;
            if(mindeg>=k){
                print(1,sz(degset));
                for(auto& [x,y]: degset) print0(y+1);
                cout << "\n";
                break;
            }
            if(mindeg<k-1){
                Erase(u);
                continue;
            }
            vec1.clear();
            for(auto v: adj[u]) vec1.pb(v);
            flag=true;
            if(k>=40){
                rep(sz(vec1)) rep2(j,i+1,sz(vec1)){
                    if(!adj2[arr[vec1[i]]][arr[vec1[j]]]){
                        flag=false;
                        break;
                    }
                }
            }
            else{
                rep(sz(vec1)) rep2(j,i+1,sz(vec1)){
                    if(!adj[vec1[i]].count(vec1[j])){
                        flag=false;
                        break;
                    }
                }
            }
            if(!flag) Erase(u);
            else{
                print(2);
                print0(u+1);
                for(auto i: vec1) print0(i+1);
                cout << "\n";
                break;
            }
        }
    }
    return 0;
}