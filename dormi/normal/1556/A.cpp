#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int SZ(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        if(a==b&&a==0){
            printf("0\n");
        }
        else if(a==b)printf("1\n");
        else if(abs(a-b)%2==0)printf("2\n");
        else printf("-1\n");
    }
    return 0;
}