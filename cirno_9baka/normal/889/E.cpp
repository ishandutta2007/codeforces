#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n;
long long a[N],ans;
map<long long,long long> mp;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%lld",&a[i]);
    for(int i=2;i<=n;++i)
        a[i]=min(a[i-1],a[i]);
    for(int i=1;i<=n;++i){
        long long as=0;
        while(1){
            auto it=mp.lower_bound(a[i]);
            if(it==mp.end())
                break;
            pair<long long,long long> p=*it;
            mp.erase(it);
            long long z=p.first%a[i];
            mp[z]=max(mp[z],p.second+(p.first-z)*(i-1));
            as=max(as,p.second+(p.first-a[i])/a[i]*a[i]*(i-1));
        }
        mp[a[i]-1]=max(mp[a[i]-1],as);
    }
    for(auto it:mp)
        ans=max(ans,it.first*n+it.second);
    cout<<ans;
}