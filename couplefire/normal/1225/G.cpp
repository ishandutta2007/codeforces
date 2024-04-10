#include <bits/stdc++.h>
using namespace std;
#define MAXN 16
#define MAXK 2005

int n, k;
bitset<MAXK> dp[1<<MAXN];
int arr[MAXN];
vector<pair<int, int>> brr;

void trace(int mask, int x){
    if(!mask) return;
    if(x*k < MAXK && dp[mask][x*k]){
        trace(mask, x*k);
        for(int i = 0; i<n; i++) brr[i].first++;
        return;
    }
    for(int i = 0; i<n; i++){
        if(mask&(1<<i)){
            if(x < arr[i]) continue;
            if(!dp[mask^(1<<i)][x-arr[i]]) continue;
            trace(mask^(1<<i), x-arr[i]);
            brr[i] = {0, arr[i]};
            break;
        }
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i<n; i++) cin >> arr[i];
    for(int i = 0, end = (1<<n); i < end; ++i) dp[i].reset();
    for(int i = 0; i<n; i++) dp[1<<i].set(arr[i]);
    dp[0].set(0);
    for(int m = 0, end = (1<<n); m<end; ++m){
        for(int i = (MAXK-1)/k*k; i>0; i -= k) if(dp[m].test(i)) dp[m].set(i/k);
        for(int i = 0; i<n; ++i){
            if(m&(1<<i)) continue;
            dp[m^(1<<i)] |= (dp[m]<<arr[i]);
        }
    }
    if(!(dp[(1<<n)-1][1])){
        cout << "NO" << endl;
        exit(0);
    }
    cout << "YES" << endl;
    brr.resize(n);
    trace((1<<n)-1, 1);
    while(!(brr.size() == 1)){
        auto it1 = max_element(brr.begin(), brr.end());
        pair<int, int> tmp = *it1;
        brr.erase(it1);
        auto it2 = max_element(brr.begin(), brr.end());
        cout << tmp.second << " " << (*it2).second << endl;
        tmp.second += (*it2).second;
        brr.erase(it2);
        while(tmp.second%k == 0) tmp.first--, tmp.second /= k;
        brr.push_back(tmp);
    }
}