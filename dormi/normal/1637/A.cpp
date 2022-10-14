#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e4+1;
int arr[MN];
int prefixmax[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            prefixmax[i] = max(arr[i], prefixmax[i - 1]);
        }
        int mi=INT_MAX;
        bool work=false;
        for (int i = n; i >= 2; i--) {
            mi=min(mi,arr[i]);
            if(prefixmax[i-1]>mi){
                work=true;
                break;
            }
        }
        if(work)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}