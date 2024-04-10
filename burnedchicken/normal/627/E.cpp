#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define rep(i,a,b) for(int i=a; i<(b); ++i)
#define per(i,a,b) for(int i=a; i>=(b); --i)
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
#define sz(a) ((int)a.size())
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 777771449
#endif

const int maxn=3005;
int R,C,n,k,res;
pii p[maxn];
vector<int> vec[maxn];

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> R >> C >> n >> k;
    rep(i,0,n) cin >> p[i].first >> p[i].second,p[i].first--,p[i].second--;
    sort(p,p+n);
    rep(i,0,n) vec[p[i].first].pb(p[i].second);
    rep(i,0,n){
        int cnt=0,cntmid=0;
        vector<int> l={p[i].second,-1},r={p[i].second,C};
        per(j,p[i].first,0){
            for(auto y: vec[j]){
                if(j<p[i].first||y<=p[i].second){
                    if(y==p[i].second) cntmid++;
                    else if(y<p[i].second){
                        auto it=lower_bound(l.begin(),l.end(),y,greater<int>());
                        l.insert(it,y);
                        if(l.size()>k+1) l.pop_back();
                    }
                    else{
                        auto it=lower_bound(r.begin(),r.end(),y);
                        r.insert(it,y);
                        if(r.size()>k+1) r.pop_back();
                    }
                }
            }
            rep(ii,0,sz(l)-1){
                int jj=k-cntmid-ii;
                if(jj<0||jj>=sz(r)-1) continue;
                cnt+=(l[ii]-l[ii+1])*(r[jj+1]-r[jj]);
            }
        }
        cnt*=R-p[i].first;
        res+=cnt;
    }
    cout << res << "\n";
}