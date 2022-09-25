#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
#define pi 3.14159265358979323846264338328
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
#ifdef i_am_noob
#define debug(a) print2(#a,a)
#else
#define debug(a)
#endif
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;

inline int add(int a, int b){return (a+b>=MOD?a+b-MOD:a+b);}
inline int sub(int a, int b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
int Pow(int a, int b){
	if(!b) return 1;
	int tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
inline int inverse(int n){return Pow(n,MOD-2);}

const int maxn=200005;
//i_am_noob
int n,m,pos[maxn],x,y,ans=0;
vector<int> vec[maxn];

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
}noob(maxn);

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m;
    rep(n) cin >> pos[i];
    rep(n) pos[i]--;
    rep(n) vec[pos[i]].pb(i);
    rep(n) noob.siz[i]=sz(vec[i]);
    rep(n-1) ans+=pos[i]!=pos[i+1];
    print1(ans);
    rep1(_,m-1){
        cin >> x >> y;
        x=noob.Find(x-1),y=noob.Find(y-1);
        if(sz(vec[x])<sz(vec[y])) swap(x,y);
        noob.Union(x,y);
        for(auto i: vec[y]){
            if(i!=n-1) if(pos[i+1]==x) ans--;
            if(i!=0) if(pos[i-1]==x) ans--;
        }
        for(auto i: vec[y]){
            pos[i]=x;
            vec[x].pb(i);
        }
        vec[y].clear();
        print1(ans);
    }
    return 0;
}