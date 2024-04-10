#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> Pair;

long long DP[100][10];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug", "r", stdin);
    #endif // ONLINE_JUDGE

    long long s, x;
    cin >> s >> x;
    x *= 2; s *= 2;

    DP[0][0] = 1;

    for(int i=1; i<=61; i++) {
        for(int ba=0; ba<=1; ba++) {
        for(int bb=0; bb<=1; bb++) {
        for(int t=0; t<=1; t++) {
            if((ba ^ bb) != ((x >> i) % 2))
                continue;
            if((ba ^ bb ^ t) != ((s >> i) % 2))
                continue;

            DP[i][ba + bb + t] += DP[i-1][2*t] + DP[i-1][2*t+1];
        }}}
    }

    if(s == x) DP[61][0] -= 2;
    cout << DP[61][0];
    return 0;
}