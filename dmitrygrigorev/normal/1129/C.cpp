#include <bits/stdc++.h>
#define ll long long
ll MOD = 1000000007;
using namespace std;
struct Vertex{int a[2]; int tm; int g; ll dp; int par;};
Vertex bor[4600000];
int I = 0;
void create(){
    Vertex kek;
    kek.a[0] = -1, kek.a[1] = -1;
    kek.tm = -1, kek.g = -1, kek.par=-1, kek.dp=0;
    bor[I] = kek;
    I++;
}
int add(int vertex, int wh, int tm){
    //cout << vertex << "!" << endl;
    if (bor[vertex].a[wh] == -1){
        create();
        bor[vertex].a[wh] = I-1;
        bor[I-1].tm = tm;
        bor[I-1].g = wh;
        bor[I-1].par = vertex;
    }
    return bor[vertex].a[wh];
}
vector<ll> ans;
int bad[4] = {12, 10, 7, 15};
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string t;
    create();
    for (int i=0; i < n; i++){
        char num;
        cin >> num;
        t += num;
        int cur=0;
        for (int j=i; j >= 0; j--){
            cur = add(cur, t[j] - '0', i);
            //cout << cur << endl;
        }
    }
    ans.resize(n, 0);
    bor[0].dp = 1;
    for (int i=1; i < I; i++){
        int p =0;
        int cur = 0;
        int W = i;
        while (cur < 4){
            //cout << i << " " << W << endl;
            if (cur) bor[i].dp += bor[W].dp;
            if (bor[W].g==-1) break;
            p += bor[W].g * (1<<cur);
            cur++, W = bor[W].par;
        }
        if (cur==4){
            if (p!=bad[0] && p != bad[1] && p != bad[2] && p != bad[3]){
                bor[i].dp += bor[W].dp;
            }
        }
        //cout << i << " " << bor[i].dp << " " << bor[i].tm << endl;
        bor[i].dp %= MOD;
        ans[bor[i].tm] += (bor[i].dp);
        //bo
    }
    ll F=0;
    for (int i=0; i < n; i++){
        F += ans[i];
        cout << F%MOD << "\n";
    }


}