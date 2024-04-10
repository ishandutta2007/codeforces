#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

int n;
int arr[16];
int dp[1<<15][16][16]; // mask, cnt, pos
int sum[1<<15];
vector<int> good;
array<int, 2> trans[1<<15][16][16];

void trace(int mask, int cnt, int pos){
    if(cnt == 0) return;
    int nmask = trans[mask][cnt][pos][0], npos = trans[mask][cnt][pos][1];
    int tmpmask = mask^nmask;
    for(int i = 0; i<n; i++){
        if(i == pos) continue;
        if(tmpmask&(1<<i)){
            int p1 = find(good.begin(), good.end(), i)-good.begin();
            int p2 = find(good.begin(), good.end(), pos)-good.begin();
            cout << p1+1 << " " << p2+1 << endl;
            good.erase(find(good.begin(), good.end(), i));
        }
    }
    trace(nmask, cnt-1, npos);
}

void solve(){
    good.clear();
    cin >> n;
    for(int i = 0; i<n; i++) cin >> arr[i], good.push_back(i);
    for(int mask = 0; mask < (1<<n); ++mask){
        sum[mask] = 0;
        for(int i = 0; i<n; i++) if(mask&(1<<i)) sum[mask] += arr[i];
    }
    for(int mask = 0; mask<(1<<n); ++mask){
        for(int cnt = 0, end = __builtin_popcount(mask); cnt<=end; ++cnt){
            for(int pos = 0; pos<n; ++pos) dp[mask][cnt][pos] = INF;
        }
    }
    dp[0][0][0] = 0;
    for(int mask = 0; mask<(1<<n); ++mask){
        for(int cnt = 0, end = __builtin_popcount(mask); cnt<=end; ++cnt){
            for(int pos = 0; pos<n; ++pos){
                if(dp[mask][cnt][pos] >= INF) continue;
                int rmask = mask^((1<<n)-1);
                for(int nmask = rmask; nmask; nmask=(nmask-1)&rmask){
                    if(sum[nmask] <= dp[mask][cnt][pos]) continue;
                    if((nmask >> pos) == 0) continue;
                    int npos = pos+__builtin_ctz(nmask >> pos);
                    if(sum[nmask] >= dp[mask|nmask][cnt+1][npos]) continue;
                    dp[mask|nmask][cnt+1][npos] = sum[nmask];
                    trans[mask|nmask][cnt+1][npos] = {mask, pos};
                }
            }
        }
    }
    for(int cnt = n; cnt>=0; cnt--){
        for(int i = 0; i<n; i++){
            if(dp[(1<<n)-1][cnt][i] >= INF) continue;
            cout << n-cnt << endl;
            trace((1<<n)-1, cnt, i);
            return;
        }
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}