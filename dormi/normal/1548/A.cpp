#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
int indeg[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,a,b;
    cin>>n>>m;
    int am=n;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        if(a>b)swap(a,b);
        if(indeg[a]==0)am--;
        indeg[a]++;
    }
    int q;
    cin>>q;
    while(q--){
        cin>>a;
        if(a==1){
            cin>>a>>b;
            if(a>b)swap(a,b);
            if(indeg[a]==0)am--;
            indeg[a]++;
        }
        else if(a==2){
            cin>>a>>b;
            if(a>b)swap(a,b);
            indeg[a]--;
            if(indeg[a]==0)am++;
        }
        else printf("%d\n",am);
    }
    return 0;
}