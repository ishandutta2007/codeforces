#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
int solve(vector<int> nums){
    if(sz(nums)<=2)return 0;
    vector<int> am[33];
    for(auto x:nums){
        if(x==0)am[0].push_back(x);
        else am[__lg(x)+1].push_back(x);
    }
    int tot=0;
    for(int i=0;i<33;i++) {
        if (sz(am[i])) {
            tot+=sz(am[i])-1;
        }
    }
    int thingies=0;
    int ans=INT_MAX;
    vector<pii> poss;
    for(int i=0;i<33;i++){
        if(sz(am[i])){
            thingies++;
            if(sz(am[i])>1) {
                vector<int> te;
                for (auto x:am[i])te.push_back(x - (1 << (i - 1)));
                ans=min(ans,tot+max(0,thingies-2)-(sz(am[i])-1)+solve(te));
            }
            else{
                ans=min(ans,tot+max(0,thingies-2)-(sz(am[i])-1));
            }
        }
    }
    return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int a;
    vector<int> stff;
    for(int i=0;i<n;i++){
        cin>>a;
        stff.push_back(a);
    }
    printf("%d\n",solve(stff));
    return 0;
}