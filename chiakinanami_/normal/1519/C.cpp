#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
int n;
vector<ll> vec[200002];
vector<ll> sum[200002];
ll ans[200002];

int a[200002], b[200002];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i=1; i<=n; i++) vec[i].clear(), ans[i] = 0;
        for(int i=1; i<=n; i++){
            scanf("%d", &a[i]);
        }
        for(int i=1; i<=n; i++){
            scanf("%d", &b[i]);
            vec[a[i]].push_back(b[i]);
        }

        for(int i=1; i<=n; i++){
            sum[i].clear();
            int s = (int)vec[i].size();
            sort(vec[i].rbegin(), vec[i].rend());
            for(int j=0; j<s; j++){
                sum[i].push_back((sum[i].empty() ? 0 : sum[i].back()) + vec[i][j]);
            }

            for(int j=1; j<=s; j++){
                ans[j] += sum[i][s/j*j-1];
            }
        }

        for(int i=1; i<=n; i++) printf("%lld ", ans[i]);
        puts("");
    }
}