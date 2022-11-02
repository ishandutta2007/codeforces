#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN=200000;
constexpr int MAXFACT=MAXN*2+5;
constexpr int MOD=998244353;
pair<int,int> arr[MAXN];
struct fenwick {
    constexpr static int FWSIZE=MAXN+5;
    int arr[FWSIZE];
    int query(int index)const{
        int ans=0;
        for(;index>0;index-=index&-index){
            ans+=arr[index];
        }
        return ans;
    }
    void update(int index, int inc){
        for(;index<FWSIZE;index+=index&-index){
            arr[index]+=inc;
        }
    }
} fw;
template <typename Callback>
int bsta(int low, int high, Callback cb){
    while(low+1<high){
        int mid=(low+high)/2;
        if(cb(mid)){
            low=mid;
        }
        else{
            high=mid;
        }
    }
    return high;
}
int facts[MAXFACT],invfacts[MAXFACT];
int powmod(int base, int e){
    if(e==0)return 1;
    int tmp=powmod(base,e/2);
    tmp*=tmp;
    tmp%=MOD;
    if(e&1){
        tmp*=base;
        tmp%=MOD;
    }
    return tmp;
}
int combin(int n, int a, int b){
    return (((facts[n]*invfacts[a])%MOD)*invfacts[b])%MOD;
}
int cache[MAXN];
int32_t main(){
    ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    //cout.tie(nullptr);
    {
        int cum=1;
        facts[0]=invfacts[0]=cum;
        for(int i=1;i<MAXFACT;++i){
            cum*=i;
            cum%=MOD;
            facts[i]=cum;
            invfacts[i]=powmod(facts[i],MOD-2);
        }
    }
    int t;
    cin>>t;
    for(int c=0;c<t;++c){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<m;++i){
            cin>>arr[i].first>>arr[i].second;
        }
        int splits=0;
        int* cache_end=cache;
        for(int i=m-1;i>=0;--i){
            const int target=arr[i].second;
            int realidx=bsta(0,n,[&](int test){
                return test-fw.query(test)<target;
            });
            if(fw.query(realidx+1)==fw.query(realidx)){
                ++splits;
            }
            fw.update(realidx,1);
            *cache_end++=realidx;
        }
        int tmp=n-1-splits;
        cout<<combin(n+tmp,n,tmp)<<'\n';
        while(cache_end!=cache){
            --cache_end;
            fw.update(*cache_end,-1);
        }
    }
}