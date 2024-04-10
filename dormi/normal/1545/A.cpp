#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
vector<int> arr[2];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,a;
        cin>>n;
        arr[0]=vector<int>(),arr[1]=vector<int>();
        for(int i=0;i<n;i++){
            cin>>a;
            arr[i%2].push_back(a);
        }
        sort(arr[0].begin(),arr[0].end()),sort(arr[1].begin(),arr[1].end());
        vector<int> finarr;
        for(int i=0;i<n;i++)finarr.push_back(arr[i%2][i/2]);
        if(is_sorted(finarr.begin(),finarr.end()))printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}