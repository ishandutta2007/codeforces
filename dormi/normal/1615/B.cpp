#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=2e5;
const int bits=19;
int psa[bits][MN];
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int j = 0; j < bits; j++) {
        for (int i = 1; i <= 2e5; i++) {
            psa[j][i]=psa[j][i-1];
            if(!(i&(1<<j)))psa[j][i]++;
        }
    }
    while(t--){
        int l,r;
        cin>>l>>r;
        int mi=INT_MAX;
        for(int i=0;i<bits;i++){
            mi=min(mi,psa[i][r]-psa[i][l-1]);
        }
        printf("%d\n",mi);
    }
    return 0;
}