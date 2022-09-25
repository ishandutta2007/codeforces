#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,tune=native")

#define ll long long
#define int ll
#define ull unsigned ll
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define chkmin(a,b) (a=min(a,b))
#define chkmax(a,b) (a=max(a,b))
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
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(vector<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(set<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(unordered_set<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

template<int maxn>
struct NT{
    vector<int> pr;
    int lpd[maxn];
    NT(){
        pr.clear();
        rep(maxn) lpd[i]=-1;
        rep2(i,2,maxn){
            if(lpd[i]==-1) lpd[i]=i,pr.pb(i);
            for(auto p: pr){
                if(p*i>=maxn) break;
                lpd[p*i]=p;
                if(i%p==0) break;
            }
        }
    }
    inline bool isp(int x){return lpd[x]==x;}
    signed fac_cnt(signed x){
        assert(x>=1&&x<maxn);
        signed res=1,lst=0,cur=0;
        while(x>1){
            signed p=lpd[x];
            if(p!=lst) res*=cur+1,cur=0;
            cur++;
            lst=p;
            x/=p;
        }
        return res*(cur+1);
    }
};
const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
const int maxn=1000000049,maxm=7777714,maxk=7777714;

//i_am_noob
//#define wiwihorz  
char dis1[maxn>>4],dis2[maxn>>4];
map<signed,signed> par1,par2;
int p=1000000007,david=-1;
bool vis1[maxn>>4],vis2[maxn>>4];
queue<int> q1,q2;
ykh;
int inverse(int x){
    int res=1,b=p-2;
    while(b){
        if(b&1) res=res*x%p;
        x=x*x%p,b>>=1;
    }
    return res;
}

int k;

vector<int> res;

void op(int x){
    if(x==1) k=(k+1)%p;
    else if(x==2) k=(k+p-1)%p;
    else k=inverse(k);
    res.pb(x);
}

void orzck(){
    int a,b;
    cin >> a >> b >> p;
    k=a;
    vis1[a>>4]=1;
    q1.push(a>>4);
    par1[a>>4]=-1;
    vis2[b>>4]=1;
    q2.push(b>>4);
    par2[b>>4]=-1;
    bool flag=0;
    while(1){
        int u1=q1.front();
        int u2=q2.front();
        if(u1==u2){
            david=u1;
            break;
        }
        if(min(dis1[u1],dis2[u2])==5) break;
        if(dis1[u1]<dis2[u2]){
            q1.pop();
            rep2(i,u1<<4,u1+1<<4){
                if(i==p) break;
                int v=inverse(i);
                if(!vis1[v>>4]){
                    vis1[v>>4]=1;
                    q1.push(v>>4);
                    dis1[v>>4]=dis1[u1]+1;
                    par1[v>>4]=u1;
                    if(vis2[v>>4]){
                        flag=1;
                        david=v>>4;
                        break;
                    }
                }
            }
            if(flag) break;
        }
        else{
            q2.pop();
            rep2(i,u2<<4,u2+1<<4){
                if(i==p) break;
                int v=inverse(i);
                if(!vis2[v>>4]){
                    vis2[v>>4]=1;
                    q2.push(v>>4);
                    dis2[v>>4]=dis2[u2]+1;
                    par2[v>>4]=u2;
                    if(vis1[v>>4]){
                        flag=1;
                        david=v>>4;
                        break;
                    }
                }
            }
            if(flag) break;
        }
    }
    bug(flag);
    vector<int> vec;
    for(int i=david; i!=-1; i=par1[i]) vec.pb(i);
    reverse(all(vec));
    vec.pop_back();
    for(int i=david; i!=-1; i=par2[i]) vec.pb(i);
    vector<int> vec2;
    vec2.pb(a);
    rep(sz(vec)-1){
        bool flag=0;
        rep2(j1,vec[i]<<4,min(p,vec[i]+1<<4)){
            rep2(j2,vec[i+1]<<4,min(p,vec[i+1]+1<<4)){
                if(j1*j2%p==1){
                    vec2.pb(j1),vec2.pb(j2);
                    flag=1;
                    break;
                }
            }
            if(flag) break;
        }
    }
    vec2.pb(b);
    bug(vec2);
    rep(sz(vec2)-1){
        if(vec2[i]*vec2[i+1]%p==1){
            op(3);
        }
        else{
            assert(abs(vec2[i]-vec2[i+1])<16);
            if(vec2[i+1]>vec2[i]) rep1(de,vec2[i+1]-vec2[i]) op(1);
            else rep1(de,vec2[i]-vec2[i+1]) op(2);
        }
    }
    assert(k==b);
    print(sz(res));
    for(auto i: res) print0(i);
    cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    freopen("output2.txt","w",stderr);
    #endif
    cout << fixed << setprecision(15);
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    while(t--) orzck();
    return 0;
}