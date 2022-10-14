#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=100001;
ll x;
int n,d;
int a[MAXN],b[MAXN];
ll getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}
void initAB() {
    for(int i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(int i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>d>>x;
    initAB();
    if(ll(d)*ll(d)>=ll(n)){
        set<pii> nums;
        for(int i=0;i<n;i++){
            nums.insert({-a[i],i});
            bool done=false;
            for(auto x:nums)if(b[i-x.second]){
                printf("%d\n",-x.first);
                done=true;
                break;
            }
            if(!done)printf("0\n");
        }
    }
    else{
        vector<int> pos;
        for(int i=0;i<n;i++){
            int ans=0;
            if(b[i])pos.push_back(i);
            for(int j:pos)ans=max(ans,a[i-j]);
            printf("%d\n",ans);
        }
    }
    return 0;
}