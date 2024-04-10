#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
int arr[51];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        set<int> base;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            for(int j=0;j<i;j++){
                base.insert(arr[i]-arr[j]);
            }
        }
        printf("%d\n",sz(base));
    }
    return 0;
}