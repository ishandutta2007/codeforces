#include <bits/stdc++.h>

using namespace std;
typedef int var;

int V[500005];
int64_t Sum[5005][5005];

#define INF 1e16

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE

    int n, k;
    cin>>n>>k;

    for(int i=1; i<=n; i++)
        cin>>V[i];
    sort(V+1, V+n+1);

    //A -> n/k+1, B -> n/k
    int A = n%k, B = k-A;

    for(int i=0; i<=A; i++) {
        for(int j=0; j<=B; j++) {
            if(i == 0 && j == 0) continue;
            Sum[i][j] = INF;

            int last = i * (n/k+1) + j * (n/k);
            if(i > 0) {
                int first = last - n/k;
                Sum[i][j] = min(Sum[i][j], Sum[i-1][j] + V[last] - V[first]);
            }
            if(j > 0) {
                int first = last - n/k + 1;
                Sum[i][j] = min(Sum[i][j], Sum[i][j-1] + V[last] - V[first]);
            }
        }
    }

    cout<<Sum[A][B];

    return 0;
}