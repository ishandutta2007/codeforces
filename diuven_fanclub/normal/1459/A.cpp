#include <bits/stdc++.h>

using namespace std;

char R[1005], B[1005];
int main() {
    int t;
    scanf("%d", &t);
    for (int _t = 0; _t < t; _t++) {
        int n, cntR = 0, cntB = 0;
        scanf("%d%s%s", &n, R, B);
        for (int i = 0; i < n; i++) {
            cntR += R[i] > B[i];
            cntB += B[i] > R[i];
        }
        if (cntR > cntB) printf("RED\n");
        else if (cntB > cntR) printf("BLUE\n");
        else printf("EQUAL\n");
    }
}