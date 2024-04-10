#include <bits/stdc++.h>
#define int ll
using namespace std;
typedef long long ll;
const int maxn = 16 * 5005;
int k;
map<ll,pair<int,int> > ID;
bool vis[maxn];
bool in[maxn];
stack<int> stk;
int num[maxn];
ll sum[20];
ll tot;
int nxt[maxn];
vector<int> circle[1 << 16];
bool dp[1 << 16];
void dfs(int u){
    vis[u] = 1;
    in[u] = 1;
    stk.push(u);
    int v = nxt[u];
    if (v == -1){
        in[u] = false;
        stk.pop();
        return;
    }
    if (in[v]){
        int mask = 0;
        vector<int> vec(0);
        while (1){
            int x = stk.top();
            stk.pop();
            in[x] = false;
            vec.push_back(x);
            int id = ID[num[x]].first;
            if (mask & (1<< (id-1)))throw 1ll;
            mask |= (1 << (id-1));
            if (x == v)break;
        }
        circle[mask] = vec;
        throw 1ll;
    }else if (!vis[v]){
        dfs(v);
    }
    stk.pop();
    in[u] = false;
}
pair<int,int> ans[20];
signed main(){
    cin>>k;
    for (int i = 1;i<=k;i++){
        int n;
        cin>>n;
        while (n--){
            int x;
            cin>>x;
            sum[i] += x;
            int sz = ID.size();
            ID[x] = make_pair(i,sz);
            num[sz] = x;
            ans[i] = make_pair(x,i);
        }
        tot += sum[i];
    }
    if (abs(tot) % k ){
        return puts("No"),0;
    }
    ll need = tot / k;
    for (int i=0;i < ID.size();i++){
        int u = num[i];
        int id = ID[u].first;
        ll v = need - sum[id] + u;
        if (ID.find(v) != ID.end() and ID[v].first != id){
            nxt[i] = ID[v].second;
        }else{
            nxt[i] = -1;
        }
    }
    for (int i=0;i<ID.size();i++){
        if (!vis[i]){
            while (!stk.empty()){
                int x = stk.top();
                in[x] = false;
                stk.pop();
            }
            try{
                dfs(i);
            }catch (ll x){

            }
        }
    }
    dp[0] = true;
    for (int mask = 0;mask < (1<<k);mask++){
        for (int submask = mask;submask != 0;submask = mask & (submask-1)){
            if (circle[submask].size() || __builtin_popcount(submask) == 1 and sum[ 1 + __builtin_ctz(submask)] == need){
                dp[mask] |= dp[mask ^ submask];
            }
        }
    }
    if (!dp[(1 << k) - 1]){
        return puts("No"),0;
    }

    int now = (1 << k) - 1;
    while (now){
        for (int submask = now;submask !=0; submask = now & (submask - 1)){
            if ((circle[submask].size() or __builtin_popcount(submask) == 1 and sum[ 1 + __builtin_ctz(submask)] == need )and dp[now ^ submask]){
                now ^= submask;
                assert(submask < (1<<15));
                assert(submask > 0);
                if (circle[submask].empty())break;
                const vector<int>& temp = circle[submask];
               // reverse(temp.begin(),temp.end());
                for (int i = 0;i < temp.size();i ++){
                    ans[ID[num[temp[i]]].first] = make_pair(num[temp[i]],ID[num[temp[(i+1)%temp.size()]]].first);
                }
                break;
            }
        }
    }
    puts("Yes");
    for (int i=1;i<=k;i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    return 0;
}