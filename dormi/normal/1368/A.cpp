#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        ll a,b,n;
        cin>>a>>b>>n;
        if(a<b)swap(a,b);
        int am=0;
        while(a<=n){
            am++;
            b+=a;
            swap(a,b);
        }
        printf("%d\n",am);
    }
    return 0;
}