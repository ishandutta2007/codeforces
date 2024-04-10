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
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    vector<int> pr(n);
    for(int i=(n%2==1?0:1);i<n;i+=2){
        pr[i]=arr.back();
        arr.pop_back();
    }
    int cnt=0;
    for(int i=n%2;i<n;i+=2){
        pr[i]=arr.back();
        arr.pop_back();
        if(i+1<n&&i-1>=0){
            if(pr[i-1]>pr[i]&&pr[i+1]>pr[i])cnt++;
        }
    }
    printf("%d\n",cnt);
    for(auto x:pr)printf("%d ",x);
    return 0;
}