#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    int q;
    cin >> q;
    int sdv[60];
    for (int i=0; i < 60; i++) sdv[i] = 0;
    vector<int> bord;
    for (int i=0; i < 60; i++) bord.push_back((1LL<<(i+1)) - 1);
    for (int i=0; i < q; i++){
        int tp;
        cin >> tp;
        if (tp == 1){
            int x, k;
            cin >> x >> k;
            for (int j=0; j < 60; j++){
                if (bord[j] >= x){
                    sdv[j] += k;
                    sdv[j] %= (1LL<<j);
                    break;
                }
            }
        }
        if (tp==2){
            int x, k;
            cin >> x >> k;
            for (int j=0; j < 60; j++){
                if (bord[j] >= x){
                    int cst = k%(1LL<<j);
                    for (int p=j; p < 60; p++){
                        sdv[p] += cst;
                        sdv[p] %= (1LL<<p);
                        cst *= 2;
                    }
                    break;
                }
            }
        }
        if (tp==3){
            int x;
            cin >> x;
            for (int j=0; j < 60; j++){
                if (bord[j] >= x){
                    int ind = (x + sdv[j]) % (1LL<<j) + 1;
                    if (ind < 0) ind += (1LL<<j);
                    if (j > 0) ind += bord[j-1];
                    for (int p=j; p >= 0; p--){
                        int nmb = (ind) % (1LL<<p);
                        nmb -= sdv[p];
                        nmb %= (1LL<<p);
                        if (nmb < 0) nmb += (1LL<<p);
                        nmb++;
                        if (p > 0) nmb += bord[p-1];
                        cout << nmb << " ";
                        ind /= 2;
                    }
                    cout << endl;
                    break;
                }
            }
        }
    }
    return 0;
}