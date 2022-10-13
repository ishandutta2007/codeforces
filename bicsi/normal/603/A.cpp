#include <bits/stdc++.h>

using namespace std;

char str[500000];
int DP[500000][4][4];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE

    int n;
    cin>>n;

    cin>>str + 1;
    str[0] = 5;



    int best = 1;

    for(int i=1; i<=n; i++) {
        for(int nw=0; nw<2; nw++) {
            for(int fl=0; fl<3; fl++) {
                int b = str[i];
                b -= '0';
                if(fl == 1) b ^= 1;

                int add = 0;
                if(b == nw) add = 1;

                int nwx = nw;
                if(b == nw) nwx ^= 1;

                if(fl == 0) DP[i][nw][0] = DP[i-1][nwx][0] + add;
                if(fl == 1) DP[i][nw][1] = max(DP[i-1][nwx][0], DP[i-1][nwx][1]) + add;
                if(fl == 2) DP[i][nw][2] = max(DP[i-1][nwx][1], DP[i-1][nwx][2]) + add;

                best = max(best, DP[i][nw][fl]);
            }
        }
    }

    cout << best;

    return 0;
}