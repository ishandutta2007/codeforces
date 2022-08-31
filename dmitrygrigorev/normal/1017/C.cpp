#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b;
    cin >> n;
    int S = 1e9;
    for (int i=1; i <= n; i++){
        int B = (n+i-1) / i;
        if (i+B < S){
            S = i+B;
            a = i, b = B;
        }

    }
    vector<int> ans(n);
    int st = 1;
    vector<pair<int, int> > blocks;
    for (int i=n-1; i >= 0; i-=a){
        int S = max((int) 0, i-a+1);
        int diff = i-S+1;
        for (int j=S; j <= i; j++){
            ans[j] = st + (j-S);
        }
        st += diff;
        blocks.push_back(make_pair(S, i));
    }
    reverse(blocks.begin(), blocks.end());
    b -= (n+a-1) / a;
    int u = 0;
    while (b > 0){
        int sz = blocks[u].second - blocks[u].first + 1;
        if (sz-1 <= b){
            b-=sz-1;
            vector<int> h;
            for (int j=blocks[u].first; j <= blocks[u].second; j++) h.push_back(ans[j]);
            reverse(h.begin(), h.end());
            for (int j=blocks[u].first; j <= blocks[u].second; j++) ans[j] = h[j - blocks[u].first];
        }
        else{
            vector<int> h;
            for (int j=blocks[u].second; j > blocks[u].second - b; j--) h.push_back(ans[j]);
            for (int j=blocks[u].first; j <= blocks[u].second - b; j++) h.push_back(ans[j]);
            for (int j=blocks[u].first; j <= blocks[u].second; j++) ans[j] = h[j - blocks[u].first];
            b = 0;
        }
        u++;
    }
    for (int i=0; i < n; i++) cout << ans[i] << " ";
    return 0;
}