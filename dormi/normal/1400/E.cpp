#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
int solve(vector<int> a){
    if(sz(a)==0)return 0;
    int val=*min_element(a.begin(),a.end());
    vector<int> gocheck;
    int teans=val;
    for(auto x:a){
        if(x==val){
            teans+=solve(gocheck);
            gocheck=vector<int>();
        }
        else gocheck.push_back(x-val);
    }
    teans+=solve(gocheck);
    return min(sz(a),teans);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    printf("%d\n",solve(arr));
    return 0;
}