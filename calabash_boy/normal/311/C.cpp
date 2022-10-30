#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
typedef long long ll;
ll inf = 0x3f3f3f3f3f3f3f3fll;
//<value,-index>
priority_queue<pair<ll,ll> > nums;
map<ll,ll> value[maxn];
ll h;
ll m,n,k;
vector<ll> a;
ll dis[maxn];
ll c[maxn];
map<ll,ll> rid;
bool used[maxn];
void dijkstra(){
    fill(dis, dis + k +1 , inf);
    dis[1] = 1;
    memset(used,0,sizeof used);
    priority_queue<pair<ll,ll> > pq;
    for (ll i=0;i<k;i++){
        pq.push(make_pair(-dis[i],i));
    }
    while (!pq.empty()){
        ll dist,u;
        tie(dist,u) = pq.top();pq.pop();
        dist *= -1;
        if (used[u])continue;
        used[u] = 1;
        for (ll s : a){
            ll v = (u + s) % k;
            if (dis[v] > dist + s){
                dis[v] = dist + s;
                pq.push(make_pair(-dis[v],v));
            }
        }
    }
}
//#define DEBUG
void work(){
    while (!nums.empty())nums.pop();
    dijkstra();
#ifdef DEBUG
    for (int i=0;i<k;i++){
        cerr<<"dis["<<i<<"]="<<dis[i]<<endl;
    }
#endif
    for(ll i=0;i<k;i++){
        for (auto pr : value[i]){
            ll idx,val;
            tie(idx,val) = pr;
            if (idx >= dis[i]){
                nums.push(make_pair(val,-rid[idx]));
            }
        }
    }
    
}
int main(){
    cin>>h>>n>>m>>k;
    for (ll i=1;i<=n;i++){
        ll idx;
        ll val;
        cin>>idx>>val;
        rid[idx] = i;
        c[i] = idx;
        value[idx % k][idx] = val;
    }
    work();
    while (m--){
        int op;
        cin>>op;
        if (op == 1){
            ll x;
            cin>>x;
            a.push_back(x);
            work();
        }else if (op == 2){
            ll x,y;
            cin>>x>>y;
            ll idx = c[x];
            assert(value[idx%k].find(idx) != value[idx%k].end());
            value[idx % k][idx] -= y;
        }else if (op == 3){
            while (1){
                ll val,idx;
                if (nums.empty()){
                    cout<<0<<endl;
                    break;
                }
                tie(val,idx) = nums.top();
                nums.pop();
                idx *= -1;
                idx = c[idx];
                if (value[idx%k].find(idx) == value[idx%k].end())continue;
                if (val != value[idx%k][idx]){
                    nums.push(make_pair(value[idx%k][idx],-rid[idx]));
                }else{
                    cout<<val<<endl;
                    value[idx%k].erase(idx);
                    break;
                }
            }
        }
    }
    return 0;
}