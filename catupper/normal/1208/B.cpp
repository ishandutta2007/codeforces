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

Int n, a[2160];
vector<Int> nums;
Int cnt[2160];
Int res = INF;

int main(){
    cin >> n;
    for(Int i = 0;i < n;i++){
        cin >> a[i];
        nums.push_back(a[i]);
    }
    sort(nums.begin(), nums.end());
    for(Int i = 0;i < n;i++)a[i] = lower_bound(nums.begin(), nums.end(), a[i]) - nums.begin();
    
    for(Int l = 0;l < n;l++){
        bool ok = true;
        fill(cnt, cnt + 2160, 0);
        for(Int j = 0;j < l;j++){
            cnt[a[j]]++;
            if(cnt[a[j]] > 1)ok = false;
        }
        if(!ok)break;
        for(Int j = n-1;j >= l;j--){
            cnt[a[j]]++;
            if(cnt[a[j]] > 1){
                res = min(res, j - l + 1);
                break;
            }
            if(j == l){
                res = min(res, j - l); 
            }
        }
    }
    cout << res << endl;
    return 0;
}