#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i<(b); ++i)
#define per(i,a,b) for(int i=a; i>=(b); --i)
#define ll long long
#define int ll
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define inf 0x3f3f3f3f
#define pb push_back
#define sz(a) ((int)a.size())
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 777771449
#endif

const int maxn=1005,mod=998244353;

int n,f[maxn];

int get(int x){
    per(i,34,2) if(x>=f[i]) x-=f[i];
    return !x;
}

int is_fib(int x){
    rep(i,0,35) if(f[i]==x) return 1;
    return 0;
}

int add(int x, int y){x+=y;if(x>=mod) x-=mod;return x;}
int sub(int x, int y){x-=y;if(x<0) x+=mod;return x;}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    f[0]=f[1]=1;
    rep(i,2,35) f[i]=f[i-1]+f[i-2];
    cin >> n;
    vector<pii> vec;
    int tot=0,lst=1,sum=1;
    rep(_,0,n){
        string str;
        cin >> str;
        for(auto c: str){
            int x=c-'0';
            rep(i,0,sz(vec)){
                if(get(tot-vec[i].first)!=x) vec.erase(vec.begin()+i),i--;
            }
            int nval=sub(sum,lst);
            for(auto [pos,y]: vec) if(is_fib(tot-pos+1)) nval=sub(nval,y);
            if(x) vec.pb({tot,lst});
            sum=add(sum,nval);
            lst=nval;
            tot++;
        }
        cout << lst << "\n";
    }
}