#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005

int n, k;
vector<int> chains;
long long tot;
int num[2*MAXN];

bool check(int mid){
    memset(num, 0, sizeof num);
    num[0] = 1, num[1] = -1;
    int curlvl = 0;
    int cursum = 1;
    long long bruh = 0;
    int tmp = 1;
    for(int i = 0; i<n; i++){
        if(tmp == 0){
            cursum += num[++curlvl];
            while(cursum == 0 && curlvl < mid) cursum += num[++curlvl];
            tmp = cursum;
        }
        if(curlvl+1 > mid) return 0;
        if(chains[i]%2 == 1){
            num[curlvl+2]+=2;
            num[curlvl+chains[i]/2+2]-=2;
            bruh++;
            if(curlvl+2 > mid)continue;
            bruh += (min(mid, curlvl+chains[i]/2+1)-min(mid, curlvl+2)+1)*2;
        }
        else{
            num[curlvl+2]+=2;
            num[curlvl+chains[i]/2+2]--; num[curlvl+chains[i]/2+1]--;
            bruh++;
            if(curlvl+2 > mid) continue;
            bruh += min(mid, curlvl+chains[i]/2+1)+min(mid, curlvl+chains[i]/2)-min(mid, curlvl+2)*2+2;
        }
        if(bruh-2*i-1 >= k){
            // cout << bruh-2*i-1 << " " << i+1 << " " << mid << endl;
            return 1;
        }
        tmp--;
    }
    return 0;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    chains.resize(n);
    for(int i = 0; i<n; i++) cin >> chains[i], tot += chains[i];
    if(tot-2*n+1 < k){
        cout << -1 << endl;
        exit(0);
    }
    sort(chains.begin(), chains.end());
    reverse(chains.begin(), chains.end());
    int lo = 0, hi = 1e6;
    while(lo < hi){
        int mid = lo+(hi-lo)/2;
        if(check(mid)) hi = mid;
        else lo = mid+1;
    }
    // cout << check(2) << endl;
    cout << lo << endl;
}