#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    printf("%d\n",(n-1)/2);
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    vector<int> pr(n);
    for(int i=0;i<n;i+=2){
        pr[i]=arr.back();
        arr.pop_back();
    }
    for(int i=1;i<n;i+=2){
        pr[i]=arr.back();
        arr.pop_back();
    }
    for(auto x:pr)printf("%d ",x);
    return 0;
}