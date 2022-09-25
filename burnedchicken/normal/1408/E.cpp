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
const int MOD=Mod;
const int maxn=100005;
//i_am_noob
int n,m,a[maxn],b[maxn],k,sum=0,c[maxn];
vector<int> vec[maxn];
vector<pii> vec1;

struct dsu{
    vector<int> fa,siz;
    dsu(int _siz){
        fa.resize(_siz),siz.resize(_siz);
        rep(_siz) fa[i]=i,siz[i]=1;
    }
    int Find(int _x){return fa[_x]==_x?_x:fa[_x]=Find(fa[_x]);}
    void Union(int _x, int _y){
        int _a=Find(_x),_b=Find(_y);
        if(_a==_b) return;
        if(siz[_a]<siz[_b]) swap(_a,_b);
        fa[_b]=_a;
        siz[_a]+=siz[_b];
    }
}d(maxn);

bool comp(pii i, pii j){return a[i.first]+b[i.second]>a[j.first]+b[j.second];}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> m >> n;
    rep(m) cin >> a[i];
    rep(n) cin >> b[i];
    rep(m){
        cin >> k;
        vec[i].resize(k);
        rep1(j,k) cin >> vec[i][j];
        rep1(j,k) vec[i][j]--;
    }
    rep(m) c[i]=-1;
    rep(m) for(auto j: vec[i]){
        sum+=a[i]+b[j];
        vec1.pb({i,j});
    }
    sort(all(vec1),comp);
    for(auto p: vec1){
        if(c[p.first]==-1){
            c[p.first]=p.second;
            sum-=a[p.first]+b[p.second];
        }
        else{
            if(d.Find(p.second)!=d.Find(c[p.first])){
                d.Union(p.second,c[p.first]);
                sum-=a[p.first]+b[p.second];
            }
        }
    }
    print1(sum);
    return 0;
}