#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n%2==1){
            printf("-1\n");
        }
        else{
            n/=2;
            int a=0,b=0,c=0;
            int p2=1;
            while(n>0){
                int bit=n%2;
                if(bit)a+=p2,b+=p2;
                n/=2;
                p2=p2*2;
            }
            printf("%d %d %d\n",a,b,c);
        }
    }
    return 0;
}