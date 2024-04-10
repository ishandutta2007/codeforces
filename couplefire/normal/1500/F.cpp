#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define f first
#define s second

const int N = 1000005;

ll n, C, w[N], ans[N], dir = 1, shif = 0, huh[N];
deque<pll> dq;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> C;
    for(int i = 0; i<n-2; ++i)
        cin >> w[i];
    dq.push_back({0, C});
    for(int i = 0; i<n-2; ++i){
        while(dq.size() && (dir>0?dq.back().f:dq.front().s)*dir+shif>w[i])
            dir>0?dq.pop_back():dq.pop_front();
        if(dq.empty()){cout << "NO" << '\n'; exit(0);}
        if((dir>0?dq.back().s:dq.front().f)*dir+shif>w[i])
            (dir>0?dq.back().s:dq.front().f) = (w[i]-shif)/dir;
        if((dir>0?dq.back().s:dq.front().f)*dir+shif==w[i]){
            dq.clear(); huh[i] = -1;
            dir>0?dq.push_back({(0-shif)/dir, (w[i]-shif)/dir}):dq.push_front({(w[i]-shif)/dir, (0-shif)/dir});
        }
        else{
            huh[i] = (dir>0?dq.back().s:dq.front().f)*dir+shif;
            dir *= -1, shif = w[i]-shif;
            ll tmp = (w[i]-shif)/dir;
            if((dir>0?dq.back().s:dq.front().f)*dir+shif<w[i]-1)
                dir>0?dq.push_back({tmp, tmp}):dq.push_front({tmp, tmp});
            else dir>0?dq.back().s = tmp:dq.front().f = tmp;
        }
    }
    cout << "YES" << '\n';
    ans[n-2] = (dir>0?dq.back().s:dq.front().f)*dir+shif;
    bool sgn = 0;
    for(int i = n-3; i>=0; --i){
        if(huh[i]==-1) sgn ^= 1, ans[i] = sgn?-w[i]:w[i];
        else if(abs(ans[i+1])==w[i]) sgn ^= 1, ans[i] = sgn?-huh[i]:huh[i];
        else ans[i] = sgn?-w[i]-ans[i+1]:w[i]-ans[i+1];
    }
    for(int i = n-1; i>=1; --i)
        ans[i] = ans[i-1];
    ans[0] = 0;
    for(int i = 1; i<n; ++i)
        ans[i] += ans[i-1];
    ll mn = 1e18;
    for(int i = 0; i<n; ++i)
        mn = min(mn, ans[i]);
    for(int i = 0; i<n; ++i)
        cout << ans[i]-mn << ' ';
    cout << '\n';
}