#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = numeric_limits<int>::max();

struct Data{
    map<int, int> mp;
    multiset<int> mst;
    int lazy = 0;
    void add(int val){lazy += val;}
    int query(int key){return (mp.count(key)?mp[key]+lazy:INF);}
    void erase(int key){if(mp.count(key)) mst.erase(mst.find(mp[key])), mp.erase(key);}
    void upd(int key, int val){
        erase(key);
        mst.insert(val-lazy);
        mp[key] = val-lazy;
    }
    int getMin(){return (mst.size()?*mst.begin()+lazy:INF);}
};

int n, s;
vector<Data*> datas;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    datas.push_back(new Data());
    datas.back()->upd(0, 0);
    for(int _ = 0; _ < n; _++){
        string type; cin >> type;
        if(type == "set"){
            int y, v; cin >> y >> v;
            int mini = datas.back()->getMin();
            datas.back()->add(v);
            if(y != s && mini < INF) datas.back()->upd(y, mini);
        } else if(type == "if"){
            int y; cin >> y;
            Data* cur = new Data();
            if(y != s && datas.back()->query(y) < INF) 
                cur->upd(y, datas.back()->query(y)), datas.back()->erase(y);
            datas.push_back(cur);
        } else{
            Data* cur = datas.back(); datas.pop_back();
            if(cur->mp.size() > datas.back()->mp.size()) swap(cur, datas.back());
            for(auto [key, val] : cur->mp) 
                if(val+cur->lazy < datas.back()->query(key)) datas.back()->upd(key, val+cur->lazy);
        }
    }
    cout << datas.back()->getMin() << endl;
}