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

const int maxn=300005;
//i_am_noob
int n,k,x,y,a,b,cnt1[maxn],cnt2[maxn],ans=0;
string str;
vector<int> vec[maxn];
bool state[maxn],good[maxn],same[maxn],flag;

int fa[maxn];
vector<int> child[maxn];
int Find(int x){return fa[x]==x?x:x=Find(fa[x]);}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n >> k >> str;
	rep(k){
	    cin >> x;
	    while(x--){
            cin >> y;
            vec[y-1].pb(i);
	    }
	}
    rep(k){
        fa[i]=i;
        child[i]={i};
        good[i]=true;
        state[i]=false;
        same[i]=true;
        cnt1[i]=1;
        cnt2[i]=0;
    }
    rep(n){
        if(vec[i].empty()){
            print1(ans);
            continue;
        }
        if(sz(vec[i])==1){
            a=vec[i][0];
            x=Find(a);
            good[x]=false;
            if((str[i]=='0')==(state[x]^same[a])){
                //print1(i);
                state[x]=1-state[x];
                ans+=cnt1[x]-cnt2[x];
                swap(cnt1[x],cnt2[x]);
            }
            //rep1(j,k) print0(1-(state[Find(j)]^same[j]));
            //cout << "\n";
            print1(ans);
            continue;
        }
        a=vec[i][0],b=vec[i][1];
        x=Find(a),y=Find(b);
        if(x==y){
            print1(ans);
            continue;
        }
        if(sz(child[x])<sz(child[y])) swap(a,b),swap(x,y);
        fa[y]=x;
        if((str[i]=='1')==(state[x]^same[a]^state[y]^same[b])){
            //print1(i);
            if(!good[x]) flag=true;
            else if(!good[y]) flag=false;
            else if(cnt1[x]+cnt2[y]>cnt1[y]+cnt2[x]) flag=true;
            else flag=false;
            if(flag){
                ans+=cnt1[y]-cnt2[y];
                if(state[x]==state[y]) for(auto j:child[y]) same[j]=1-same[j];
                cnt1[x]+=cnt2[y],cnt2[x]+=cnt1[y];
            }
            else{
                if(!good[y]) good[x]=false;
                ans+=cnt1[x]-cnt2[x];
                state[x]=1-state[x];
                if(state[x]!=state[y]) for(auto j:child[y]) same[j]=1-same[j];
                swap(cnt1[x],cnt2[x]);
                cnt1[x]+=cnt1[y],cnt2[x]+=cnt2[y];
            }
        }
        else{
            if(state[x]!=state[y]) for(auto j:child[y]) same[j]=1-same[j];
            cnt1[x]+=cnt1[y];
            cnt2[x]+=cnt2[y];
            if(!good[y]) good[x]=false;
        }
        //rep1(j,k) print0(1-(state[Find(j)]^same[j]));
        //cout << "\n";
        for(auto j:child[y]) child[x].pb(j);
        child[y].clear();
        print1(ans);
    }
	return 0;
}