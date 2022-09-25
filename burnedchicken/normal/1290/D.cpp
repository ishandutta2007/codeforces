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
const int MOD=Mod2;

inline int add(int a, int b){return (a+b>=MOD?a+b-MOD:a+b);}
inline int sub(int a, int b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
int Pow(int a, int b){
	if(!b) return 1;
	int tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
inline int inverse(int n){return Pow(n,MOD-2);}

const int maxn=1025;
//i_am_noob
int n,k,m,cnt=0;
vector<vector<int>> vec;
vector<int> vec1;
bool ok[maxn];

void query(vector<int> vec){
    char tmp;
    for(int i:vec){
        print2("?",i+1);
        cout << flush;
        cin >> tmp;
        if(tmp=='Y') ok[i]=false;
    }
    cout << "R" << endl;
}

void report(){
    int ans=0;
    rep(n) ans+=ok[i];
    print2("!",ans);
    cout << flush;
    exit(0);
}

void build(int n, int x){
    if(n==4){
        vec.pb({x,x+1,x+2,x+3});
        return;
    }
    if(n==8){
        rep(4) rep2(j,i+1,4) vec.pb({x+i,x+j,x+4+i,x+4+j});
        return;
    }
    if(n==16){
        rep(4) vec.pb({x+4*i,x+4*i+1,x+4*i+2,x+4*i+3});
        vec.pb({x,x+4,x+8,x+12});
        vec.pb({x,x+5,x+10,x+15});
        vec.pb({x,x+6,x+11,x+13});
        vec.pb({x,x+7,x+9,x+14});
        vec.pb({x+1,x+4,x+11,x+14});
        vec.pb({x+1,x+5,x+9,x+13});
        vec.pb({x+1,x+6,x+8,x+15});
        vec.pb({x+1,x+7,x+10,x+12});
        vec.pb({x+2,x+4,x+9,x+15});
        vec.pb({x+2,x+5,x+11,x+12});
        vec.pb({x+2,x+6,x+10,x+14});
        vec.pb({x+2,x+7,x+8,x+13});
        vec.pb({x+3,x+4,x+10,x+13});
        vec.pb({x+3,x+5,x+8,x+14});
        vec.pb({x+3,x+6,x+9,x+12});
        vec.pb({x+3,x+7,x+11,x+15});
        return;
    }
    int tmp=n/4+1;
    rep(tmp) rep1(j,tmp){
        vec1.clear();
        if(i!=tmp-1) vec1.pb(x+i);
        if(j!=tmp-1) vec1.pb(x+n/4+j);
        if((j+i)%tmp!=tmp-1) vec1.pb(x+n/4*2+(j+i)%tmp);
        if((j+2*i)%tmp!=tmp-1) vec1.pb(x+n/4*3+(j+2*i)%tmp);
        vec.pb(vec1);
    }
    rep(4) build(n/4,x+n/4*i);
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n >> k;
	rep(n) ok[i]=true;
	if(k==1){
        rep(n) rep2(j,i+1,n) query({i,j});
        report();
	}
	if(k==2){
        rep(n/2) rep2(j,i+1,n/2){
            query({i,j,i+n/2});
            query({i,i+n/2,j+n/2});
        }
        query({n/2-1,n-1});
        report();
	}
	build(n/k*4,0);
	rep1(ii,sz(vec)){
        m=sz(vec[ii]);
        rep2(i,1,k/4) rep1(j,m){
            vec[ii].pb(n/k*4*i+vec[ii][j]);
        }
	}
    /*
	for(auto vec2:vec){
        for(auto i:vec2) {print0(i);cnt++;}
        cout << "\n";
	}
	print1(cnt);
    rep(n) rep2(j,i+1,n) b[i][j]=false;
    for(auto vec2:vec) rep(sz(vec2)) rep2(j,i+1,sz(vec2)) b[vec2[i]][vec2[j]]=true;
    rep(n) rep2(j,i+1,n) if(!b[i][j]) print2(i,j);
    */

	for(auto vec2:vec) query(vec2);
	report();

	return 0;
}