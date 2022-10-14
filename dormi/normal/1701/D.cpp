#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=5e5+1;
int ans[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,a;
        cin>>n;
        vector<pair<pii,int>> ranges;
        for(int i=1;i<=n;i++){
            cin>>a;
            if(a==0)ranges.push_back({{i+1,n},i});
            else ranges.push_back({{(i/(a+1))+1,i/a},i});
        }
        sort(ranges.begin(),ranges.end());
        priority_queue<pii,vector<pii>,greater<>> q;
        for(int i=1,ptr=0;i<=n;i++){
            while(ptr<sz(ranges)&&ranges[ptr].first.first<=i){
                q.push({ranges[ptr].first.second,ranges[ptr].second});
                ptr++;
            }
            ans[q.top().second]=i;
            q.pop();
        }
        for(int i=1;i<=n;i++)printf("%d%c",ans[i]," \n"[i==n]);
    }
    return 0;
}