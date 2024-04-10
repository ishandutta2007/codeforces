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

const int maxn=55;
//i_am_noob
int t,n,m,x,y,dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
vector<pii> vec;
queue<pii> q;
char c[maxn][maxn];
bool flag,vis[maxn][maxn],b[maxn][maxn];

bool valid(int i, int j){return i>=0&&i<n&&j>=0&&j<m;}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        rep(n) rep1(j,m) cin >> c[i][j];
        vec.clear();
        rep(n) rep1(j,m) if(c[i][j]=='G') vec.pb(mp(i,j));
        if(vec.empty()){
            print1("Yes");
            continue;
        }
        flag=true;
        rep(n) rep1(j,m) if(c[i][j]=='B') rep1(ii,4){
            x=i+dx[ii],y=j+dy[ii];
            if(valid(x,y)){
                if(c[x][y]=='G') flag=false;
                if(c[x][y]=='.') c[x][y]='#';
            }
        }
        if((!flag)||c[n-1][m-1]=='#'){
            print1("No");
            continue;
        }
        rep(n) rep1(j,m) vis[i][j]=b[i][j]=false;
        q.push(mp(n-1,m-1));
        vis[n-1][m-1]=true;
        while(!q.empty()){
            rep1(ii,4){
                x=q.front().first+dx[ii],y=q.front().second+dy[ii];
                if(valid(x,y)){
                    if(vis[x][y]||c[x][y]=='#') continue;
                    b[x][y]=true;
                    q.push(mp(x,y));
                    vis[x][y]=true;
                }
            }
            q.pop();
        }
        flag=true;
        for(auto p: vec) if(!b[p.first][p.second]) flag=false;
        print1(flag?"Yes":"No");
    }
    return 0;
}