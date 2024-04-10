#include <bits/stdc++.h>

using namespace std;
//sorry mike :C
const int MAXN = 1505;

char s[MAXN];
int aye[256][MAXN];

int main() {
    int n,q;
    if (scanf("%d %s %d", &n, s, &q) < 3)
        return false;

    for (int l=0; l<n; l++) {
        map<char, int> cnt;
        for (int r=l; r<n; r++) {
            cnt[s[r]]++;
            for (char c = 'a'; c<='z'; c++) {
                int len = r - l + 1;
                int cur_cost = len - cnt[c];
                aye[c][cur_cost] = max(aye[c][cur_cost], len);
            }
        }
    }

    for (char c = 'a'; c<='z'; c++) {
        for (int i=1; i<MAXN; i++) {
            aye[c][i] = max(aye[c][i], aye[c][i-1]);
        }
    }

    while (q--) {
        int m;
        char c;
        cin>>m>>c;
        cout<<aye[c][m]<<endl;
    }
}