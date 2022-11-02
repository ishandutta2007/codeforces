#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN=200000;
int arr[MAXN];
int delta[MAXN];
int do_gcd(int a, int b){
    if(b==0)return a;
    return do_gcd(b,a%b);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin>>tc;
    for(int ct=0;ct<tc;++ct){
        int n;
        cin>>n;
        cin>>arr[0];
        for(int i=1;i<n;++i){
            cin>>arr[i];
            delta[i-1]=abs(arr[i]-arr[i-1]);
        }
        int best=1;
        vector<pair<int,int>> ranges; // <startidx, val> (ordered from smallest startidx and val)
        for(int i=0;i<n-1;++i){
            int gcdarc=delta[i];
            for(auto it=ranges.rbegin();it!=ranges.rend();++it){
                gcdarc=it->second=do_gcd(it->second, gcdarc);
            }
            ranges.emplace_back(i, delta[i]);
            int past=1;
            ranges.erase(std::remove_if(ranges.begin(),ranges.end(),[&](const pair<int,int>& range){
                if(range.second==past)return true;
                past=range.second;
                return false;
            }),ranges.end());
            if(!ranges.empty())best=max(best,i+2-ranges.front().first);
        }
        cout<<best<<'\n';
    }
}