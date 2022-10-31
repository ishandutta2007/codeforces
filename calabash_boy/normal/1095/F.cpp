#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+100;
typedef long long ll;
ll a[maxn];
bool used[maxn];
struct Node{
    int x,y;
    ll z;
    bool operator < (const Node & other)const{
        return other.z < z;
    }
};
priority_queue<Node> pq;
ll ans = 0;
int m,n;
int rk[maxn];
vector<pair<int,ll> > E[maxn];
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=m;i++) {
        int x, y;
        ll z;
        cin >> x >> y >> z;
        E[x].push_back({y, z});
        E[y].push_back({x, z});
    }
    for (int i=1;i<=n;i++){
        rk[i] =i;
    }
    sort(rk+1,rk+1+n,[](int x,int y){
        return a[x] < a[y];
    });
    int min_id = rk[1];
    used[min_id] = 1;
    for (auto pr : E[min_id]){
        pq.push({min_id,pr.first,pr.second});
    }
    int now_id = 2;
    for (int i=1;i<n;i++){
        while (!pq.empty() && used[pq.top().x] && used[pq.top().y])pq.pop();
        while (now_id <=n && used[rk[now_id]])now_id ++;
        assert(now_id <=n);
        if (pq.empty() || pq.top().z > a[rk[now_id]] + a[min_id]){
            used[rk[now_id]] = 1;
            ans += a[rk[now_id]] + a[min_id];
          //  cerr<<rk[now_id] <<"  "<<min_id<<" "<<a[rk[now_id]] + a[min_id]<<endl;

            assert(rk[now_id] <=n);
            for (auto pr : E[rk[now_id]]){
                pq.push({rk[now_id],pr.first,pr.second});
            }
        }else{
            auto pr = pq.top();pq.pop();
          //  cerr<<"@"<<pr.x<<" "<<pr.y<<" "<<pr.z<<endl;
            ans += pr.z;
            int tar = pr.x + pr.y - pr.x * used[pr.x] - pr.y * used[pr.y];
            used[pr.x] = used[pr.y] = 1;
            assert(tar <=n);
            for (auto p : E[tar]){
                pq.push({tar,p.first,p.second});
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}