#include<bits/stdc++.h>
#define int ll
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 100;
int a[maxn];
int n,k;
map<int,int> cnt;
signed main(){
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]] ++;
        if (cnt[a[i]] >= k){
            cout<<0<<endl;
            return 0;
        }
    }
    sort(a+1,a+1+n);
    map<int,ll> ans1,ans2;
    int tot = 0;
    ll sum = 0;
    for (auto pr : cnt){
        tot += pr.second;
        sum += 1ll * pr.first * pr.second;
        ans1[pr.first] += 1ll * tot * pr.first - sum;
    }
    tot =0; sum = 0;
    for (auto it = cnt.rbegin();it != cnt.rend();it ++){
        tot += it->second;
        sum += 1ll * it->first * it->second;
        ans2[it->first] += sum - 1ll * tot * it->first;
    }
    ll ANS = LLONG_MAX;
    tot = 0;
    for (auto pr : cnt){
        tot += pr.second;
        ll tmp = ans1[pr.first];
        int need = k - tot;
        if (need > 0){
            auto it = ans2.lower_bound(pr.first);
            it = next(it);
            tmp += it->second;
            tmp += (n - tot) * (it->first - pr.first - 1);
            tmp += need;
        }
        if (tot >k and tot - pr.second < k){
            auto it = ans1.lower_bound(pr.first);
            it = prev(it);
            tmp = it->second;
            tmp += (pr.first - it->first - 1) * (tot - pr.second);
            tmp += k - pr.second;
        }
        ANS = min(ANS,tmp);
    }
    tot = 0;
    for (auto itt = cnt.rbegin();itt != cnt.rend();itt ++){
        auto pr = *itt;
        tot += pr.second;
        ll tmp = ans2[pr.first];
        int need = k - tot;
        if (need > 0){
            auto it = ans1.lower_bound(pr.first);
            it = prev(it);
            tmp += it->second;
            tmp += (n - tot) * (pr.first - it->first - 1);
            tmp += need;
        }
        if (tot > k and tot - pr.second < k){
            auto it = ans2.lower_bound(pr.first);
            it = next(it);
            tmp = it->second;
            tmp += (it->first - pr.first - 1) * (tot - pr.second);
            tmp += k - pr.second;
        }
        ANS = min(ANS,tmp);
    }
    cout<<ANS<<endl;
    return 0;
}