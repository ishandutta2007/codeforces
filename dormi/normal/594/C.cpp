#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
map<ll,vector<int>> xnodes,ynodes;
pll node[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    ll a,b,c,d;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c>>d;
        node[i]={a+c,b+d};
        xnodes[a+c].push_back(i);
        ynodes[b+d].push_back(i);
    }
    ll ans=LLONG_MAX;
    for(int front=0;front<=min(k,sz(xnodes));front++){
        for(int back=0;back<=min(k,sz(xnodes));back++){
            for(int top=0;top<=min(k,sz(ynodes));top++){
                for(int bot=0;bot<=min(k,sz(ynodes));bot++){
                    auto it=xnodes.begin();
                    set<int> torem;
                    bool work=true;
                    for(int i=0;i<front&&work;i++){
                        for(auto x:it->second){
                            torem.insert(x);
                            if(sz(torem)>k){
                                work=false;
                                break;
                            }
                        }
                        it++;
                    }
                    ll le;
                    if(work)le=it->first;
                    auto rit=xnodes.rbegin();
                    for(int i=0;i<back&&work;i++){
                        for(auto x:rit->second){
                            torem.insert(x);
                            if(sz(torem)>k){
                                work=false;
                                break;
                            }
                        }
                        rit++;
                    }
                    ll ri;
                    if(work)ri=rit->first;
                    it=ynodes.begin();
                    for(int i=0;i<top&&work;i++){
                        for(auto x:it->second){
                            torem.insert(x);
                            if(sz(torem)>k){
                                work=false;
                                break;
                            }
                        }
                        it++;
                    }
                    ll thetop;
                    if(work)thetop=it->first;
                    rit=ynodes.rbegin();
                    for(int i=0;i<bot&&work;i++){
                        for(auto x:rit->second){
                            torem.insert(x);
                            if(sz(torem)>k){
                                work=false;
                                break;
                            }
                        }
                        rit++;
                    }
                    ll thebot;
                    if(work)thebot=rit->first;
                    if(work){
                        ans=min(ans,max(1LL,(thebot-thetop+1)/2)*max(1LL,(ri-le+1)/2));
                    }
                }
            }
        }
    }
    printf("%lli\n",ans);
    return 0;
}