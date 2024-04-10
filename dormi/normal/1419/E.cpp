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
        ll n;
        cin>>n;
        vector<ll> primefactors;
        set<ll> factors;
        for(ll i=2;i*i<=n;i++){
            if(n%i==0){
                factors.insert(i);
                factors.insert(n/i);
            }
        }
        factors.erase(n);
        ll ten=n;
        for(ll i=2;i*i<=n;i++){
            int cnt=0;
            while(n%i==0){
                n/=i;
                cnt++;
            }
            if(cnt)primefactors.push_back(i);
        }
        if(n>1)primefactors.push_back(n);
        int am=0;
        if(sz(factors)==2&&sz(primefactors)==2)am=1;
        for(int i=0;i<sz(primefactors)-1;i++){
            printf("%lli ",primefactors[i]);
            factors.erase(primefactors[i]);
            if(primefactors[i]*primefactors[i+1]!=ten)factors.erase(primefactors[i]*primefactors[i+1]);
            for(auto it=factors.begin();it!=factors.end();){
                if((*it)%primefactors[i]==0){
                    printf("%lli ",*it);
                    it++;
                    factors.erase(prev(it,1));
                }
                else it++;
            }
            if(primefactors[i]*primefactors[i+1]!=ten)printf("%lli ",primefactors[i]*primefactors[i+1]);
        }
        printf("%lli ",primefactors.back());
        factors.erase(primefactors.back());
        while(sz(factors)){
            printf("%lli ",*factors.begin());
            factors.erase(*factors.begin());
        }
        printf("%lli\n",ten);
        printf("%d\n",am);
    }
    return 0;
}