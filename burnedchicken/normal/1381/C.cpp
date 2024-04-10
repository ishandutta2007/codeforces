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
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
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
int t,n,x,y,a[maxn],ans[maxn],k,swag,cnt;
vector<int> vec[maxn],vec1;
set<pii> st;

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> x >> y;
        rep(n) cin >> a[i];
        rep(n) {a[i]--;ans[i]=-1;}
        rep(n+1) vec[i].clear();
        rep(n) vec[a[i]].pb(i);
        st.clear();
        rep(n+1) st.insert(mp(sz(vec[i]),i));
        rep(n+1) if(vec[i].empty()){
            swag=i;
            break;
        }
        rep(x){
            k=(*st.rbegin()).second;
            ans[vec[k].back()]=a[vec[k].back()];
            vec[k].pop_back();
            st.erase(mp(sz(vec[k])+1,k));
            st.insert(mp(sz(vec[k]),k));
        }
        vec1.clear();
        rep(n+1) for(auto j: vec[i]) if(ans[j]==-1) vec1.pb(j);
        if(sz(vec1)==0){
            print1("YES");
            rep(n) print0(ans[i]+1);
            cout << "\n";
            continue;
        }
        k=(*st.rbegin()).first;
        if(2*k-sz(vec1)>n-y){
            print1("NO");
            continue;
        }
        rep(sz(vec1)) ans[vec1[(i+sz(vec1)/2)%sz(vec1)]]=a[vec1[i]];
        cnt=0;
        rep(sz(vec1)) if(a[vec1[i]]==ans[vec1[i]]) {ans[vec1[i]]=swag;cnt++;}
        rep(sz(vec1)){
            if(y+cnt==n) break;
            if(ans[vec1[i]]!=swag){
                ans[vec1[i]]=swag;
                cnt++;
            }
        }
        print1("YES");
        rep(n) print0(ans[i]+1);
        cout << "\n";
    }
	return 0;
}