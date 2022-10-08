#include <stdio.h>
#include <vector>
using namespace std;
int d[105];
vector <int> ans[105];
int main() {
    int mx = 0, mn = 101, i, j, N, K;
    scanf("%d %d", &N, &K);
    for(i = 1; i <= N; i++) {
        scanf("%d", &d[i]);
        if(d[i] > mx) mx = d[i];
        if(d[i] < mn) mn = d[i];
    }
    if(mx-mn > K) {
        printf("NO");
        return 0;
    }
    for(i = 1; i <= N; i++) {
        for(j = mn+2; j <= d[i]; j++) ans[i].push_back(j-mn-1);
        for(j = 1; j <= mn; j++) ans[i].push_back(K);
        if(d[i] != mn) ans[i].push_back(K);
    }
    printf("YES\n");
    for(i = 1; i <= N; i++) {
        for(j = 0; j < ans[i].size(); j++) printf("%d ", ans[i][j]);
        printf("\n");
    }
    return 0;
}