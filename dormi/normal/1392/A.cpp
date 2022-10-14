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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        set<int> nums;
        int a;
        for(int i=0;i<n;i++){
            cin>>a;
            nums.insert(a);
        }
        if(sz(nums)==1)printf("%d\n",n);
        else printf("1\n");
    }
    return 0;
}