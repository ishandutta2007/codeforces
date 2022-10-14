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
        int n,m;
        cin>>n>>m;
        for(int i=0,ai=0;i<n;i+=2,ai++){
            for(int j=0,aj=0;j<m;j+=2,aj++){
                if((ai+aj)%2)printf("1 0%c"," \n"[j+2>=m]);
                else printf("0 1%c"," \n"[j+2>=m]);
            }
            for(int j=0,aj=0;j<m;j+=2,aj++){
                if((ai+aj)%2)printf("0 1%c"," \n"[j+2>=m]);
                else printf("1 0%c"," \n"[j+2>=m]);
            }
        }
    }
    return 0;
}