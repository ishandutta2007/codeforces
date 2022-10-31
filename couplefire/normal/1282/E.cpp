#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        set<pair<int, int>> edges;
        set<int> adj[n];
        set<int> tri[n];
        pair<pair<int, int>, int> ahh[n];
        for(int i = 0; i<n-2; i++){
            int a, b, c; cin >> a >> b >> c;
            --a; --b; --c;
            adj[a].insert(b);
            adj[a].insert(c);
            adj[b].insert(a);
            adj[b].insert(c);
            adj[c].insert(a);
            adj[c].insert(b);
            if(!edges.count({a, b})) edges.insert({a, b});
            else edges.erase({a, b});
            if(!edges.count({a, c})) edges.insert({a, c});
            else edges.erase({a, c});
            if(!edges.count({b, a})) edges.insert({b, a});
            else edges.erase({b, a});
            if(!edges.count({b, c})) edges.insert({b, c});
            else edges.erase({b, c});
            if(!edges.count({c, a})) edges.insert({c, a});
            else edges.erase({c, a});
            if(!edges.count({c, b})) edges.insert({c, b});
            else edges.erase({c, b});
            tri[a].insert(i);
            tri[b].insert(i);
            tri[c].insert(i);
            ahh[i] = {{a, b}, c};
        }
        vector<int> per;
        auto it = edges.begin();
        per.push_back((*it).first);
        while(!edges.empty()){
            per.push_back((*it).second);
            int a = (*it).first, b = (*it).second;
            edges.erase({a, b});
            edges.erase({b, a});
            it = edges.lower_bound({b, -100000000});
        }
        per.pop_back();
        for(auto i : per) cout << i+1 << " ";
        cout << endl;
        set<pair<int, int>> st;
        for(int i = 0; i<n; i++) st.insert({adj[i].size(), i});
        while(!st.empty()){
            auto pp = *st.begin();
            st.erase(st.begin());
            if(pp.first < 2) continue;
            cout << *tri[pp.second].begin()+1 << " ";
            int ii = *tri[pp.second].begin();
            tri[ahh[ii].first.first].erase(ii);
            tri[ahh[ii].first.second].erase(ii);
            tri[ahh[ii].second].erase(ii);
            for(auto i : adj[pp.second]){
                st.erase({adj[i].size(), i});
                adj[i].erase(pp.second);
                st.insert({adj[i].size(), i});
            }
            adj[pp.second].clear();
        }
        cout << endl;
    }
}