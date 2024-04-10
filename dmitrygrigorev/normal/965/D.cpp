#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    int l, w;
    cin >> w >> l;
    w--;
    vector<int> stones(w);
    for (int i=0; i < w; i++) cin >> stones[i];
    stones.push_back(1e12);
    int u = 0;
    vector<int> frogs(w+1);
    fill(frogs.begin(), frogs.end(), 0);
    for (int i=0; i < l; i++) frogs[i] = stones[i];
    for (int i=l; i <= w; i++){
        while (u+l < i) u++;
        while (u < i){
            if (stones[i] >= frogs[u]){
                frogs[i] += frogs[u];
                stones[i] -= frogs[u];
                u++;
            }
            else{
                frogs[i] += stones[i];
                frogs[u] -= stones[i];
                break;
            }
        }
    }
    cout << frogs.back();
}