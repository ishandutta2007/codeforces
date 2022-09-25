#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
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

const int maxn=100005;
//i_am_noob
const int K=342;
int n,m,k,X,b[maxn],a[maxn],cnt[pow2(20)],l,r,posl,posr;
ll arr[maxn][305],ans;
unordered_map<int,int> mm;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m >> k;
    rep(n) cin >> b[i];
    a[0]=0;
    rep(n) a[i+1]=a[i]^b[i];
    n++;
    X=ceiling(n,K);
    rep(X){
        memset(cnt,0,sizeof(cnt));
        if(i>0) arr[i*K-1][i]=0;
        rep2(j,i*K,n){
            arr[j][i]=(j==0?0:arr[j-1][i])+cnt[a[j]^k];
            cnt[a[j]]++;
        }
    }
    rep(X){
        memset(cnt,0,sizeof(cnt));
        arr[min(n,i*K+K)][i+1]=0;
        rep3(j,min(n-1,i*K+K-1),0){
            arr[j][i+1]=arr[j+1][i+1]+cnt[a[j]^k];
            cnt[a[j]]++;
        }
    }
    while(m--){
        cin >> l >> r;
        l--;
        posl=l/K,posr=r/K;
        if(posl==posr){
            mm.clear();
            ans=0;
            rep2(i,l,r+1) mm[a[i]]++;
            rep2(i,l,r+1) ans+=mm[a[i]^k];
            if(!k) ans-=r-l+1;
            ans/=2;
            print1(ans);
            continue;
        }
        ans=arr[l][posr]+arr[r][posl+1]-arr[posr*K-1][posl+1];
        mm.clear();
        rep2(i,posr*K,r+1) mm[a[i]]++;
        rep2(i,l,posl*K+K) ans+=mm[a[i]^k];
        print1(ans);
    }
    return 0;
}