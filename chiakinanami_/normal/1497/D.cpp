#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
int n;
int tag[5002];
ll arr[5002];

ll DPNow[2][5002];
ll DPPrev[2][5002];
ll DP[2][5002];
ll DPNext[2][5002];
ll tarr[5002];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i=1; i<=n; i++){
            scanf("%d", &tag[i]);
        }
        for(int i=1; i<=n; i++){
            scanf("%lld", &arr[i]);
        }

        memset(DPNow, 0, sizeof(DPNow));
        memset(DPPrev, 0, sizeof(DPPrev));
        memset(DP, 0, sizeof(DP));
        memset(DPNext, 0, sizeof(DPNext));

        ll ans = 0;
        for(int i=2; i<=n; i++){
            memset(DPNow, 0, sizeof(DPNow));
            memset(DPNext, 0, sizeof(DPNext));
            memset(tarr, 0, sizeof(tarr));
            for(int j=1; j<i; j++){
                if(tag[i] == tag[j]) continue;
                tarr[j-1] = DPNow[1][j] = max(DP[0][j], DP[1][j]) + abs(arr[i] - arr[j]);
                ans = max(DPNow[1][j], ans);
                DPNext[1][i] = max(DPNext[1][i], DPNow[1][j]);
            }
            for(int j=i-1; j>=1; j--) tarr[j] = max(tarr[j], tarr[j+1]);
            for(int j=1; j<i; j++){
                if(tag[i] == tag[j]) continue;
                DPNow[0][j] = tarr[j] + abs(arr[i] - arr[j]);
                ans = max(ans, DPNow[0][j]);
                DPNext[0][j] = max(DPNext[0][j], DPNow[0][j]);
            }

//            for(int j=1; j<i; j++){
//                if(tag[i] != tag[j]) printf("%d %d: %lld %lld\n", i, j, DPNow[0][j], DPNow[1][j]);
//            }

            for(int i=1; i<=n; i++){
                DP[0][i] = max(DP[0][i], DPNext[0][i]);
                DP[1][i] = max(DP[1][i], DPNext[1][i]);
                DPPrev[0][i] = DPNow[0][i];
                DPPrev[1][i] = DPNow[1][i];
            }
        }
        printf("%lld\n", ans);
    }
}