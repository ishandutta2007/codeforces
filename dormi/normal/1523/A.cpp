#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e3+1;
int ldist[MN],rdist[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string a;
        cin>>a;
        int last=-2e9;
        for(int i=0;i<n;i++){
            if(a[i]=='1')last=i;
            ldist[i]=i-last;
        }
        last=2e9;
        for(int i=n-1;i>=0;i--){
            if(a[i]=='1')last=i;
            rdist[i]=last-i;
        }
        for(int i=0;i<n;i++){
            if(min(ldist[i],rdist[i])<=m&&(ldist[i]!=rdist[i]||ldist[i]==0))printf("1");
            else printf("0");
        }
        printf("\n");
    }
    return 0;
}