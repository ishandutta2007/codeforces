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
        vector<int> vals;
        int a;
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>a;
            sum+=a;
            vals.push_back(a);
        }
        sort(vals.begin(),vals.end());
        if(sum==0){
            printf("NO\n");
        }
        else{
            printf("YES\n");
            if(sum>0)reverse(vals.begin(),vals.end());
            for(auto x:vals)printf("%d ",x);
            printf("\n");
        }
    }
    return 0;
}