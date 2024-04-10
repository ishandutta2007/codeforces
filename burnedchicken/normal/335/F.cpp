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

const int maxn=500005;

int n,a[maxn];

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    rep(i,0,n) cin >> a[i];
    sort(a,a+n,greater<int>());
    priority_queue<int,vector<int>,greater<int>> pq;
    int cnt=1,lst=0;
    rep(i,0,n){
        if(i<n-1&&a[i]==a[i+1]){
            cnt++;
            continue;
        }
        vector<pii> vec;
        int tmp=min(lst-sz(pq)*2,cnt);
        while(sz(pq)){
            int diff=min(lst-(sz(pq)-1)*2,cnt)-tmp;
            if(diff==0) break;
            vec.pb({pq.top(),diff});
            pq.pop();
            tmp+=diff;
        }
        while(sz(vec)&&vec.back().first>a[i]){
            pq.push(vec.back().first);
            if(vec.back().second==2) pq.push(2*a[i]-vec.back().first);
            tmp-=vec.back().second;
            vec.pop_back();
        }
        rep(j,0,tmp) pq.push(a[i]);
        lst+=cnt;
        cnt=1;
    }
    int res=accumulate(a,a+n,0ll);
    while(!pq.empty()){
        if(pq.top()>0) res-=pq.top();
        pq.pop();
    }
    cout << res << "\n";
}