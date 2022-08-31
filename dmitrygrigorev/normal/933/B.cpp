#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int p, k;
    cin >> p >> k;
    vector<int> v;
    int D = 0;
    int i = 0;
    while (p != 0 || D != 0){
        int o = p%k;
        p /= k;
        o += D;
        D = 0;
        if (o >= k){
            o-=k;
            D++;
        }
        if (o == 0){
            v.push_back(o);
            i++;
            continue;
        }
        if (i % 2 != 0){
            int num = k - o;
            D++;
            v.push_back(num);
        }
        else v.push_back(o);
        i++;
    }
    cout << v.size() << endl;
    for (int i=0; i < v.size(); i++) cout << v[i] << " ";
}