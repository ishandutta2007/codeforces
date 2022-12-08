#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
int n, k;
int arr[200002];
int DP[200002][21];
int pnt[200002][21];
vector<int> occ[200002];

void renumber(){
    vector<int> vec;
    for(int i=1; i<=n; i++) vec.push_back(arr[i]);
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    for(int i=1; i<=n; i++) arr[i] = lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();

    for(int i=0; i<=n; i++) occ[i].clear();
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        for(int i=1; i<=n; i++){
            scanf("%d", &arr[i]);
            for(int j=2; j*j<=arr[i]; j++){
                while(arr[i] % (j*j) == 0){
                    arr[i] /= j*j;
                }
            }
        }
        renumber();
        for(int i=0; i<=n; i++) occ[i].push_back(-1);

        for(int i=1; i<=n; i++){
            for(int j=0; j<=k; j++){
                DP[i][j] = 1e9;
                ///     
                pair<int, int> pr;
                if(pnt[i-1][j] <= occ[arr[i]].back()) pr = make_pair(DP[i-1][j]+1, -i);
                else pr = make_pair(DP[i-1][j], -pnt[i-1][j]);

                if(j){
                    pr = min(pr, make_pair(DP[i-1][j-1], -pnt[i-1][j-1]));
                }
                DP[i][j] = pr.first;
                pnt[i][j] = -pr.second;
            }
            occ[arr[i]].push_back(i);
        }

        int ans = INT_MAX;
        for(int j=0; j<=k; j++) ans = min(ans, DP[n][j]);

        printf("%d\n", ans+1);
    }
}