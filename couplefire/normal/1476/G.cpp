#include <bits/stdc++.h>
using namespace std;
#define BLOCK 2714
#define MAXN 100100

struct Query{
    int l, r, t, k, id;
    Query(){}
    Query(int _l, int _r, int _t, int _k, int _id): l(_l), r(_r), t(_t), k(_k), id(_id){}
    bool operator < (const Query &o) const{
        if(l/BLOCK != o.l/BLOCK) return l/BLOCK < o.l/BLOCK;
        if(r/BLOCK != o.r/BLOCK) return r/BLOCK < o.r/BLOCK;
        return t < o.t; 
    }
};

int n, q;
vector<Query> queries;
vector<array<int, 3>> updates; // pos, prev, next
int arr[MAXN], cnt[MAXN], ans[MAXN], order[MAXN];
array<int, 2> bound[MAXN];
int curl = 0, curr = -1, curt = -1;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 0; i<n; i++) cin >> arr[i];
    for(int i = 0; i<q; i++){
        int t; cin >> t;
        if(t == 1){
            int l, r, k; cin >> l >> r >> k; --l; --r;
            queries.push_back({l, r, (int)updates.size()-1, k, (int)queries.size()});
        }
        else{
            int p, x; cin >> p >> x; --p;
            updates.push_back({p, arr[p], x});
            arr[p] = x;
        }
    }
    for(int i = (int)updates.size()-1; i>=0; i--) arr[updates[i][0]] = updates[i][1];
    for(int i = 0; i<MAXN; i++) bound[i] = {0, -1};
    bound[0] = {0, MAXN-1};
    sort(queries.begin(), queries.end());
    auto add = [&](int x){
        int c = cnt[x];
        order[bound[c][0]]++;
        bound[c+1][1] = bound[c][0];
        bound[c][0]++;
        ++cnt[x];
    };
    auto del = [&](int x){
        int c = cnt[x];
        order[bound[c][1]]--;
        bound[c-1][0] = bound[c][1];
        bound[c][1]--;
        --cnt[x];
    };
    auto upd = [&](int id, int f){
        int p = updates[id][0];
        int x = updates[id][f];
        if(curl <= p && p <= curr) del(arr[p]), add(x);
        arr[p] = x;
    };
    for(auto qq : queries){
        while(curl > qq.l) add(arr[--curl]);
        while(curr < qq.r) add(arr[++curr]);
        while(curl < qq.l) del(arr[curl++]);
        while(curr > qq.r) del(arr[curr--]);
        while(curt < qq.t) upd(++curt, 2);
        while(curt > qq.t) upd(curt--, 1);
        int res = MAXN;
        for(int i = 0, j = 0, sum = 0; i<MAXN && order[i] > 0; i = bound[order[i]][1]+1){
            while(j < MAXN && order[j] > 0 && sum < qq.k){
                sum += bound[order[j]][1]-bound[order[j]][0]+1;
                j = bound[order[j]][1]+1;
            }
            if(sum >= qq.k) res = min(res, order[i]-order[j-1]);
            sum -= bound[order[i]][1]-bound[order[i]][0]+1;
        }
        if(res == MAXN) ans[qq.id] = -1;
        else ans[qq.id] = res;
    }
    for(int i = 0; i<queries.size(); i++) cout << ans[i] << endl; 
}