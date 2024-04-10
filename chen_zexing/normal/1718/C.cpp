#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[200005];
int is_prime(int x){
    for(int i=2;i*i<=x;i++)
        if(x%i==0)
            return 0;
    return 1;
}
unordered_map <int,long long> mp[200005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,q;
        cin>>n>>q;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        vector <int> v;
        for(int i=1;i<n;i++)
            if(n%i==0&&is_prime(n/i))
                v.push_back(i),mp[i].clear();
        multiset <long long,greater<long long>> s;
        for(auto t:v){
            for(int i=1;i<=n;i++) mp[t][i%t]+=a[i];
            for(int i=0;i<t;i++) s.insert(mp[t][i]*t);
        }
        printf("%lld\n",*s.begin());
        for(int i=1,x,y;i<=q;i++){
            scanf("%d%d",&x,&y);
            for(auto t:v) s.erase(s.find(mp[t][x%t]*t)),mp[t][x%t]-=a[x];
            a[x]=y;
            for(auto t:v) mp[t][x%t]+=a[x],s.insert(mp[t][x%t]*t);
            printf("%lld\n",*s.begin());
        }
    }
    return 0;
}