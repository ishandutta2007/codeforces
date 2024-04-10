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

const int maxn=300005,mod=998244353;

bool isp[maxn];
int n,m,cur_sum,res;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    rep(i,2,maxn) isp[i]=1;
    rep(i,2,maxn) if(isp[i]) for(int j=2*i; j<maxn; j+=i) isp[j]=0;
    cin >> n >> m;
    cur_sum=res=m;
    res%=mod,cur_sum%=mod;
    int cur=1;
    rep(i,2,n+1){
        if(isp[i]) cur*=i;
        if(cur>m){
            cur_sum=0;
            break;
        }
        cur_sum=m/cur%mod*cur_sum%mod;
        res=(res+cur_sum)%mod;
    }
    int tot=m;
    cur_sum=m;
    tot%=mod,cur_sum%=mod;
    rep(i,0,n-1) cur_sum=cur_sum*(m%mod)%mod,tot=(tot+cur_sum)%mod;
    cout << (tot-res+mod)%mod << "\n";
}