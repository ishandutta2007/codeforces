#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
int arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        set<int> todel;
        set<pii> ele;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            ele.insert({i,arr[i]});
            if(i>=2&&__gcd(arr[i],arr[i-1])==1)todel.insert(i);
        }
        if(__gcd(arr[1],arr[n])==1)todel.insert(1);
        vector<int> ans;
        int ind=1;
        while(sz(todel)){
            auto it=todel.upper_bound(ind);
            if(it==todel.end())it=todel.begin();
            int cur=*it;
            ans.push_back(cur);
            auto it2=ele.lower_bound({cur,arr[cur]});
            auto nit=next(it2,1);
            if(nit==ele.end())nit=ele.begin();
            todel.erase(it);
            todel.erase(nit->first);
            auto pit=ele.begin();
            if(it2==ele.begin())pit=prev(ele.end(),1);
            else pit=prev(it2,1);
            if(pit!=it2&&nit!=it2&&__gcd(pit->second,nit->second)==1)todel.insert(nit->first);
            if(nit==it2)ind=-1;
            else ind=nit->first;
            ele.erase(it2);
        }
        printf("%d ",sz(ans));
        for(auto x:ans)printf("%d ",x);
        printf("\n");
    }
    return 0;
}