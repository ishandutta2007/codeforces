#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 200005;

int n, m;
int arr[N], events[N], ans[N];

struct node{
    int l, r, tot, dead;
    bool operator < (const node& o) const{
        return l < o.l;
    }
};

set<node> nodes;
set<pair<int, node>, greater<>> st;
multiset<int, greater<>> lens;

signed main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<n; i++)
        cin >> arr[i];
    for(int i = 0; i<n; i++)
        nodes.insert({i, i, arr[i], i==n-1?0:arr[i]-1}),
        st.insert({i==n-1?0:arr[i]-1, {i, i, arr[i], i==n-1?0:arr[i]-1}}),
        lens.insert(0);
    for(int i = 0; i<m; i++)
        cin >> events[i];
    reverse(events, events+m);
    for(int i = 0; i<m; i++){
        int num = events[i];
        while(st.begin()->first >= num){
            node cur = st.begin()->second; st.erase(st.begin());
            node nxt = *nodes.upper_bound(cur);
            nodes.erase(cur); nodes.erase(nxt);
            st.erase({nxt.dead, nxt});
            lens.erase(lens.find(cur.r-cur.l));
            lens.erase(lens.find(nxt.r-nxt.l));
            node tmp; tmp.l = cur.l, tmp.r = nxt.r;
            tmp.tot = cur.tot+nxt.tot;
            if(tmp.r == n-1) tmp.dead = 0;
            else tmp.dead = (tmp.tot-1)/(tmp.r-tmp.l+1);
            nodes.insert(tmp); st.insert({tmp.dead, tmp});
            lens.insert(tmp.r-tmp.l);
        }
        ans[i] = *lens.begin();
    }
    reverse(ans, ans+m);
    for(int i = 0; i<m; i++)
        cout << ans[i] << " ";
    cout << '\n';
}