#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<complex>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
#define PI 3.1415926535897932384626433832795028
typedef long long Int;
typedef pair<Int, Int> P;
typedef long double Real;
typedef complex<Real> CP;

Int n, k;
Int c;
map<Int, int> cnt;
int main(){
    scanf("%lld%lld", &n, &k);
    for(int i = 0;i < n;i++){
        scanf("%lld", &c);
        cnt[c]++;
    }
    int kk = k;
    while(kk){
        auto rich = cnt.rbegin();        
        Int move = min(kk, rich->second);
        auto second_rich = next(rich);
        Int nxt = second_rich == cnt.rend()?-LINF:(second_rich->first);
        if(nxt != -LINF && move * (rich->first - nxt) <= kk){
            rich->second -= move;
            second_rich->second += move;
            kk -= move * (rich->first - nxt);
        }
        else{
            Int nxt1 = rich->first - kk/move;
            Int nxt2 = nxt1-1;
            Int cnt2 = kk % move;
            Int cnt1 = move - cnt2;
            cnt[nxt1] += cnt1;
            if(cnt2)cnt[nxt2] += cnt2;
            rich->second -= move;
            kk = 0;
        }
        if(rich->second == 0)cnt.erase(prev(cnt.end()));        
    }
    kk = k;
    while(kk){
//        for(auto p:cnt)cout << p.first << " " << p.second << endl;
        auto poor = cnt.begin();        
        Int move = min(kk, poor->second);
        auto second_poor = next(poor);
        Int nxt = second_poor == cnt.end()?LINF:(second_poor->first);
        if(nxt != LINF && move * (nxt - poor->first) <= kk){
            poor->second -= move;
            second_poor->second += move;
            kk -= move * (nxt - poor->first);
        }
        else{
            Int nxt1 = poor->first + kk/move;
            Int nxt2 = nxt1+1;
            Int cnt2 = kk % move;
            Int cnt1 = move - cnt2;
            cnt[nxt1] += cnt1;
            if(cnt2)cnt[nxt2] += cnt2;
            poor->second -= move;
            kk = 0;
        }
        if(poor->second == 0)cnt.erase(poor);        
    }

    cout << cnt.rbegin()->first - cnt.begin()->first << endl;
    
    return 0;
}