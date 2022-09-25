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

const int maxn=200005;
//i_am_noob
int n,q,x,y,l,cnt[maxn],seed[5][maxn],invseed[5][maxn],noob[maxn][5],k[4];
string str;
vector<int> vec,vec1;
bool flag;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n >> str;
    cnt[0]=0;
    rep(n){
        cnt[i+1]=cnt[i];
        if(str[i]=='0'){
            cnt[i+1]++;
            vec.pb(i);
        }
    }
    rep(sz(vec)-1) vec1.pb((vec[i+1]-vec[i]-1)%2);
    rep(5) seed[i][0]=1;
    rep(5) seed[i][1]=rng()%MOD;
    rep2(i,2,maxn) rep1(j,5) seed[j][i]=seed[j][i-1]*seed[j][1]%MOD;
    rep(maxn) rep1(j,5) invseed[j][i]=inverse(seed[j][i]);
    rep(5) noob[0][i]=0;
    rep(sz(vec1)) rep1(j,5) noob[i+1][j]=add(noob[i][j],vec1[i]*seed[j][i]%MOD);
    cin >> q;
    while(q--){
        cin >> x >> y >> l;
        x--,y--;
        if(cnt[x+l]-cnt[x]!=cnt[y+l]-cnt[y]){
            print1("No");
            continue;
        }
        if(cnt[x+l]-cnt[x]==0&&cnt[y+l]-cnt[y]==0){
            print1("Yes");
            continue;
        }
        k[0]=lower_bound(all(vec),x)-vec.begin();
        k[1]=upper_bound(all(vec),x+l-1)-vec.begin()-1;
        k[2]=lower_bound(all(vec),y)-vec.begin();
        k[3]=upper_bound(all(vec),y+l-1)-vec.begin()-1;
        if((vec[k[0]]-x)%2!=(vec[k[2]]-y)%2||(x+l-vec[k[1]])%2!=(y+l-vec[k[3]])%2){
            print1("No");
            continue;
        }
        flag=true;
        rep(5) if(sub(noob[k[1]][i],noob[k[0]][i])*invseed[i][k[0]]%MOD!=sub(noob[k[3]][i],noob[k[2]][i])*invseed[i][k[2]]%MOD) flag=false;
        print1(flag?"Yes":"No");
    }
	return 0;
}