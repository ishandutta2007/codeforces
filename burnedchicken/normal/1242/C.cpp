#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,tune=native")

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
const int MOD=Mod2;
const int maxn=400005;
//i_am_noob
int n,m[20],a[20][5005],b1[20][5005],b2[20][5005],sum[20],ans1[20],ans2[20],tot,sol1[pow2(15)+5][20],sol2[pow2(15)+5][20],x;
vector<pair<int,pii>> vec,vec1;
bool found[pow2(15)+5],vis[20];

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif
    cin >> n;
    rep(n){
        cin >> m[i];
        rep1(j,m[i]){
            cin >> a[i][j];
            tot+=a[i][j];
            sum[i]+=a[i][j];
            vec.pb({a[i][j],{i,j}});
        }
    }
    sort(all(vec));
    if(tot%n){
        print("No");
        return 0;
    }
    tot/=n;
    rep(n){
        rep1(j,m[i]){
            auto it=lower_bound(all(vec),pair<int,pii>(a[i][j]+tot-sum[i],{-1ll,-1ll}));
            if((*it).first!=a[i][j]+tot-sum[i]) b1[i][j]=b2[i][j]=-1;
            else b1[i][j]=(*it).second.first,b2[i][j]=(*it).second.second;
        }
    }
    rep(n){
        rep1(j,m[i]){
            vec1.clear();
            rep1(k,n) vis[k]=false;
            pii p={i,j},q;
            bool flag;
            x=0;
            vis[i]=true;
            while(1){
                if(b1[p.first][p.second]==-1){
                    flag=false;
                    break;
                }
                q={b1[p.first][p.second],b2[p.first][p.second]};
                vec1.pb({q.first,{a[q.first][q.second],p.first}});
                x|=pow2(q.first);
                if(q.first==i){
                    flag=q.second==j;
                    break;
                }
                if(vis[q.first]){
                    flag=false;
                    break;
                }
                vis[q.first]=true;
                p=q;
            }
            if(flag){
                bug(i,j,x);
                found[x]=true;
                for(auto p: vec1){
                    bug(p.first,p.second.first,p.second.second);
                    sol1[x][p.first]=p.second.first,sol2[x][p.first]=p.second.second;
                }
            }
        }
    }
    rep2(i,1,pow2(n)){
        if(found[i]) continue;
        for(int mask=i; mask; mask=(mask-1)&i) if(found[mask]&&found[i^mask]){
            rep1(j,n){
                if(mask&pow2(j)) sol1[i][j]=sol1[mask][j],sol2[i][j]=sol2[mask][j];
                if((i^mask)&pow2(j)) sol1[i][j]=sol1[i^mask][j],sol2[i][j]=sol2[i^mask][j];
            }
            found[i]=true;
            break;
        }
    }
    if(!found[pow2(n)-1]){
        print("No");
        return 0;
    }
    print("Yes");
    rep(n) print(sol1[pow2(n)-1][i],sol2[pow2(n)-1][i]+1);
    return 0;
}