#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
#include <numeric>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <queue>
#include <numeric>
#include <iomanip>
#define ll long long
using namespace std;
const int MAXN = 400005;
int n,m,arr[MAXN];
vector<int> has[MAXN];
int x[MAXN],y[MAXN],h[MAXN],ans[MAXN],L[MAXN],R[MAXN],cnt[MAXN];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 1; i <= m; i++){
        cin >> x[i] >> y[i]; x[i]--;
        has[x[i]].push_back(i);
    }
    for(int i = 0; i < MAXN; i++) h[i] = 1e9;
    int lis = 0;
    for(int i = 0; i < n; i++){
        int lb = -1;
        for(auto &idx : has[i]){
            lb = lower_bound(h,h+n,y[idx]) - h;
            ans[idx] += (lb + 1);
        }
        lb = lower_bound(h,h+n,arr[i]) - h;
        lis = max(lis,lb+1);
        L[i] = lb;
        h[lb] = arr[i];
    }
    for(int i = 0; i < MAXN; i++) h[i] = 1e9;
    for(int i=n-1;i>=0;i--){
        int lb = -1;
        for(auto &idx : has[i]){
            lb = lower_bound(h,h+n,-y[idx]) - h;
            ans[idx] += (lb + 1);
        }
        lb = lower_bound(h,h+n,-arr[i]) - h;
        R[i] = lb;
        h[lb] = -arr[i];
    }
    for(int i = 0; i < n; i++){
        if(L[i] + R[i] + 1 == lis){
            cnt[L[i]]++;
        }
    }
    for(int i = 1; i <= m; i++){
        int ret = lis;
        int idx = x[i];
        if(L[idx] + R[idx] + 1 == lis && cnt[L[idx]] == 1) ret--;
        ret = max(ret,ans[i] - 1);
        cout << ret << "\n";
    }
    
    
    return 0;
}