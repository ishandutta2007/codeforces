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
        ll s;
        string n;
        cin>>n>>s;
        ll needed=0;
        ll sum=0;
        for(int i=0;i<sz(n);i++){
            sum+=n[i]-'0';
        }
        ll ma=10;
        ll tesum=0;
        ll totsum=sum;
        for(int i=sz(n)-1;sum>s;i--){
            needed=ma-stoll(n.substr(i));
            tesum+=n[i]-'0';
            sum=totsum-tesum+1;
            ma*=ll(10);
        }
        printf("%lli\n",needed);
    }
    return 0;
}