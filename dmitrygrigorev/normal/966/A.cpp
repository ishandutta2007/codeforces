#include <bits/stdc++.h>
#define int long long
using namespace std;
int bp(vector<int> &v, int num){
    int L = -1, R = v.size();
    while (R-L>1){
        int M = (L+R)/2;
        if (v[M] <= num) L = M;
        else R = M;
    }
    return L;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, lift, ladders, speed;
    cin >> n >> m >> ladders >> lift >> speed;
    vector<int> b(lift), a(ladders);
    for (int i=0; i < ladders; i++) cin >> a[i];
    for (int i=0; i < lift; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int q;
    cin >> q;
    for (int i=0; i < q; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int res = 1e18;
        int dst = abs(x1 - x2);
        int ost = dst / speed + (dst % speed != 0);
        if (x1==x2){
            cout << abs(y1-y2) << endl;
        }
        else{
            int ind = bp(a, y1);
            if (ind != -1) res = min(res, abs(y1 - a[ind]) + dst + abs(y2-a[ind]));
            ind++;
            if (ind != a.size()) res = min(res, abs(y1 - a[ind]) + dst + abs(y2-a[ind]));
            ind = bp(b, y1);
            if (ind != -1) res = min(res, abs(y1 - b[ind]) + ost + abs(y2-b[ind]));
            ind++;
            if (ind != b.size()) res = min(res, abs(y1 - b[ind]) + ost + abs(y2-b[ind]));
            cout << res << endl;
        }
    }
}