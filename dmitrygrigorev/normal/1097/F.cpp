#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
using namespace std;
const int K = 7001;
bitset<K> kek[K];
bitset<K> mn[100000];
vector<vector<int> > del(K);
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i=K; i >= 1; i--){
        bitset<K> b;
        b[i] = 1;
        kek[i] = b;
        for (int j=i+i; j < K; j+=i){
            kek[i] ^= kek[j];
        }
    }
    for (int i=1; i < K; i++) for (int j=i; j < K; j+=i) del[j].push_back(i);
    int n, q;
    cin >> n >> q;
    for (int i=0; i < n; i++){
        bitset<K> b;
        mn[i] = b;
    }
    bitset<K> pl;
    string ans = "";
    for (int i=0; i < q; i++){
        int tp;
        cin >> tp;
        if (tp == 1){
            bitset<K> e;
            int a, b;
            cin >> a >> b;
            a--;
            for (int j=0; j < del[b].size(); j++){
                int num = del[b][j];
                e[num] = 1;
            }
            mn[a] = e;
        }
        if (tp == 2){
            int x, y, z;
            cin >> x >> y >> z;
            x--, y--, z--;
            pl = mn[y] ^ mn[z];
            mn[x] = pl;
        }
        if (tp==3){
            int x, y, z;
            cin >> x >> y >> z;
            x--, y--, z--;
            pl = mn[y] & mn[z];
            mn[x] = pl;
        }
        if (tp == 4){
            int a, b;
            cin >> a >> b;
            a--;
            pl = mn[a] & kek[b];
            ans += (char) ('0' + (pl.count()%2));
        }
    }
    cout << ans;
    return 0;
}