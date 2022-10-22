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
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

map<Int, Int> cnt;
Int cntcnt[440000];
Int cntmorethan[440000];
Int sumlessthan[440000];

int main(){
    Int n, a;
    cin >> n;
    for(Int i = 0;i < n;i++){
        cin >> a;
        cnt[a]++;
    }
    for(auto it: cnt){
        cntcnt[it.second]++;
    }
    for(Int i = 400000;i >= 0;i--){
        cntmorethan[i] = cntmorethan[i+1] + cntcnt[i];
    }
    for(Int i = 1;i <= 400000;i++){
        sumlessthan[i] = sumlessthan[i-1] + cntcnt[i] * i;
    }

    Int maxp, maxarea = -1;
    for(Int p = 1;p <= n;p++){
        Int valid = sumlessthan[p] + cntmorethan[p+1] * p;
        Int area = valid / p * p;
        if(area < p*p)continue;
        if(area > maxarea){
            maxp = p;
            maxarea = area;
        }
    }

    Int maxq = maxarea / maxp;
    vector<P> nums;
    vector<vector<Int>> ans(maxp, vector<Int>(maxq));
    for(auto it:cnt){
        int use = min(it.second, maxp);
        for(Int i = 0;i < use;i++)nums.push_back(P(use, it.first));
    }
    sort(nums.rbegin(), nums.rend());
    for(Int i = 0;i < maxarea;i++){
        ans[i % maxp][(i % maxp + (i / maxp))%maxq] = nums[i].second;;
    }

    cout << maxarea << endl;
    cout << maxp << " " << maxq << endl;
    for(Int i = 0;i < maxp;i++){
        for(Int j = 0;j < maxq;j++){
            cout << ans[i][j] << " " ;
        }cout << endl;
    }
    return 0;
}