#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005

int n, q;
int arr[MAXN];
int down[MAXN][20];
vector<int> primes[MAXN];

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i<=n; i++) cin >> arr[i];
    for(int i = 0; i<MAXN; i++) primes[i].push_back(0);
    for(int i = 1; i<=n; i++){
        down[i][0] = down[i-1][0];
        for(int j = 2, end = sqrt(arr[i])+5; j <= end; j++){
            if(arr[i]%j != 0) continue;
            down[i][0] = max(down[i][0], primes[j].back());
            primes[j].push_back(i);
            while(arr[i]%j == 0) arr[i]/=j;
        }
        if(arr[i] != 1){
            down[i][0] = max(down[i][0], primes[arr[i]].back());
            primes[arr[i]].push_back(i);
            arr[i] = 1;
        }
        for(int j = 1; j<20; j++) down[i][j] = down[down[i][j-1]][j-1];
    }
    while(q--){
        int l, r; cin >> l >> r;
        int ans = 0;
        for(int i = 19; i>=0; i--) if(down[r][i] >= l) ans += (1<<i), r = down[r][i];
        cout << ans+1 << endl;
    }
}