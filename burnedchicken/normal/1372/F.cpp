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
const int MOD=Mod;

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
int n,a[maxn];
set<int> st;
map<int,int> mm;

pii query(int l, int r){
    print3("?",l+1,r+1);
    cout << flush;
    pii ret;
    cin >> ret.first >> ret.second;
    return ret;
}

void solve(int l, int r){
    if(l>r) return;
    pii tmp=query(l,r);
    if(tmp.second==r-l+1){
        rep2(i,l,r+1) a[i]=tmp.first;
        return;
    }
    if(mm.count(tmp.first)){
        int k=mm[tmp.first];
        mm.erase(tmp.first);
        pii tmp1=query(max(0ll,k-tmp.second+1),k);
        if(tmp1.first==tmp.first){
            rep2(i,k-tmp1.second+1,k-tmp1.second+1+tmp.second) a[i]=tmp.first;
            solve(l,k-tmp1.second);
            solve(k-tmp1.second+tmp.second+1,r);
            return;
        }
        tmp1=query(k+1,min(n-1,k+tmp.second));
        rep2(i,k+tmp1.second-tmp.second+1,k+tmp1.second+1) a[i]=tmp.first;
        solve(l,k+tmp1.second-tmp.second);
        solve(k+tmp1.second+1,r);
        return;
    }
    int x,y,mid;
    pii tmp2;
    if(mm.lower_bound(tmp.first)==mm.end()) y=r;
    else y=min(r,(*mm.lower_bound(tmp.first)).second-1);
    if(mm.empty()||mm.lower_bound(tmp.first)==mm.begin()) x=l;
    else x=max(l,(*--mm.lower_bound(tmp.first)).second+1);
    while(x<=y){
        mid=x+y>>1;
        tmp2=query(mid,mid);
        if(tmp2.first==tmp.first){
            pii tmp1=query(max(0ll,mid-tmp.second+1),mid);
            if(tmp1.first==tmp.first){
                rep2(i,mid-tmp1.second+1,mid-tmp1.second+1+tmp.second) a[i]=tmp.first;
                solve(l,mid-tmp1.second);
                solve(mid-tmp1.second+tmp.second+1,r);
                return;
            }
            tmp1=query(mid+1,min(n-1,mid+tmp.second));
            rep2(i,mid+tmp1.second-tmp.second+1,mid+tmp1.second+1) a[i]=tmp.first;
            solve(l,mid+tmp1.second-tmp.second);
            solve(mid+tmp1.second+1,r);
            return;
        }
        mm[tmp2.first]=mid;
        if(tmp2.first>tmp.first) y=mid-1;
        else x=mid+1;
    }
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    solve(0,n-1);
    print0("!");
    rep(n) print0(a[i]);
    cout << endl;
    return 0;
}