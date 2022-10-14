#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=3e5+1;
vector<vector<int>> arr[2];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int a;
    int cur=0;
    arr[cur].push_back({});
    for(int i=0;i<n;i++){
        cin>>a;
        arr[cur].back().push_back(a);
    }
    int x=0;
    ll inver=0;
    vector<vector<int>> next;
    for(int i=30;i>=0;i--){
        vector<ll> ans(2,0);
        arr[!cur]=vector<vector<int>>();
        for(const auto &x:arr[cur]){
            vector<ll> am(2,0);
            vector<vector<int>> te;
            te.resize(2,{});
            for(auto y:x) {
                int bit = (!!(y & (1 << i)));
                if (!bit)ans[0] += am[1];
                else ans[1] += am[0];
                am[bit]++;
                te[bit].push_back(y);
            }
            for(const auto& y:te){
                if(sz(y)){
                    arr[!cur].push_back(y);
                }
            }
        }
        if(ans[0]<=ans[1]){
            inver+=ans[0];
        }
        else inver+=ans[1],x+=(1<<i);
        cur=!cur;
    }
    printf("%lli %d\n",inver,x);
    return 0;
}