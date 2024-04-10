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

Int n, k, x;
Int start[1100000];
Int last[1100000];
Int same[1100000];

int main(){
    cin >> n;
    for(Int i = 0;i < n;i++){
        cin >> k;
        vector<Int> nums;
        bool ng = true;
        for(Int i = 0;i < k;i++){
            cin >> x;
            nums.push_back(x);
            if(i == 0)continue;
            if(nums[i-1] < nums[i])ng = false;
        }
        if(ng){
            start[nums[0]]++;
            last[nums.back()]++;
        }
    }

    for(Int i = 1;i < 1100000;i++){
        start[i] += start[i-1];
    }
    Int ans = n * n;
    for(Int i = 0;i < 1100000;i++){
        if(last[i] * start[i] == 0)continue;
        //   cout << last[i] << " " << start[i] << " " << i << endl;
        ans -= last[i] * start[i];
    }
    cout << ans << endl;
    return 0;
}