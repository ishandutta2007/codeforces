#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
multiset<ll> paths[101];
vector<ll> ans[101];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        ll a;
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>> q;
        for(int i=0;i<n;i++){
            paths[i]=multiset<ll>();
            ans[i]=vector<ll>();
            for(int j=0;j<m;j++){
                cin>>a;
                paths[i].insert(a);
                q.push({a,i});
            }
        }
        while(sz(q)){
            auto cur=q.top();
            q.pop();
            if(paths[cur.second].count(cur.first)){
                paths[cur.second].erase(paths[cur.second].find(cur.first));
                ans[cur.second].push_back(cur.first);
                for(int i=0;i<n;i++){
                    if(i!=cur.second){
                        ans[i].push_back(*paths[i].rbegin());
                        paths[i].erase(paths[i].find(*paths[i].rbegin()));
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(auto x:ans[i])printf("%lli ",x);
            printf("\n");
        }
    }
    return 0;
}