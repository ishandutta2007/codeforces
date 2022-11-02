#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

char c[105][105];

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) 
            scanf("%s", c[i] + 1);
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(c[i][m] == 'R') cnt++;
        }
        for(int i = 1; i <= m; i++) {
            if(c[n][i] == 'D') cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}