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
        string a;
        cin>>a;
        char largest='1';
        for(auto x:a){
            largest=max(largest,x);
        }
        printf("%d\n",largest-'0');
    }
    return 0;
}