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
        ll p,f;
        ll sword,axe;
        cin>>p>>f>>sword>>axe;
        ll sw,aw;
        cin>>sw>>aw;
        if(sw>aw)swap(sw,aw),swap(sword,axe);
        ll ma=0;
        for(ll i=0;i<=sword;i++){
            if(p-i*sw<0)break;
            ll axecnt=min(axe,(p-i*sw)/aw);
            ll te=axecnt+i;
            ll leftaxes=axe-axecnt,leftswords=sword-i;
            ll swordcnt=min(leftswords,f/sw);
            axecnt=min(leftaxes,(f-swordcnt*sw)/aw);
            ma=max(ma,te+swordcnt+axecnt);
        }
        printf("%lli\n",ma);
    }
    return 0;
}