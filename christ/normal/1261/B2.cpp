#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;
const int MN = 2e5+2;
vector<pii> q[MN];
pii arr[MN];
int og[MN];
int bit[MN];
int ans[MN];
void inc (int i){
    for (;i<MN;i+=i&-i)
        ++bit[i];
}
int query (int i) {
    int ret = 0;
    for(;i;i^=i&-i)
        ret += bit[i];
    return ret;
}
int main () {
    int n;
    scanf ("%d",&n);
    for (int i = 1; i <= n; i++) {
        scanf ("%d",&arr[i].first);
        og[i] = arr[i].first;
        arr[i].second = i;
    }
    sort(arr+1,arr+1+n,[](pii a, pii b){
        return a.first > b.first || (a.first == b.first && a.second < b.second);
    });
    int m,k,b;
    scanf ("%d",&m);
    for (int i = 0; i < m; i++) {
        scanf ("%d %d",&k,&b);
        q[k].emplace_back(b,i);
    } 
    for (int i = 1; i <= n; i++) {
        inc(arr[i].second);
        for (pii &p : q[i]) {
            int low = 1, high = n,mid,ret=-1;
            while (low <= high) {
                mid = low+high>>1;
                if (query(mid) >= p.first) high = mid-1, ret = mid;
                else low = mid+1;
            }
            ans[p.second] = og[ret];
        }
    }
    for (int i = 0; i < m; i++) printf ("%d\n",ans[i]);
    return 0;
}