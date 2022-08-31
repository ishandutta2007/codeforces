#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<pair<int, int> > pieces;
    int kek = 2;
    for (int i=0; i < 40; i++){
        pieces.push_back({kek, 2*kek-1});
        kek *= 2;
    }
    int q;
    cin >> q;
    for (int i=0; i < q; i++){
        int x;
        cin >> x;
        for (int j=0; j < pieces.size(); j++){
            if (pieces[j].second < x) continue;
            if (pieces[j].second > x){
                cout << pieces[j].second << "\n";
                break;
            }
            bool res = false;
            for (int e=2; e*e <= x; e++){
                if (x % e == 0){
                    cout << x/e << "\n";
                    res = true;
                    break;
                }
            }
            if (!res) cout << 1 << "\n";
            break;
        }
    }
}