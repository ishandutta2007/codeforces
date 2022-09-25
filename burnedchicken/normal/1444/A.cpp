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
#define inf 4000000000000000000
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
int t,n,m,k,cnt,ans;
vector<pii> vec;
vector<int> vec1;

int lpd[maxn];
vector<int> prime;

void find_prime(){
	rep(maxn) lpd[i]=-1;
    rep2(i,2,maxn){
        if(lpd[i]==-1){
            prime.pb(i);
            lpd[i]=i;
            for(int j=i*i; j<maxn; j+=i) if(lpd[j]==-1) lpd[j]=i;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    find_prime();
    cin >> t;
    while(t--){
        cin >> n >> m;
        if(n%m){
            print1(n);
            continue;
        }
        vec.clear();
        vec1.clear();
        for(auto p: prime){
            if(m%p==0){
                vec.pb({p,0});
                while(m%p==0) vec.back().second++,m/=p;
                vec1.pb(0);
                k=n;
                while(k%p==0) vec1.back()++,k/=p;
            }
        }
        if(m>1){
            vec.pb({m,1});
            k=n;
            vec1.pb(0);
            while(k%m==0) vec1.back()++,k/=m;
        }
        ans=-1;
        rep(sz(vec)){
            k=n;
            rep1(j,vec1[i]-vec[i].second+1) k/=vec[i].first;
            ans=max(ans,k);
        }
        print1(ans);
    }
    return 0;
}